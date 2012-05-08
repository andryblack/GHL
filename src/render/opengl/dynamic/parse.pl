use strict;
use warnings;


sub demangle_func {
    my ($name) = @_;
    $name =~ /^gl([\w\d]+)/;
    return $1;
} 

sub demangle_constant {
    my ($name) = @_;
    $name =~ /^GL_([\w\d]+)/;
    return $1;
}

sub demangle_type {
    my ($name) = @_;
	my $result = {};
	if ($name =~ /const (\w\*)+\s*/ ) {
		$name = $1;
		$result->{'const'} = 'yes';
	} else {
		$result->{'const'} = 'no';
	}
	if ($name =~ /(\w+)+\s*\*\s*/) {
		$name = $1;
		$result->{'pointer'} = 'yes';
	} else {
		$result->{'pointer'} = 'no';
	}
    $name =~ /^GL([\w\d]+)\s*/;
	$result->{'type'} = $1;
    return $result;
}

sub mangle_type {
	my ($type,$prefix) = @_;
	my $result = "";
	if ($type->{'const'}) {
		if ($type->{'const'} eq 'yes') {
			$result = $result . 'const ';
		}
	}
	$result = $result . "$prefix$type->{'type'}";
	if ($type->{'pointer'}) {
		if ($type->{'pointer'} eq 'yes') {
			$result = $result . "*";
		}
	}
	return $result;
}

