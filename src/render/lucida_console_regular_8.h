#ifndef _lucida_console_regular_8_h_included_
#define _lucida_console_regular_8_h_included_
static const int lucida_console_regular_8_width = 128;
static const int lucida_console_regular_8_height = 128;
extern const unsigned char lucida_console_regular_8_data[];
struct CharDef { 
  int x;
  int y;
  int w;
  int h;
  int ox;
  int oy;
  int a;
};
extern const CharDef lucida_console_regular_8_chars[];

#endif /*_lucida_console_regular_8_h_included_*/
