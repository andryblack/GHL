

#include <wchar.h>
#include "Parser.h"
#include "Scanner.h"

#include "agal_assembler.h"

namespace GHL {
namespace AGAL {


void Parser::SynErr(int n) {
	if (errDist >= minErrDist) errors->SynErr(la->line, la->col, n);
	errDist = 0;
}

void Parser::SemErr(const char* msg) {
	if (errDist >= minErrDist) errors->Error(t->line, t->col, msg);
	errDist = 0;
}

void Parser::Get() {
	for (;;) {
		t = la;
		la = scanner->Scan();
		if (la->kind <= maxT) { ++errDist; break; }

		if (dummyToken != t) {
			dummyToken->kind = t->kind;
			dummyToken->pos = t->pos;
			dummyToken->col = t->col;
			dummyToken->line = t->line;
			dummyToken->next = NULL;
			coco_string_delete(dummyToken->val);
			dummyToken->val = coco_string_create(t->val);
			t = dummyToken;
		}
		la = t;
	}
}

void Parser::Expect(int n) {
	if (la->kind==n) Get(); else { SynErr(n); }
}

void Parser::ExpectWeak(int n, int follow) {
	if (la->kind == n) Get();
	else {
		SynErr(n);
		while (!StartOf(follow)) Get();
	}
}

bool Parser::WeakSeparator(int n, int syFol, int repFol) {
	if (la->kind == n) {Get(); return true;}
	else if (StartOf(repFol)) {return false;}
	else {
		SynErr(n);
		while (!(StartOf(syFol) || StartOf(repFol) || StartOf(0))) {
			Get();
		}
		return StartOf(syFol);
	}
}

void Parser::agal() {
		m_codegen = 0;
		while (StartOf(1)) {
			line();
			Expect(_newline);
		}
		
}

void Parser::line() {
		if (StartOf(2)) {
			if (StartOf(3)) {
				directive();
			} else {
				expression();
			}
		}
}

void Parser::directive() {
		switch (la->kind) {
		case _token_vertex: {
			vertex();
			break;
		}
		case _token_fragment: {
			fragment();
			break;
		}
		case _token_attribute: {
			attribute();
			break;
		}
		case _token_var: {
			var();
			break;
		}
		case _token_uniform: {
			uniform();
			break;
		}
		case _token_const: {
			constset();
			break;
		}
		case _token_sampler: {
			sampler_def();
			break;
		}
		default: SynErr(25); break;
		}
}

void Parser::expression() {
		if (!m_codegen) {
		SemErr("must specify program type before opcodes");
		return;
		}
		std::string opcode_name; 
		
		while (!(la->kind == _EOF || la->kind == _identifier)) {SynErr(26); Get();}
		code(opcode_name);
		const Opcode* opcode = get_opcode(opcode_name.c_str());
		if (!opcode) {
		std::string err = "unknown opcode '" + opcode_name + "'";
		SemErr(err.c_str());
		return;
		}
		std::cout << opcode->name << " ";
		RegisterName dst_reg;
		std::string dst_swizzle;
		RegisterName src1_reg;
		std::string src1_swizzle;
		RegisterName src2_reg;
		std::string src2_swizzle;
		
		if (la->kind == _identifier) {
			dst(dst_reg,dst_swizzle);
			std::cout << dst_reg << (dst_swizzle.empty() ? "" : ".") << dst_swizzle;
			
			if (la->kind == 20 /* "," */) {
				Get();
				src(src1_reg,src1_swizzle);
				std::cout << ", " << src1_reg << (src1_swizzle.empty() ? "" : ".") << src1_swizzle;
				
				if (la->kind == 20 /* "," */) {
					Get();
					src(src2_reg,src2_swizzle);
					std::cout << ", " << src2_reg << (src2_swizzle.empty() ? "" : ".") << src2_swizzle;
					
					if (la->kind == 21 /* "<" */) {
						Get();
						Expect(_k_linear);
						Expect(_k_mipdisable);
						Expect(_k_repeat);
						Expect(_k_2d);
						Expect(22 /* ">" */);
					}
				}
			}
		}
		std::cout << std::endl;
		if (dst_reg.def) {
		Register dst(dst_reg);
		if (!dst_swizzle.empty()) dst.swizzle(dst_swizzle.c_str());
		if (src1_reg.def) {
			Register src1(src1_reg);
			if (!src1_swizzle.empty()) src1.swizzle(src1_swizzle.c_str());
			if (src2_reg.def) {
				if (src2_reg.def == &FS) {
					Sampler src2(*src2_reg.def,src2_reg.idx);
					if (!src2_swizzle.empty()) {
						SemErr("swizzle not supported on sampler");
						return;
					}
					m_codegen->add(*opcode,dst,src1,src2);
				} else {
					Register src2(src2_reg);
					if (!src2_swizzle.empty()) src2.swizzle(src2_swizzle.c_str());
					m_codegen->add(*opcode,dst,src1,src2);
				}
			} else {
				m_codegen->add(*opcode,dst,src1);
			}
		} else {
			m_codegen->add(*opcode,dst);
		}
		} else {
		m_codegen->add(*opcode);
		}
		
}

void Parser::vertex() {
		Expect(_token_vertex);
		m_codegen = new AGALCodeGen(AGALCodeGen::VERTEX_PROGRAM); m_is_vertex = true; 
}

void Parser::fragment() {
		Expect(_token_fragment);
		m_codegen = new AGALCodeGen(AGALCodeGen::FRAGMENT_PROGRAM); m_is_vertex = false; 
}

void Parser::attribute() {
		RegisterName reg_name; std::string name; 
		Expect(_token_attribute);
		directive_name(name);
		Expect(16 /* "=" */);
		reg(reg_name);
		if (m_is_vertex) {
		AGALData::name_to_register_map::iterator it = m_attributes_map.find(name);
		if (it==m_attributes_map.end()) {
			SemErr((std::string("unknown attribute ") + name).c_str() );
			return;
		}
		if (it->second!=reg_name) {
			m_registers_remap[reg_name] = it->second;
		}
		}
		
}

void Parser::var() {
		RegisterName reg_name; std::string name;
		Expect(_token_var);
		directive_name(name);
		Expect(16 /* "=" */);
		reg(reg_name);
		if (m_is_vertex) {
		m_varying_map[name] = reg_name;
		} else {
		AGALData::name_to_register_map::iterator it = m_varying_map.find(name);
		if (it==m_varying_map.end()) {
			SemErr((std::string("undefined uniform ") + name).c_str() );
			return;
		}
		if (it->second!=reg_name) {
			m_registers_remap[reg_name] = it->second;
		}
		} 
}

void Parser::uniform() {
		RegisterName reg_name; std::string name; 
		Expect(_token_uniform);
		directive_name(name);
		Expect(16 /* "=" */);
		reg(reg_name);
		m_uniform_map[name] = reg_name; 
}

void Parser::constset() {
		RegisterName reg_name; 
		Expect(_token_const);
		reg(reg_name);
		Expect(16 /* "=" */);
		vec4();
}

void Parser::sampler_def() {
		RegisterName reg_name; std::string name; 
		Expect(_token_sampler);
		directive_name(name);
		Expect(16 /* "=" */);
		reg(reg_name);
		if (reg_name.def!=&FS) {
		SemErr( "sampler register must be FS" );
		return;
		}
		static const char* prefix = "texture_";
		if (name.find(prefix)!=0) {
		SemErr( "sampler name must be 'texture_%num%'" );
		return;
		}
		size_t num = atoi(name.c_str()+strlen(prefix));
		if (num!=reg_name.idx) {
		SemErr( "sampler index invalid" );
		return;
		/// @todo remap sampler
		}
		
}

void Parser::directive_name(std::string& name) {
		Expect(_identifier);
		name = t->val; 
}

void Parser::reg(RegisterName& reg_name) {
		Expect(_identifier);
		reg_name.def = 0;
		reg_name.idx = 0;
		if (!reg_name.parse(t->val)) {
		std::string err = std::string("unknown register '") + std::string(t->val) + "'";
		SemErr(err.c_str());
		return;
		}
		
}

void Parser::vec4() {
		Expect(17 /* "{" */);
		float_value();
		Expect(18 /* ";" */);
		float_value();
		Expect(18 /* ";" */);
		float_value();
		Expect(18 /* ";" */);
		float_value();
		Expect(19 /* "}" */);
}

void Parser::float_value() {
		if (la->kind == _number) {
			Get();
		} else if (la->kind == _floatNumber) {
			Get();
		} else SynErr(27);
}

void Parser::code(std::string& name) {
		Expect(_identifier);
		name = t->val; 
}

void Parser::dst(RegisterName &reg_name,std::string& swizz) {
		reg(reg_name);
		std::map<RegisterName,RegisterName>::const_iterator it = m_registers_remap.find(reg_name);
		if (it!=m_registers_remap.end()) {
		reg_name = it->second;
		}
		
		if (la->kind == 23 /* "." */) {
			Get();
			swizzle();
			swizz = t->val;
		}
}

void Parser::src(RegisterName &reg_name,std::string& swizz) {
		reg(reg_name);
		std::map<RegisterName,RegisterName>::const_iterator it = m_registers_remap.find(reg_name);
		if (it!=m_registers_remap.end()) {
		reg_name = it->second;
		}
		
		if (la->kind == 23 /* "." */) {
			Get();
			swizzle();
			swizz = t->val;
		}
}

void Parser::swizzle() {
		Expect(_identifier);
}




// If the user declared a method Init and a mehtod Destroy they should
// be called in the contructur and the destructor respctively.
//
// The following templates are used to recognize if the user declared
// the methods Init and Destroy.

template<typename T>
struct ParserInitExistsRecognizer {
	template<typename U, void (U::*)() = &U::Init>
	struct ExistsIfInitIsDefinedMarker{};