sub parse_args { 
    my ($args_string) = @_;
#    print "args : $args_string\n";
    my @pairs = split ( /,/,$args_string);
    my @args = ();
	my $def_name = 1;
    foreach my $arg_pair ( @pairs ) {
		$arg_pair=~s/^\s*//;
		$arg_pair=~s/\s*$//;
	#	print " str_pair : $arg_pair\n";
		my ($type,$name) = split ( / / , $arg_pair );
		my $const = "no";
		if ($type eq 'const' ) {
			($const,$type,$name) = split ( / / , $arg_pair );
			$const = "yes";
		}
		my $pointer = 'no';
		if ( ! $name ) {
			$name = "p$def_name";
			$def_name = $def_name + 1;
		}
		if ($name =~ /\s*\*\s*(\w*)/) {
			$pointer = 'yes';
			$name = $1;
		}
		if ( ! $name ) {
			$name = "p$def_name";
			$def_name = $def_name + 1;
		}
		$type =~ s/^GL//;
	#	print " pair : $type $name\n";
		$args[++$#args] = { type => $type, name => $name , const => $const, pointer => $pointer};
    }
    return @args;
}



my @extensions_developer = ("EXT" , "ARB" , "NV" , "ATI" , "SGIS", "IMG"  );

my @features = ();


sub parse_gl_h() {
    open ( my $in , "<" ,"gl.h" ) or die "Can't open file gl.h";
    my @lines = <$in>;
    my $feature = { name => "VERSION_1_1" , core => "yes" };
    my $skip="no";
    my $wait_endif = "no";
    my $collect_line = "no";
    my $line = "";
    foreach my $xline (  @lines ) {
		$xline =~ s/\n$//;
		$xline =~ s/\r$//;
        $xline =~ s/\s*$//;
        $xline =~ s/\s*\/\*.*\*\/$//;
        $xline =~ s/^\s*//;
        #print "parsed :'" . $line . "'\n";
        if ( $collect_line eq "yes" ) {
            $line = $line . $xline;
            if ( $xline =~ /;$/ ) {
                $collect_line = "no";
            }
        } else {
            $line = $xline;
            my $original_line = $xline;
            if (  $xline =~ /^[A-Z_]+API\s+[\s\*\w]+\s+[GL_]*APIENTRY\s+(\w+)\s*\(\s*/ && !($original_line =~ /;$/) ) {
                $collect_line = "yes";
            }
        }
        if ($collect_line eq "yes") {
            
        } elsif ($skip eq "yes") { 
            if ( $line =~ /^#endif/ ) {
                $skip = "no";
            }
        } else {
            #print $line . "\n";
            if ( $line =~ /^#ifndef GL_(\w+)/ ) {
                my $feature_name = $1;
                if ( $wait_endif eq "no" ) {
                    if ( ($feature_name ne "VERSION_1_1") and ($feature_name ne "VERSION_1_0") ) {
                        $skip = "yes";
                    } else {
                        $wait_endif = "yes";
                    }
                }
            } elsif ( $line =~ /^#if !defined\(__WIN32__\)/) {
                $skip = "yes";
            } elsif ( $line =~ /^typedef ([\w\s]+)\sGL(\w+)\s*;/ ) {
                my $type = $1;
                my $name = $2;
                $type =~ s/\s*$//; 
                push ( @{$feature->{'typedefs'}} , { 'name'=>$name,'type'=>$type } );
            } elsif ( $line =~ /^#define GL_([A-Z0-9_]+)\s+([0x]*[0-9A-F]+)/ ) {
                my $name = $1;
                if ( ! ( $name =~ /^VERSION_[0-9]_[0-9]/ ) ) { 
                    my $value = $2;
                    my $skip = "no";
                    foreach ( @extensions_developer ) {
                        if ( $name =~ /_$_$/ ) {
                            $skip = "yes";
                        }
                    }
                    if ( $skip eq "no" ) {
                        push ( @{$feature->{'constants'}} , { 'name' => $name, 'value' => $value} );
                    }
                }
            } elsif ( $line =~ /^[A-Z_]+API\s+([\s\*\w]+)\s+[GL_]*APIENTRY\s+(\w+)\s*\(\s*([\w\s,\*]*)\s*\)\s*;$/) {
                #print "/**$line**/\n";
                my $res = demangle_type($1);
                my $name = demangle_func($2);
                my $args = $3;
                $args =~ s/^\s*//;
                $args =~ s/\s*$//;
                #print "|$args|\n";
                $res =~ s/GL//;
                my $function = { 'name' => $name , 'rettype' => $res->{'type'} , 'retconst' => $res->{'const'} , 'retpointer' => $res->{'pointer'} };
                if ( ( ! $args ) || ( $args eq "void" ) ) {
                } else {
                    push ( @{$function->{'args'}} , parse_args($args) );
                }
                push ( @{$feature->{'functions'}} , $function );
                #print "/* gl$function->{'name'} */\n";
            } elsif ( $line =~ /^#endif/) {
                if ( $wait_endif eq "yes" ) {
                    $wait_endif = "no"
                }
            }
        }
    }
    $features[++$#features] = $feature;


}


sub parse_glext_h() {
    open ( my $in , "<" ,"glext.h" ) or die "Can't open file glext.h";
    my @lines = <$in>;
    my $feature_name;
	my $featurez = {};
	my $core = "no";
    foreach (  @lines ) {
		if ( /^#ifndef GL_(\w+)/) {
			$feature_name = $1;
			my $core = "no";
			if ( $1 =~ /^VERSION_[0-9]_[0-9]/ ) {
				$core = "yes";
			}
			$featurez->{$feature_name}->{'core'} = $core;
        } elsif ( /^typedef ([\w\s]+)\sGL(\w+)\s*;/ ) {
			my $type = $1;
			my $name = $2;
			$type =~ s/\s*$//; 
			push ( @{$featurez->{$feature_name}->{'typedefs'}} , { 'name'=>$name,'type'=>$type } );
		} elsif ( /^#define GL_([A-Z0-9_]+)\s+(0x[0-9A-F]+)/ ) {
			my $name = $1;
			my $value = $2;
			push ( @{$featurez->{$feature_name}->{'constants'}} , { 'name' => $name, 'value' => $value} );
		} elsif ( /^typedef\s+(\w+)\s+\(\s*[GL_]*APIENTRYP\s+PFNGL(\w+)PROC\s*\)\s*\(\s*([\w\s,\*]*)\s*\)\s*;/ ) {
			my $res = $1;
			my $name = $2;
			my $args = $3;
			$args =~ s/^\s*//;
			$args =~ s/\s*$//;
			$res =~ s/GL//;
			push ( @{$featurez->{$feature_name}->{'protos'}} , { 'name' => $name, 'res' => $res , 'args' => $args} );
		} elsif ( /^[A-Z_]+API\s+(\w+)\s+[GL_]*APIENTRY\s+(\w+)\s*\(\s*([\w\s,\*]*)\s*\);/ ) {
			my $res = demangle_type($1);
			my $name = demangle_func($2);
			my $args = $3;
			$args =~ s/^\s*//;
			$args =~ s/\s*$//;
			#print "|$args|\n";
			$res =~ s/GL//;
			my $function = { 'name' => $name , 'rettype' => $res->{'type'} , 'retconst' => $res->{'const'} , 'retpointer' => $res->{'pointer'} };
			if ( ( ! $args ) || ( $args eq "void" ) ) {
			} else {
				push ( @{$function->{'args'}} , parse_args($args));
			}
			push ( @{$featurez->{$feature_name}->{'functions'}} , $function );
			
		}
		
    }
	
	foreach my $key ( keys %{$featurez} ) {
		$featurez->{$key}->{'name'}=$key;
		#############
		# replase argument names from proto
		my @new_funcs = ();
		foreach my $func ( @{$featurez->{$key}->{'functions'}} ) {
			my $name = $func->{'name'};
			my $res = $func->{'rettype'};
			my $proto_name = uc ($name);
			my $function = { 'name' => $name , 'rettype' => $res , 'retconst' =>$func->{'retconst'}, 'retpointer' => $func->{'retpointer'} };
			my $found = "no";
			foreach my $proto ( @{$featurez->{$key}->{'protos'}} ) {
				if ( $proto->{'name'} eq $proto_name ) {
					my $args = $proto->{'args'};
					if ( ( ! $args ) || ( $args eq "void" ) ) {
					} else {
						push ( @{$function->{'args'}} , parse_args($args));
					}
					$found = "yes";
				}
			}
			if ( $found eq "yes" ) {
				push( @new_funcs , $function );
			} else {
				push( @new_funcs , $func );
			}
		}
		@{$featurez->{$key}->{'functions'}} = @new_funcs;
		###########################
		$features[++$#features] = $featurez->{$key};
	}
    #$features[++$#features] = $feature;


}

parse_gl_h();
parse_glext_h();

sub print_xml () {   
	print "<?xml version=\"1.0\" ?>\n";
	print "<features>\n";
	 
	foreach my $feature ( @features ) {
		print " <feature name=\"$feature->{'name'}\" core=\"$feature->{'core'}\">\n";
		foreach my $typedef ( @{$feature->{'typedefs'}} ) {
			print "  <typedef name=\"$typedef->{'name'}\" type=\"$typedef->{'type'}\" />\n";
		}
		foreach my $constant ( @{$feature->{'constants'}} ) {
			print "  <constant name=\"$constant->{'name'}\" value=\"$constant->{'value'}\" />\n";
		}
		foreach my $function ( @{$feature->{'functions'}} ) {
			if ( $function->{'args'} ) {
				print "  <function name=\"$function->{'name'}\" rettype=\"$function->{'rettype'}\" retconst=\"$function->{'retconst'}\" retpointer=\"$function->{'retpointer'}\" >\n";
				foreach my $arg ( @{$function->{'args'}} ) {
					print "   <arg name=\"$arg->{'name'}\" type=\"$arg->{'type'}\" const=\"$arg->{'const'}\" pointer=\"$arg->{'pointer'}\" />\n";
				}
				print "  </function>\n";
			} else {
				print "  <function name=\"$function->{'name'}\" rettype=\"$function->{'rettype'}\" retconst=\"$function->{'retconst'}\" retpointer=\"$function->{'retpointer'}\" />\n";
			}
		}
		print " </feature>\n";
	}
	print "</features>\n";
}

sub mangle_args {
	my (@argsa) = @_;
	if (@argsa) {
		my $args = "";
		my $sep = "";
		foreach my $arg ( @argsa ) {
			my $name = $arg->{'name'};
			my $type = $arg->{'type'};
			my $const = $arg->{'const'};
			my $pointer = $arg->{'pointer'};
			$args = $args . $sep;
			if ($const eq 'yes' ) {
				$args = $args . 'const ' ;
			}
			$args = $args . "GL$type ";
			if ($pointer eq 'yes' ) {
				$args = $args . '*';
			}
			$args = $args . $name;
			$sep = " , ";
		}
		return $args;
	} else {
		return "";
	}
}


sub print_h{
	
	foreach my $feature ( @features ) {
		print "/*$feature->{'name'}*/\n";
		print "#ifdef USE_DYNAMIC_GL_$feature->{'name'}\n";
		foreach my $typedef ( @{$feature->{'typedefs'}} ) {
			print "typedef $typedef->{'type'} GL$typedef->{'name'};\n";
			#print "  <typedef name=\"$typedef->{'name'}\" type=\"$typedef->{'type'}\" />\n";
		}
		foreach my $constant ( @{$feature->{'constants'}} ) {
			print "#define GL_$constant->{'name'} $constant->{'value'}\n"; 
			#print "  <constant name=\"$constant->{'name'}\" value=\"$constant->{'value'}\" />\n";
		}
        if ( @{$feature->{'functions'}} ) {
            print "#ifndef DYNAMIC_GL_NO_FUCPOINTERS\n";
            foreach my $function ( @{$feature->{'functions'}} ) {
                my $args = mangle_args(@{$function->{'args'}});
                my $ret = "void";
                if ( ! ( ($function->{'rettype'} eq "void") && ($function->{'retconst'} eq "no") && ($function->{'retpointer'} eq "no") ) ) {
                    $ret = mangle_type( { type=>$function->{'rettype'},const=>$function->{'retconst'},pointer=>$function->{'retpointer'}},"GL");
                }
                #print "typedef $ret ( DYNAMIC_GL_APIENTRYP DynamicGL_$function->{'name'}_Proc ) ( $args );\n";
                print "extern $ret (DYNAMIC_GL_APIENTRYP DynamicGL_$function->{'name'})($args);\n";
                print "#define gl$function->{'name'} DynamicGL_$function->{'name'}\n";
            }
			print "#else\n";
			print "extern \"C\" {\n";
			foreach my $function ( @{$feature->{'functions'}} ) {
				my $args = mangle_args(@{$function->{'args'}});
                my $ret = "void";
                if ( ! ( ($function->{'rettype'} eq "void") && ($function->{'retconst'} eq "no") && ($function->{'retpointer'} eq "no") ) ) {
                    $ret = mangle_type( { type=>$function->{'rettype'},const=>$function->{'retconst'},pointer=>$function->{'retpointer'}},"GL");
                }
                print " DYNAMIC_GL_APIENTRY $ret gl$function->{'name'}( $args );\n";
            }
			print "}\n";
			print "#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/\n";
        }
		print "extern bool DinamicGLFeature_$feature->{'name'}_Supported();\n";
		print "#endif /*USE_DYNAMIC_GL_$feature->{'name'}*/\n\n";
	}
}

sub print_cpp{
	foreach my $feature ( @features ) {
		print "/*$feature->{'name'}*/\n";
		print "#ifdef USE_DYNAMIC_GL_$feature->{'name'}\n";
	
	    if (@{$feature->{'functions'}}) {
            print "#ifndef DYNAMIC_GL_NO_FUCPOINTERS\n";
			foreach my $function ( @{$feature->{'functions'}} ) {
				my $args = mangle_args(@{$function->{'args'}});
				my $ret = "void";
				if ( ! ( ($function->{'rettype'} eq "void") && ($function->{'retconst'} eq "no") && ($function->{'retpointer'} eq "no") ) ) {
					$ret = mangle_type( { type=>$function->{'rettype'},const=>$function->{'retconst'},pointer=>$function->{'retpointer'}},"GL");
				}
				#print "typedef $ret ( DYNAMIC_GL_APIENTRYP DynamicGL_$function->{'name'}_Proc ) ( $args );\n";
				print "$ret (DYNAMIC_GL_APIENTRYP DynamicGL_$function->{'name'})($args) = 0;\n";
			}
			
            print "static bool DinamicGLFeature_$feature->{'name'}_loaded = false; \n";
            print "static void InitDinamicGLFeature_$feature->{'name'}() {\n";
            foreach my $function ( @{$feature->{'functions'}} ) {
                my $args = mangle_args(@{$function->{'args'}});
                my $ret = "void";
                if ( ! ( ($function->{'rettype'} eq "void") && ($function->{'retconst'} eq "no") && ($function->{'retpointer'} eq "no") ) ) {
                    $ret = mangle_type( { type=>$function->{'rettype'},const=>$function->{'retconst'},pointer=>$function->{'retpointer'}},"GL");
                }
                my $type = "$ret (DYNAMIC_GL_APIENTRYP)($args)";
                print "		DynamicGL_$function->{'name'} = DynamicGL_LoadFunction<$type>(\"gl$function->{'name'}\"); \n";
            }
            print "		DinamicGLFeature_$feature->{'name'}_loaded = true; \n";
            print "}\n";
            print "#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/\n";
        }
		print "bool DinamicGLFeature_$feature->{'name'}_Supported() {\n";
		print "		static bool supported = false;\n";
		print "		static bool checked = false;\n";
		print "		if (checked) return supported;\n";
		print "		checked = true;\n";
		if ($feature->{'core'} eq "no") {
			print "		if(!DynamicGL_CheckExtensionSupported(\"GL_$feature->{'name'}\")) return false;\n";
		}
        if (@{$feature->{'functions'}}) {
            print "#ifndef DYNAMIC_GL_NO_FUCPOINTERS\n";
            print "		if (!DinamicGLFeature_$feature->{'name'}_loaded) {\n";
            print "			InitDinamicGLFeature_$feature->{'name'}();\n";
            print "		}\n";
            foreach my $function ( @{$feature->{'functions'}} ) {
                print "		if (DynamicGL_$function->{'name'}==0) return false; \n";
            }
            print "#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/\n";
        }
		print "		supported = true;\n";
		print "		return true;\n";
		print "}\n";
		print "#endif /*USE_DYNAMIC_GL_$feature->{'name'}*/\n\n";
	}
	
	print "void InternalDynamicGLLoadSubset() {\n";
	print "#ifndef DYNAMIC_GL_NO_FUCPOINTERS\n";
	foreach my $feature ( @features ) {
        if (@{$feature->{'functions'}}) {
            print "#ifdef USE_DYNAMIC_GL_$feature->{'name'}\n";
            print "			InitDinamicGLFeature_$feature->{'name'}();\n";
            print "#endif /*USE_DYNAMIC_GL_$feature->{'name'}*/\n";
        }
	}
	print "#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/\n";
	print "}\n";
}

my ($out_type) = @ARGV;
if (! $out_type ) {
	$out_type = "xml";
}
if ($out_type eq "xml") {
	print_xml();
} elsif ($out_type eq "h" ) {
	print_h();
} elsif ($out_type eq "cpp" ) {
	print_cpp();
} elsif ($out_type eq "glesh" ) {
	print_h();
} elsif ($out_type eq "glescpp" ) {
	print_cpp();
}