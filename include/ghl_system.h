/*
 *  ghl_system.h
 *  SR
 *
 *  Created by Андрей Куницын on 13.02.11.
 *  Copyright 2011 andryblack. All rights reserved.
 *
 */

#ifndef GHL_SYSTEM_H
#define GHL_SYSTEM_H

#include "ghl_api.h"

namespace GHL {

    struct System {
        ///
        virtual void GHL_CALL Exit() = 0;
        ///
        virtual bool GHL_CALL IsFullscreen() const = 0;
        ///
        virtual void GHL_CALL SwitchFullscreen(bool fs) = 0;
        ///
        virtual void GHL_CALL SwapBuffers() = 0;
        ///
        virtual void GHL_CALL ShowKeyboard() = 0;
        ///
        virtual void GHL_CALL HideKeyboard() = 0;
        ///
        virtual UInt32  GHL_CALL GetKeyMods() const = 0;
    };
}

#endif /*GHL_SYSTEM_H*/
