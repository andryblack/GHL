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
#include "ghl_types.h"

namespace GHL
{

    /// Event type
    enum EventType {
        EVENT_TYPE_KEY_PRESS,
        EVENT_TYPE_KEY_RELEASE,
        EVENT_TYPE_MOUSE_PRESS,
        EVENT_TYPE_MOUSE_MOVE,
        EVENT_TYPE_MOUSE_RELEASE,
        EVENT_TYPE_WHEEL,
        EVENT_TYPE_ACTIVATE,
        EVENT_TYPE_DEACTIVATE,
        EVENT_TYPE_VISIBLE_RECT_CHANGED,
        EVENT_TYPE_APP_STARTED,
        EVENT_TYPE_HANDLE_URL,
        EVENT_TYPE_KEYBOARD_HIDE,
        EVENT_TYPE_TEXT_INPUT_TEXT_CHANGED,
        EVENT_TYPE_TEXT_INPUT_ACCEPTED,
        EVENT_TYPE_TEXT_INPUT_CLOSED,
        EVENT_TYPE_RELAYOUT,
        EVENT_TYPE_SUSPEND,
        EVENT_TYPE_RESUME,
        EVENT_TYPE_TRIM_MEMORY
    };

    /// Key press
    struct KeyPressEvent {
        Key     key;
        UInt32  charcode;
        UInt32  modificators;
        bool    handled;
    };

    /// Key release
    struct KeyReleaseEvent {
        Key     key;
        UInt32  modificators;
        bool    handled;
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
    
    /// Wheel event
    struct WheelEvent {
        float delta;
    };
    
    // Soft Keyboard show
    struct VisibleRectChanged {
        Int32 x;
        Int32 y;
        Int32 w;
        Int32 h;
    };
    
    // Application Started
    struct AppStartedEvent {
    };
   
    // handle url
    struct HandleUrlEvent {
        const char* url;
    };
    
    // text input changed
    struct TextInputTextChangedEvent {
        const char* text;
        UInt32 cursor_position;
    };
    // text input accepted
    struct TextInputAcceptedEvent : TextInputTextChangedEvent {
        
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
            WheelEvent          wheel;
            VisibleRectChanged  visible_rect_changed;
            AppStartedEvent     app_started;
            HandleUrlEvent      handle_url;
            TextInputTextChangedEvent text_input_text_changed;
            TextInputAcceptedEvent  text_input_accepted;
        } data;
    };
    
}

#endif /*GHL_EVENT_H*/
