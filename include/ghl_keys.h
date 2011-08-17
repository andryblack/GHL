/*
    GHL - Game Helpers Library
    Copyright (C)  Andrey Kunitsyn 2009

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

    Andrey (AndryBlack) Kunitsyn
    blackicebox (at) gmail (dot) com
*/

#ifndef GHL_KEYS_H
#define GHL_KEYS_H

namespace GHL
{

	enum MouseButton
	{
		MOUSE_BUTTON_LEFT,
		MOUSE_BUTTON_RIGHT,
		MOUSE_BUTTON_MIDDLE,
		TOUCH_1 = MOUSE_BUTTON_LEFT,
	};

	enum Key
	{
		KEY_NONE,		///< none
		
		KEY_ESCAPE		,///< escape
		KEY_BACKSPACE	,///< backspace
		KEY_TAB			,///< tab
		KEY_ENTER		,///< enter
		KEY_SPACE		,///< space

		KEY_SHIFT		,///< shift
		KEY_CTRL		,///< control
		KEY_ALT			,///< alt

		KEY_LWIN		,///< left "win"
		KEY_RWIN		,///< right "win"
		KEY_APPS		,///< "app" key

		KEY_PAUSE		,///< pause
		KEY_CAPSLOCK	,///< caps lock
		KEY_NUMLOCK		,///< num lock
		KEY_SCROLLLOCK	,///< scroll lock

		KEY_PGUP		,///< page up
		KEY_PGDN		,///< page down
		KEY_HOME		,///< home
		KEY_END			,///< end
		KEY_INSERT		,///< insert
		KEY_DELETE		,///< delete

		KEY_LEFT		,///< left
		KEY_UP			,///< up
		KEY_RIGHT		,///< right
		KEY_DOWN		,///< down

		KEY_0			,///< "0"
		KEY_1			,///< "1"
		KEY_2			,///< "2"
		KEY_3			,///< "3"
		KEY_4			,///< "4"
		KEY_5			,///< "5"
		KEY_6			,///< "6"
		KEY_7			,///< "7"
		KEY_8			,///< "8"
		KEY_9			,///< "9"

		KEY_A			,///< "a"
		KEY_B			,///< "b"
		KEY_C			,///< "c"
		KEY_D			,///< "d"
		KEY_E			,///< "e"
		KEY_F			,///< "f"
		KEY_G			,///< "g"
		KEY_H			,///< "h"
		KEY_I			,///< "i"
		KEY_J			,///< "j"
		KEY_K			,///< "k"
		KEY_L			,///< "l"
		KEY_M			,///< "m"
		KEY_N			,///< "n"
		KEY_O			,///< "o"
		KEY_P			,///< "p"
		KEY_Q			,///< "q"
		KEY_R			,///< "r"
		KEY_S			,///< "s"
		KEY_T			,///< "t"
		KEY_U			,///< "u"
		KEY_V			,///< "v"
		KEY_W			,///< "w"
		KEY_X			,///< "x"
		KEY_Y			,///< "y"
		KEY_Z			,///< "z"

		KEY_GRAVE		,///< "???"
		KEY_MINUS		,///< "-"
		KEY_EQUALS		,///< "="
		KEY_BACKSLASH	,///< "\"
		KEY_LBRACKET	,///< "["
		KEY_RBRACKET	,///< "]"
		KEY_SEMICOLON	,///< ";"
		KEY_APOSTROPHE	,///< "`"
		KEY_COMMA		,///< ":"
		KEY_PERIOD		,///< "???"
		KEY_SLASH		,///< "/"

		KEY_NUMPAD0,	///< numpad 0
		KEY_NUMPAD1,	///< numpad 1
		KEY_NUMPAD2,	///< numpad 2
		KEY_NUMPAD3,	///< numpad 3
		KEY_NUMPAD4,	///< numpad 4
		KEY_NUMPAD5,	///< numpad 5
		KEY_NUMPAD6,	///< numpad 6
		KEY_NUMPAD7,	///< numpad 7
		KEY_NUMPAD8,	///< numpad 8
		KEY_NUMPAD9,	///< numpad 9

		KEY_MULTIPLY,	///< numpad "*"
		KEY_DIVIDE,		///< numpad "/"
		KEY_ADD,		///< numpad "+"
		KEY_SUBTRACT,	///< numpad "-"
		KEY_DECIMAL,	///< numpad "."

		KEY_F1,	///< functional key 1
		KEY_F2,	///< functional key 2
		KEY_F3,	///< functional key 3
		KEY_F4,	///< functional key 4
		KEY_F5,	///< functional key 5
		KEY_F6,	///< functional key 6
		KEY_F7,	///< functional key 7
		KEY_F8,	///< functional key 8
		KEY_F9,	///< functional key 9
		KEY_F10,	///< functional key 10
		KEY_F11,	///< functional key 11
		KEY_F12,	///< functional key 12
	
	};

}

#endif /*GHL_KEYS_H*/