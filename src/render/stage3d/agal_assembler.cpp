
#include "agal_assembler.h"
#include "../../ghl_log_impl.h"

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

#define REGISTER(name,val,range,flags) const RegisterDef name = { #name,flags,range,val};
        REGISTERS_LIST
#undef REGISTER

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
        
        const SamplerDef FS = { "FS", 8, 0x5 };
        
        Sampler SamplerDef::operator [] (UInt16 idx) const {
            return Sampler(*this,idx);
        }
        
        std::string Sampler::name_full() const {
            std::stringstream ss;
            ss << m_def.name << "[" << int(index()) << "]";
            return ss.str();
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
    
    void AGALCodeGen::dump() {
        LOG_INFO("program " << (m_type==VERTEX_PROGRAM ? "v":"f") << " " << m_data.size() << " bytes");
        for (std::list<std::string>::const_iterator it = m_errors.begin();it!=m_errors.end();++it) {
            LOG_ERROR("error: " << *it);
        }
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
}
