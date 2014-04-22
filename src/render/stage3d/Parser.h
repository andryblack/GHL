

#if !defined(GHL__AGAL_COCO_PARSER_H__)
#define GHL__AGAL_COCO_PARSER_H__

#include <iostream>
#include <string>
#include <map>


#include <ghl_types.h>
#include "agal_assembler.h"


#include "Scanner.h"

namespace GHL {
namespace AGAL {


class Errors {
public:
	int count;			// number of errors detected

	Errors();
	void SynErr(int line, int col, int n);
	void Error(int line, int col, const char *s);
	void Warning(int line, int col, const char *s);
	void Warning(const char *s);
	void Exception(const char *s);

}; // Errors

class Parser {
private:
	enum {
		_EOF=0,
		_number=1,
		_floatNumber=2,
		_newline=3,
		_identifier=4,
		_token_vertex=5,
		_token_fragment=6,
		_token_attribute=7,
		_token_var=8,
		_token_uniform=9,
		_token_const=10,
		_token_sampler=11,
		_k_linear=12,
		_k_mipdisable=13,
		_k_repeat=14,
		_k_2d=15
	};
	int maxT;

	Token *dummyToken;
	int errDist;
	int minErrDist;

	void SynErr(int n);
	void Get();
	void Expect(int n);
	bool StartOf(int s);
	void ExpectWeak(int n, int follow);
	bool WeakSeparator(int n, int syFol, int repFol);

public:
	Scanner *scanner;
	Errors  *errors;

	Token *t;			// last recognized token
	Token *la;			// lookahead token

AGALCodeGen* m_codegen;

	AGALData::name_to_register_map m_varying_map;
	AGALData::name_to_register_map m_uniform_map;
	AGALData::name_to_register_map m_attributes_map;
	bool m_is_vertex;

	std::map<RegisterName,RegisterName> m_registers_remap;



	Parser(Scanner *scanner);
	~Parser();
	void SemErr(const char* msg);

	void agal();
	void line();
	void directive();
	void expression();
	void vertex();
	void fragment();
	void attribute();
	void var();
	void uniform();
	void constset();
	void sampler_def();
	void directive_name(std::string& name);
	void reg(RegisterName& reg_name);
	void vec4();
	void float_value();
	void code(std::string& name);
	void dst(RegisterName &reg_name,std::string& swizz);
	void src(RegisterName &reg_name,std::string& swizz);
	void swizzle();

	void Parse();

}; // end Parser

} // namespace
} // namespace


#endif

