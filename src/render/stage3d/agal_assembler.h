#ifndef GHL_AGAL_ASSEMBLER_H
#define GHL_AGAL_ASSEMBLER_H

#include "ghl_types.h"
#include <sstream>
#include <vector>
#include <list>
#include <string>

namespace GHL {

    
    
#define OPCODES_LIST \
    OPCODE( MOV, 2, 0x00, 0 )\
    OPCODE( ADD, 3, 0x01, 0 )\
    OPCODE( SUB, 3, 0x02, 0 )\
    OPCODE( MUL, 3, 0x03, 0 )\
    OPCODE( DIV, 3, 0x04, 0 )\
    OPCODE( RCP, 2, 0x05, 0 )\
    OPCODE( MIN, 3, 0x06, 0 )\
    OPCODE( MAX, 3, 0x07, 0 )\
    OPCODE( FRC, 2, 0x08, 0 )\
    OPCODE( SQT, 2, 0x09, 0 )\
    OPCODE( RSQ, 2, 0x0a, 0 )\
    OPCODE( POW, 3, 0x0b, 0 )\
    OPCODE( LOG, 2, 0x0c, 0 )\
    OPCODE( EXP, 2, 0x0d, 0 )\
    OPCODE( NRM, 2, 0x0e, 0 )\
    OPCODE( SIN, 2, 0x0f, 0 )\
    OPCODE( COS, 2, 0x10, 0 )\
    OPCODE( CRS, 3, 0x11, 0 )\
    OPCODE( DP3, 3, 0x12, 0 )\
    OPCODE( DP4, 3, 0x13, 0 )\
    OPCODE( ABS, 2, 0x14, 0 )\
    OPCODE( NEG, 2, 0x15, 0 )\
    OPCODE( SAT, 2, 0x16, 0 )\
    OPCODE( M33, 3, 0x17, OP_SPECIAL_MATRIX )\
    OPCODE( M44, 3, 0x18, OP_SPECIAL_MATRIX )\
    OPCODE( M34, 3, 0x19, OP_SPECIAL_MATRIX )\
    OPCODE( IFZ, 1, 0x1a, OP_NO_DEST | OP_INC_NEST | OP_SCALAR )\
    OPCODE( INZ, 1, 0x1b, OP_NO_DEST | OP_INC_NEST | OP_SCALAR )\
    OPCODE( IFE, 2, 0x1c, OP_NO_DEST | OP_INC_NEST | OP_SCALAR )\
    OPCODE( INE, 2, 0x1d, OP_NO_DEST | OP_INC_NEST | OP_SCALAR )\
    OPCODE( IFG, 2, 0x1e, OP_NO_DEST | OP_INC_NEST | OP_SCALAR )\
    OPCODE( IFL, 2, 0x1f, OP_NO_DEST | OP_INC_NEST | OP_SCALAR )\
    OPCODE( IEG, 2, 0x20, OP_NO_DEST | OP_INC_NEST | OP_SCALAR )\
    OPCODE( IEL, 2, 0x21, OP_NO_DEST | OP_INC_NEST | OP_SCALAR )\
    OPCODE( ELS, 0, 0x22, OP_NO_DEST | OP_INC_NEST | OP_DEC_NEST )\
    OPCODE( EIF, 0, 0x23, OP_NO_DEST | OP_DEC_NEST )\
    OPCODE( REP, 1, 0x24, OP_NO_DEST | OP_INC_NEST | OP_SCALAR )\
    OPCODE( ERP, 0, 0x25, OP_NO_DEST | OP_DEC_NEST )\
    OPCODE( BRK, 0, 0x26, OP_NO_DEST )\
    OPCODE( KIL, 1, 0x27, OP_NO_DEST | OP_FRAG_ONLY )\
    OPCODE( TEX, 3, 0x28, OP_FRAG_ONLY | OP_SPECIAL_TEX )\
    OPCODE( SGE, 3, 0x29, 0 )\
    OPCODE( SLT, 3, 0x2a, 0 )\
    OPCODE( SGN, 2, 0x2b, 0 )\
    OPCODE( SEQ, 3, 0x2c, 0 )\
    OPCODE( SNE, 3, 0x2d, 0 )\
    
