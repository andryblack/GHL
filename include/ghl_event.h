/*
 GHL - Game Helpers Library
 Copyright (C)  Andrey Kunitsyn 2016
 
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

#ifndef GHL_EVENT_H
#define GHL_EVENT_H

#include "ghl_keys.h"

namespace GHL
{

    /// Event type
    enum EventType {
        EVENT_TYPE_KEY_PRESS,
        EVENT_TYPE_KEY_RELEASE,
        EVENT_TYPE_MOUSE_PRESS,
        EVENT_TYPE_MOUSE_MOVE,
        EVENT_TYPE_MOUSE_RELEASE,
        EVENT_TYPE_ACTIVATE,
        EVENT_TYPE_DEACTIVATE,
        EVENT_TYPE_SOFT_KEYBOARD_SHOW,
        EVENT_TYPE_SOFT_KEYBOARD_HIDE,
    };

    /// Key press
    struct KeyPressEvent {
        Key     key;
        UInt32  charcode;
        UInt32  modificators;
    };

    /// Key release
    struct KeyReleaseEvent {
        Key     key;
    };

    /// Base mouse event
    struct MouseEvent {
        MouseButton button;
        UInt32  modificators;
        Int32   x;
        Int32   y;
    };

    /// Mouse/pointer press event
    struct MousePressEvent : MouseEvent {
        MouseButton button;
    };

    /// Mouse/pointer move event
    struct MouseMoveEvent : MouseEvent {
        MouseButton button;
    };

    /// Mouse/pointer release event
    struct MouseReleaseEvent : MouseEvent {
        MouseButton button;
    };
    
    // Soft Keyboard show
    struct SoftKeyboardShowEvent {
        Int32 x;
        Int32 y;
        Int32 w;
        Int32 h;
    };

    /// Event uninon
    struct Event {
        EventType type;
        union Data {
            KeyPressEvent       key_press;
            KeyReleaseEvent     key_release;
            MousePressEvent     mouse_press;
            MouseMoveEvent      mouse_move;
            MouseReleaseEvent   mouse_release;
            SoftKeyboardShowEvent soft_keyboard_show;
        } data;
    };
    
}

#endif /*GHL_EVENT_H*/