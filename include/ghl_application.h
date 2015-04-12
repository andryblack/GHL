/*
 *  winlib_application.h
 *  SR
 *
 *  Created by Андрей Куницын on 03.02.11.
 *  Copyright 2011 andryblack. All rights reserved.
 *
 */

#ifndef GHL_APPLICATION_H
#define GHL_APPLICATION_H

#include "ghl_api.h"

#include "ghl_types.h"
#include "ghl_keys.h"

namespace GHL {

    struct System;
    struct Render;
    struct VFS;
    struct ImageDecoder;
    struct Sound;
    struct Settings;

    /// base application interface
    struct Application {
        ///
        virtual void GHL_CALL SetSystem( System* sys ) = 0;
        ///
        virtual void GHL_CALL SetVFS( VFS* vfs ) = 0;
        ///
        virtual void GHL_CALL SetRender( Render* render ) = 0;
        ///
        virtual void GHL_CALL SetImageDecoder( ImageDecoder* decoder ) = 0;
        ///
        virtual void GHL_CALL SetSound( Sound* sound) = 0;
        ///
        virtual void GHL_CALL FillSettings( Settings* settings ) = 0;
		/// called after window created, before first rendered
		virtual bool GHL_CALL Load() = 0;
        ///
        virtual bool GHL_CALL OnFrame( UInt32 usecs ) = 0;
        ///
        virtual void GHL_CALL OnKeyDown( Key key ) = 0;
        ///
        virtual void GHL_CALL OnKeyUp( Key key ) = 0;
        ///
        virtual void GHL_CALL OnChar( UInt32 ch ) = 0;
        ///
        virtual void GHL_CALL OnMouseDown( MouseButton btn, Int32 x, Int32 y) = 0;
        ///
        virtual void GHL_CALL OnMouseMove( MouseButton btn, Int32 x, Int32 y) = 0;
        ///
        virtual void GHL_CALL OnMouseUp( MouseButton btn, Int32 x, Int32 y) = 0;
        ///
        virtual void GHL_CALL OnDeactivated() = 0;
        ///
        virtual void GHL_CALL OnActivated() = 0;
        ///
        virtual void GHL_CALL Release(  ) = 0;
    };



}

GHL_API int GHL_CALL GHL_StartApplication( GHL::Application* app,int argc, char** argv);

#endif /*WINLIB_APPLICATION_H*/