    namespace AGAL {
    
        struct Opcode {
            const char* name;
            Byte    args;
            Byte    code;
            UInt16  flags;
        };
        
        
#define OPCODE(name,args,val,flags) extern const Opcode name;
        OPCODES_LIST
#undef OPCODE
        
        class Register;
        
        struct RegisterDef {
            const char* const name;
            const UInt16 flags;
            const UInt16 range;
            const Byte  value;
            operator Register () const;
            Register operator [] (UInt16 idx) const;
        };
        
        class Register {
        private:
            const RegisterDef& m_def;
            bool    m_relative;
            UInt16   m_index;
            Byte    m_writemask;
            Byte    m_indirect;
            Byte    m_swizzle;
            Byte    m_indextype;
            Byte    m_indexselect;
        public:
            explicit Register(const RegisterDef& def,UInt16 idx) : m_def(def),
                m_relative(false),
                m_index(idx),
                m_writemask(0xf),
                m_indirect(0),
                m_swizzle(0x00|(0x01<<2)|(0x02<<4)|(0x03<<6)),
                m_indextype(0),
                m_indexselect(0){
                
            }
            const UInt16 index() const { return m_index; }
            const UInt16 flags() const { return m_def.flags; }
            const UInt16 range() const { return m_def.range; }
            const char* name() const { return m_def.name; }
            const bool relative() const { return m_relative; }
            const Byte writemask() const { return m_writemask; }
            const Byte type() const { return m_def.value; }
            const Byte indirect() const { return m_indirect; }
            const Byte swizzle() const { return m_swizzle; }
            const Byte indextype() const { return m_indextype; }
            const Byte indexselect() const { return m_indexselect; }
            std::string name_full() const;
        };
        
        
        
        
       
#define REGISTERS_LIST \
        REGISTER(VA,/* vertex attribute     */  0x0,	8,		REG_VERT | REG_READ )\
        REGISTER(VC,/* vertex constant      */  0x1,	128,	REG_VERT | REG_READ )\
        REGISTER(VT,/* vertex temporary     */	0x2,	8,		REG_VERT | REG_WRITE | REG_READ )\
        REGISTER(VO,/* vertex output        */  0x3,	1,		REG_VERT | REG_WRITE )\
        REGISTER(I,/*  varying              */  0x4,	8,		REG_VERT | REG_FRAG | REG_READ | REG_WRITE )\
        REGISTER(FC,/* fragment constant    */  0x1,	28,		REG_FRAG | REG_READ )\
        REGISTER(FT,/* fragment temporary   */  0x2,	8,		REG_FRAG | REG_WRITE | REG_READ )\
        REGISTER(FO,/* fragment output      */  0x3,	1,		REG_FRAG | REG_WRITE )
  
#define REGISTER(name,val,range,flags) extern const RegisterDef name;
        REGISTERS_LIST
#undef REGISTER

        //REGISTER(FS,/* texture sampler      */  0x5,	8,		REG_FRAG | REG_READ )\
        
        // texture sampler register: always 64 bits
        // 63.............................................................0
        // FFFFMMMMWWWWSSSSDDDD--------TTTT--------BBBBBBBBNNNNNNNNNNNNNNNN
        // N = Sampler index (16 bits)
        // B = Texture lod bias, signed integer, scale by 8. the floating point value used is b/8.0 (8 bits)
        // T = Register type, must be reg_sampler
        // F = Filter (0=nearest,1=linear,2=anisotropic) (4 bits)
        // M = Mipmap (0=disable,1=nearest,2=linear)
        // W = Wrapping (0=clamp,1=repeat)
        // S = Special flag bits (bit 0=centroid sampling, bit 1=single component read)
        // D = Dimension (0=2D,1=Cube,2=3D)
        