	struct InitIsMissingType {
		char dummy1;
	};
	
	struct InitExistsType {
		char dummy1; char dummy2;
	};

	// exists always
	template<typename U>
	static InitIsMissingType is_here(...);

	// exist only if ExistsIfInitIsDefinedMarker is defined
	template<typename U>
	static InitExistsType is_here(ExistsIfInitIsDefinedMarker<U>*);

	enum { InitExists = (sizeof(is_here<T>(NULL)) == sizeof(InitExistsType)) };
};

template<typename T>
struct ParserDestroyExistsRecognizer {
	template<typename U, void (U::*)() = &U::Destroy>
	struct ExistsIfDestroyIsDefinedMarker{};

	struct DestroyIsMissingType {
		char dummy1;
	};
	
	struct DestroyExistsType {
		char dummy1; char dummy2;
	};

	// exists always
	template<typename U>
	static DestroyIsMissingType is_here(...);

	// exist only if ExistsIfDestroyIsDefinedMarker is defined
	template<typename U>
	static DestroyExistsType is_here(ExistsIfDestroyIsDefinedMarker<U>*);

	enum { DestroyExists = (sizeof(is_here<T>(NULL)) == sizeof(DestroyExistsType)) };
};

// The folloing templates are used to call the Init and Destroy methods if they exist.

// Generic case of the ParserInitCaller, gets used if the Init method is missing
template<typename T, bool = ParserInitExistsRecognizer<T>::InitExists>
struct ParserInitCaller {
	static void CallInit(T *t) {
		// nothing to do
	}
};

// True case of the ParserInitCaller, gets used if the Init method exists
template<typename T>
struct ParserInitCaller<T, true> {
	static void CallInit(T *t) {
		t->Init();
	}
};

// Generic case of the ParserDestroyCaller, gets used if the Destroy method is missing
template<typename T, bool = ParserDestroyExistsRecognizer<T>::DestroyExists>
struct ParserDestroyCaller {
	static void CallDestroy(T *t) {
		// nothing to do
	}
};

// True case of the ParserDestroyCaller, gets used if the Destroy method exists
template<typename T>
struct ParserDestroyCaller<T, true> {
	static void CallDestroy(T *t) {
		t->Destroy();
	}
};

void Parser::Parse() {
	t = NULL;
	la = dummyToken = new Token();
	la->val = coco_string_create("Dummy Token");
	Get();
	agal();
	Expect(0);
}

Parser::Parser(Scanner *scanner) {
	maxT = 24;

	ParserInitCaller<Parser>::CallInit(this);
	dummyToken = NULL;
	t = la = NULL;
	minErrDist = 2;
	errDist = minErrDist;
	this->scanner = scanner;
	errors = new Errors();
}

bool Parser::StartOf(int s) {
	const bool T = true;
	const bool x = false;

	static bool set[4][26] = {
		{T,x,x,x, T,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x,x,x, x,x},
		{x,x,x,T, T,T,T,T, T,T,T,T, x,x,x,x, x,x,x,x, x,x,x,x, x,x},
		{x,x,x,x, T,T,T,T, T,T,T,T, x,x,x,x, x,x,x,x, x,x,x,x, x,x},
		{x,x,x,x, x,T,T,T, T,T,T,T, x,x,x,x, x,x,x,x, x,x,x,x, x,x}
	};



	return set[s][la->kind];
}

Parser::~Parser() {
	ParserDestroyCaller<Parser>::CallDestroy(this);
	delete errors;
	delete dummyToken;
}

Errors::Errors() {
	count = 0;
}

void Errors::SynErr(int line, int col, int n) {
	char* s;
	switch (n) {
			case 0: s = coco_string_create(COCOTEXT("EOF expected")); break;
			case 1: s = coco_string_create(COCOTEXT("number expected")); break;
			case 2: s = coco_string_create(COCOTEXT("floatNumber expected")); break;
			case 3: s = coco_string_create(COCOTEXT("newline expected")); break;
			case 4: s = coco_string_create(COCOTEXT("identifier expected")); break;
			case 5: s = coco_string_create(COCOTEXT("token_vertex expected")); break;
			case 6: s = coco_string_create(COCOTEXT("token_fragment expected")); break;
			case 7: s = coco_string_create(COCOTEXT("token_attribute expected")); break;
			case 8: s = coco_string_create(COCOTEXT("token_var expected")); break;
			case 9: s = coco_string_create(COCOTEXT("token_uniform expected")); break;
			case 10: s = coco_string_create(COCOTEXT("token_const expected")); break;
			case 11: s = coco_string_create(COCOTEXT("token_sampler expected")); break;
			case 12: s = coco_string_create(COCOTEXT("k_linear expected")); break;
			case 13: s = coco_string_create(COCOTEXT("k_mipdisable expected")); break;
			case 14: s = coco_string_create(COCOTEXT("k_repeat expected")); break;
			case 15: s = coco_string_create(COCOTEXT("k_2d expected")); break;
			case 16: s = coco_string_create(COCOTEXT("\"=\" expected")); break;
			case 17: s = coco_string_create(COCOTEXT("\"{\" expected")); break;
			case 18: s = coco_string_create(COCOTEXT("\";\" expected")); break;
			case 19: s = coco_string_create(COCOTEXT("\"}\" expected")); break;
			case 20: s = coco_string_create(COCOTEXT("\",\" expected")); break;
			case 21: s = coco_string_create(COCOTEXT("\"<\" expected")); break;
			case 22: s = coco_string_create(COCOTEXT("\">\" expected")); break;
			case 23: s = coco_string_create(COCOTEXT("\".\" expected")); break;
			case 24: s = coco_string_create(COCOTEXT("??? expected")); break;
			case 25: s = coco_string_create(COCOTEXT("invalid directive")); break;
			case 26: s = coco_string_create(COCOTEXT("this symbol not expected in expression")); break;
			case 27: s = coco_string_create(COCOTEXT("invalid float_value")); break;

		default:
		{
			char format[20];
			coco_sprintf(format, 20, "error %d", n);
			s = coco_string_create(format);
		}
		break;
	}
	printf("-- line %d col %d: %s\n", line, col, s);
	coco_string_delete(s);
	count++;
}

void Errors::Error(int line, int col, const char *s) {
	printf("-- line %d col %d: %s\n", line, col, s);
	count++;
}

void Errors::Warning(int line, int col, const char *s) {
	printf("-- line %d col %d: %s\n", line, col, s);
}

void Errors::Warning(const char *s) {
	printf("%s\n", s);
}

void Errors::Exception(const char* s) {
	printf("%s", s); 
	exit(1);
}

} // namespace
} // namespace

