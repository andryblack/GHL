
#include "agal_assembler.h"
#include "../../ghl_log_impl.h"
#include "../../ghl_data_impl.h"
#include "Parser.h"

namespace GHL {
    
    static const char* MODULE = "AGAL";

    static const UInt32 OP_SPECIAL_MATRIX = 1 << 0;
    static const UInt32 OP_NO_DEST =        1 << 1;
    static const UInt32 OP_INC_NEST =       1 << 2;
    static const UInt32 OP_SCALAR =         1 << 3;
    static const UInt32 OP_DEC_NEST =       1 << 4;
    static const UInt32 OP_FRAG_ONLY =      1 << 5;
    static const UInt32 OP_SPECIAL_TEX =    1 << 6;

    static const UInt32 REG_WRITE = 1 << 0;
    static const UInt32 REG_READ =  1 << 1;
    static const UInt32 REG_FRAG =  1 << 2;
    static const UInt32 REG_VERT =  1 << 3;


    
    namespace AGAL {
    
#define OPCODE(name,args,val,flags) const Opcode name = { #name,args,val,flags };
        OPCODES_LIST
#undef OPCODE

        static inline bool compare_opcode_name(const char* inname, const char* defname) {
            while (*inname && *defname) {
                if (*inname!=*defname) {
                    if (*inname>='a' && *inname<='z') {
                        if ((*inname-'a'+'A')!=*defname)
                            return false;
                    } else {
                        return false;
                    }
                }
                ++inname;
                ++defname;
            }
            return *inname == 0 && *defname == 0;
        }
        static inline bool compare_reg_name(const char* inname,const char* innameend, const char* defname) {
            while (inname!=innameend && *defname) {
                if (*inname!=*defname) {
                    if (*inname>='a' && *inname<='z') {
                        if ((*inname-'a'+'A')!=*defname)
                            return false;
                    } else {
                        return false;
                    }
                }
                ++inname;
                ++defname;
            }
            return inname == innameend && *defname == 0;
        }

        const Opcode* get_opcode(const char* opname) {
#define OPCODE(name,args,val,flags) if (compare_opcode_name(opname,#name)) return &name;
        OPCODES_LIST
#undef OPCODE
            return 0;
        }

#define REGISTER(name,val,range,flags,altname) const RegisterDef name = { #name,flags,range,val};
        REGISTERS_LIST
#undef REGISTER