        class Sampler;
        struct SamplerDef {
            const char* const name;
            const UInt16 range;
            const Byte  value;
            Sampler operator [] (UInt16 idx) const;
        };
        class Sampler {
        private:
            const SamplerDef& m_def;
            UInt32  m_index;
            Int8    m_lodbias;
            Byte    m_dimension;
            Byte    m_special;
            Byte    m_wrapping;
            Byte    m_mipmap;
            Byte    m_filter;
        public:
            explicit Sampler( const SamplerDef& def, UInt16 idx )
            : m_def(def)
            , m_index(idx)
            , m_lodbias(0)
            , m_dimension(0)
            , m_special(0)
            , m_wrapping(0)
            , m_mipmap(0)
            , m_filter(0) {
                
            }
            const UInt16 range() const { return m_def.range; }
            const Byte type() const { return m_def.value; }
            const UInt16 index() const { return m_index; }
            const Int8 lodbias() const { return m_lodbias; }
            const Byte dimension() const { return m_dimension; }
            const Byte special() const { return m_special; }
            const Byte wrapping() const { return m_wrapping; }
            const Byte mipmap() const { return m_mipmap; }
            const Byte filter() const { return m_filter; }
            std::string name_full() const;
            Sampler& nearest() { m_filter = 0; return *this; }
            Sampler& linear() { m_filter = 1; return *this; }
            Sampler& clamp() { m_wrapping = 0; return *this; }
            Sampler& repeat() { m_wrapping = 1; return *this; }
        };
        extern const SamplerDef FS;
    }
    
    class AGALCodeGen {
    public:
        enum ProgramType {
            VERTEX_PROGRAM,
            FRAGMENT_PROGRAM
        };
        static const size_t MAX_OPCODES = 256;
        static const size_t MAX_NESTING = 4;
        

        explicit AGALCodeGen( ProgramType prg );
        
        size_t size() const { return m_data.size(); }
        const Byte* data() const { return &m_data[0]; }
        
        bool add(const AGAL::Opcode& op);
        bool add(const AGAL::Opcode& op,const AGAL::Register& r1);
        bool add(const AGAL::Opcode& op,const AGAL::Register& r1, const AGAL::Register& r2);
        bool add(const AGAL::Opcode& op,const AGAL::Register& r1, const AGAL::Register& r2, const AGAL::Register& r3);
        bool add(const AGAL::Opcode& op,const AGAL::Register& r1, const AGAL::Register& r2, const AGAL::Sampler& r3);
        
        void add_error( const std::string& str );
        
        void dump();
    protected:
        void write8( Byte v ) {
            m_data.push_back( v );
        }
        void write16( UInt16 v ) {
            m_data.push_back( v & 0xff);
            m_data.push_back( (v >> 8) & 0xff );
        }
        void write32( UInt32 v ) {
            m_data.push_back( v & 0xff);
            m_data.push_back( (v >> 8) & 0xff );
            m_data.push_back( (v >> 16) & 0xff );
            m_data.push_back( (v >> 24) & 0xff );
        }
        struct end {
        };
        struct error {
            AGALCodeGen& cg;
            explicit error( AGALCodeGen& cg ) : cg(cg) {}
            std::stringstream ss;
            void operator << (const end& ) { cg.add_error(ss.str()); }
            template <class T>
            error& operator << (T v) {
                ss << v;
                return *this;
            }
        };
        bool check_instruction( const AGAL::Opcode& op, int argsCnt );
        bool check_register( const AGAL::Opcode& op, const AGAL::Register& r, int idx );
        bool check_register( const AGAL::Opcode& op, const AGAL::Sampler& r, int idx );
        void write_opcode( const AGAL::Opcode& op);
        void write_dest( const AGAL::Register& r);
        void write_source( const AGAL::Register& r);
        void write_source( const AGAL::Sampler& r);
        void write_zero( size_t cnt ) { for (size_t i=0;i<cnt;++i) m_data.push_back(0); }
    private:
        ProgramType         m_type;
        std::vector<Byte>   m_data;
        std::list<std::string>  m_errors;
        size_t m_nops;
        size_t m_nest;
        
    };
    
    class AGALAssembler {
    public:
        //explicit AGALAssembler( ProgramType prg );
        
    private:
        
    };
    
}

#endif /*GHL_AGAL_ASSEMBLER_H*/