        static bool parse_register(const char* str,const RegisterDef*& def,size_t& idx) {
            const char* strbeg = str;
            while (*str) {
                if (*str>='0'&&*str<='9') {
                    break;
                }
                ++str;
            }
            def = 0;
#define REGISTER(name,val,range,flags,altname) if ((compare_reg_name(strbeg,str,#name) || \
                                                (altname && compare_reg_name(strbeg,str,altname)))) { def = &name; } else
        REGISTERS_LIST
#undef REGISTER
            {
                return false;
            }
            idx = 0;
            if (def->range!=1 && *str!=0) {
                idx = atoi(str);
            }
            return true;
        }

        RegisterDef::operator Register () const { return Register(*this,0); }
        Register RegisterDef::operator [] (UInt16 idx) const {
            return Register(*this,idx);
        }
        
        std::string Register::name_full() const {
            std::stringstream ss;
            ss << name();
            if (m_def.range>1) {
                ss << "[" << int(index()) << "]";
            }
            return ss.str();
        }

        Register &Register::swizzle(const char *swizzle) {
            m_writemask = (0xf);
            m_swizzle = (0x00|(0x01<<2)|(0x02<<4)|(0x03<<6));
            if (swizzle && *swizzle!=0) {
                m_writemask = 0;
                m_swizzle = 0;
                size_t i = 0;
                Byte cv = 3;
                for (;i<4;++i) {
                    if (!swizzle[i])
                        break;
                    if (swizzle[i]=='x' || swizzle[i]=='X') {
                        cv = 0;
                    } else if (swizzle[i]=='y' || swizzle[i]=='Y') {
                        cv = 1;
                    } else if (swizzle[i]=='z' || swizzle[i]=='Z') {
                        cv = 2;
                    } else if (swizzle[i]=='w' || swizzle[i]=='W') {
                        cv = 3;
                    }
                    m_writemask = m_writemask | ( 1 << cv );
                    m_swizzle = m_swizzle | cv << ( i * 2 );
                }
                for (;i<4;++i) {
                    m_swizzle = m_swizzle | cv << ( i * 2 );
                }

            }
            return *this;
        }
        

        std::string Sampler::name_full() const {
            std::stringstream ss;
            ss << m_def.name << "[" << int(index()) << "]";
            return ss.str();
        }

        bool RegisterName::parse(const char *str)
        {
            return parse_register(str,def,idx);
        }

        
    }
    
    
    bool AGALCodeGen::add(const AGAL::Opcode& op) {
        if (!check_instruction(op,0)) return false;
        write_opcode(op);
        write_zero(32/8);
        write_zero(64/8);
        write_zero(64/8);
        return true;
    }
    bool AGALCodeGen::add(const AGAL::Opcode& op,const AGAL::Register& r1) {
        if (!check_instruction(op,1)) return false;
        if (!check_register(op,r1,0)) return false;
        write_opcode(op);
        write_dest(r1);
        write_zero(64/8);
        write_zero(64/8);
        return true;
    }
    bool AGALCodeGen::add(const AGAL::Opcode& op,const AGAL::Register& r1, const AGAL::Register& r2) {
        if (!check_instruction(op,2)) return false;
        if (!check_register(op,r1,0)) return false;
        if (!check_register(op,r2,1)) return false;
        write_opcode(op);
        write_dest(r1);
        write_source(r2);
        write_zero(64/8);
        return true;
    }
    bool AGALCodeGen::add(const AGAL::Opcode& op,const AGAL::Register& r1, const AGAL::Register& r2, const AGAL::Register& r3) {
        if (!check_instruction(op,3)) return false;
        if (!check_register(op,r1,0)) return false;
        if (!check_register(op,r2,1)) return false;
        if (!check_register(op,r3,2)) return false;
        write_opcode(op);
        write_dest(r1);
        write_source(r2);
        write_source(r3);
        return true;
    }
    
    bool AGALCodeGen::add(const AGAL::Opcode& op,const AGAL::Register& r1, const AGAL::Register& r2, const AGAL::Sampler& r3) {
        if (!check_instruction(op,3)) return false;
        if (!check_register(op,r1,0)) return false;
        if (!check_register(op,r2,1)) return false;
        if (!check_register(op,r3,2)) return false;
        write_opcode(op);
        write_dest(r1);
        write_source(r2);
        write_source(r3);
        return true;
    }
    
    void AGALCodeGen::write_opcode( const AGAL::Opcode& op) {
        write32(op.code);
    }
    
    void AGALCodeGen::write_dest( const AGAL::Register& r) {
        write16( r.index() );
        write8( r.writemask() );
        write8( r.type() );
    }
    
    void AGALCodeGen::write_source( const AGAL::Register& r) {
        write16( r.index() );
        write8( r.indirect() );
        write8( r.swizzle() );
        write8( r.type() );
        write8( r.indextype() );
        write8( r.indexselect() );
        write8( r.relative() ? 0x80 : 0 );
    }
    
    void AGALCodeGen::write_source( const AGAL::Sampler& r) {
        write16( r.index() );
        write8( r.lodbias() );
        write8( 0 );
        write8( r.type() );
        write8( Byte(r.dimension()) << 4 );
        write8( ( r.special() ) | ( r.wrapping() << 4 ) );
        write8( ( r.mipmap() ) | ( r.filter() << 4 ) );
    }
    
    bool AGALCodeGen::check_instruction( const AGAL::Opcode& op, int argsCnt ) {
        if (op.args!=argsCnt) {
            error(*this) << "wrong number of operands for opcode " << op.name
            << ", found " << argsCnt << " but expected "<< op.args << end();
            return false;
        }
        if (m_type != FRAGMENT_PROGRAM) {
            if ( op.flags & OP_FRAG_ONLY) {
                error(*this) << "opcode " << op.name << " is only allowed in fragment programs";
                return false;
            }
        }
        ++m_nops;
        if (m_nops > MAX_OPCODES) {
            error(*this) << "too many opcodes. maximum is " << MAX_OPCODES << end();
            return false;
        }
        if (op.flags & OP_DEC_NEST) {
            if (m_nest==0) {
                error(*this) << "conditional closes without open" << end();
                return false;
            }
            --m_nest;
        }
        if (op.flags & OP_INC_NEST) {
            ++m_nest;
            if (m_nest>MAX_NESTING) {
                error(*this) << "nesting to deep, maximum allowed is " << MAX_NESTING << end();
                return false;
            }
        }
        return true;
    }
    
    bool AGALCodeGen::check_register( const AGAL::Opcode& op, const AGAL::Register& r, int idx ) {
        if ( r.index() >= r.range() ) {
            error(*this) << "register operand " << idx+1 << " ("<<r.name_full()<<") out of range " << r.range() << end();
            return false;
        }
        if ( m_type == FRAGMENT_PROGRAM ) {
            if ( !(r.flags() & REG_FRAG) ) {
                error(*this) << "register operand " << idx+1 << " ("<<r.name_full()<<") not allowed in fragment programs" << end();
                return false;
            }
            if (r.relative()) {
                error(*this) << "register operand "<<idx+1 << " ("<<r.name_full()<<") relative adressing not allowed in fragment programs";
                return false;
            }
        } else {
            if ( !(r.flags() & REG_VERT) ) {
                error(*this) << "register operand " << idx+1 << " ("<<r.name_full()<<") not allowed in vertex programs" << end();
                return false;
            }
        }
        bool is_dest = ( idx == 0 ) && !( op.flags & OP_NO_DEST );
        if (is_dest && r.relative()) {
            error(*this) << "relative can not be destination" << end();
            return false;
        }
        return true;
    }
    
    bool AGALCodeGen::check_register( const AGAL::Opcode& op, const AGAL::Sampler& r, int idx ) {
        if ( r.index() >= r.range() ) {
            error(*this) << "register operand " << idx+1 << " ("<<r.name_full()<<") out of range " << r.range() << end();
            return false;
        }
        if ( m_type != FRAGMENT_PROGRAM ) {
            error(*this) << "register operand " << idx+1 << " ("<<r.name_full()<<") not allowed in vertex programs" << end();
            return false;
        }
        if (idx==0) {
            error(*this) << "sampler can not be destination" << end();
            return false;
        }
        if (idx!=2) {
            error(*this) << "sampler must be last argument" << end();
            return false;
        }
        if (!(op.flags & OP_SPECIAL_TEX)) {
            error(*this) << "use sampler in unsupported instruction" << end();
            return false;
        }
        return true;
    }
    
    void AGALCodeGen::add_error( const std::string& str ) {
        m_errors.push_back(str);
    }
    
    bool AGALCodeGen::dump() {
        LOG_INFO("program " << (m_type==VERTEX_PROGRAM ? "v":"f") << " " << m_data.size() << " bytes");
        for (std::list<std::string>::const_iterator it = m_errors.begin();it!=m_errors.end();++it) {
            LOG_ERROR("error: " << *it);
        }
        if (!m_errors.empty())
            return false;
        size_t all = 0;
        while (all<m_data.size()) {
            std::stringstream ss;
            size_t count = 0;
            while (count < 32 && all<m_data.size()) {
                char buf[5];
                ::snprintf(buf,4,"%02X ",int(m_data[all]));
                ++all;
                ++count;
                ss << buf;
            }
            LOG_INFO(ss.str());
        }
        LOG_INFO("instructions: " << m_nops);
        return true;
    }

    
    AGALCodeGen::AGALCodeGen( ProgramType prg ) : m_type( prg ) {
        write8(0xa0);
        write32(1);
        write8(0xa1);
        if (prg==VERTEX_PROGRAM)
            write8(0);
        else if (prg==FRAGMENT_PROGRAM)
            write8(1);
        m_nops = 0;
        m_nest = 0;
    }


    AGALAssembler::AGALAssembler(AGALData *data) : m_data(data) {

    }
    AGALAssembler::~AGALAssembler() {

    }

    bool AGALAssembler::parse(const Data *srcv, const Data *srcf)
    {
        if (!srcv || !srcf) {
            LOG_ERROR("empty data");
            return false;
        }
        if (m_data->codef || m_data->codef) {
            LOG_ERROR("already parsed");
            return false;
        }
        AGALData::name_to_register_map varying;
        {
            /// parse vertex
            AGAL::Scanner scanner(srcv->GetData(),srcv->GetSize());
            AGAL::Parser parser(&scanner);
            parser.m_attributes_map["vPosition"] =  AGAL::RegisterName(AGAL::VA,0);
            parser.m_attributes_map["vColor"] =     AGAL::RegisterName(AGAL::VA,1);
            parser.m_attributes_map["vTexCoord"] =  AGAL::RegisterName(AGAL::VA,2);
            parser.m_attributes_map["vTexCoord2"] = AGAL::RegisterName(AGAL::VA,3);

            parser.Parse();
            if (!parser.m_is_vertex) {
                LOG_ERROR("not vertex program");
                delete parser.m_codegen;
                return false;
            }
            if (parser.errors->count || !parser.m_codegen) {
                delete parser.m_codegen;
                return false;
            }
            if (!parser.m_codegen->dump()) {
                delete parser.m_codegen;
                return false;
            }
            varying = parser.m_varying_map;
            m_data->codev = new DataImpl(parser.m_codegen->size(),parser.m_codegen->data());
            delete parser.m_codegen;
            for (AGALData::name_to_register_map::const_iterator it = parser.m_uniform_map.begin();it!=parser.m_uniform_map.end();++it) {
                m_data->uniforms.insert(*it);
            }
            for (AGALData::constants_map::const_iterator it = parser.m_constants.begin();it!=parser.m_constants.end();++it) {
                m_data->constants.insert(*it);
            }
        }
        {
            /// parse fragment
            AGAL::Scanner scanner(srcf->GetData(),srcf->GetSize());
            AGAL::Parser parser(&scanner);
            parser.m_varying_map = varying;
            parser.Parse();
            if (parser.m_is_vertex) {
                LOG_ERROR("not fragment program");
                delete parser.m_codegen;
                return false;
            }
            if (parser.errors->count || !parser.m_codegen) {
                delete parser.m_codegen;
                return false;
            }
            if (!parser.m_codegen->dump()) {
                delete parser.m_codegen;
                return false;
            }
            m_data->codef = new DataImpl(parser.m_codegen->size(),parser.m_codegen->data());
            delete parser.m_codegen;
            for (AGALData::name_to_register_map::const_iterator it = parser.m_uniform_map.begin();it!=parser.m_uniform_map.end();++it) {
                m_data->uniforms.insert(*it);
            }
            for (AGALData::constants_map::const_iterator it = parser.m_constants.begin();it!=parser.m_constants.end();++it) {
                m_data->constants.insert(*it);
            }
        }
        for (AGALData::constants_map::const_iterator it = m_data->constants.begin();it!=m_data->constants.end();++it) {
            LOG_INFO("set constant " << it->first << " to { "
                     << it->second.data[0] << ";"
                     << it->second.data[1] << ";"
                     << it->second.data[2] << ";"
                     << it->second.data[3] << "}" );
        }
        for (AGALData::name_to_register_map::const_iterator it = m_data->uniforms.begin();it!=m_data->uniforms.end();++it) {
            LOG_INFO("bind uniform  " << it->first << " to " << it->second);
        }
        return true;
    }
}
