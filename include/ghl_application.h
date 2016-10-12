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
    struct Event;

    /// base application interface
    struct Application {
        /// Set system interface
        virtual void GHL_CALL SetSystem( System* sys ) = 0;
        /// Set VFS interface
        virtual void GHL_CALL SetVFS( VFS* vfs ) = 0;
        /// Set renderer interface
        virtual void GHL_CALL SetRender( Render* render ) = 0;
        /// Set image decoder interface
        virtual void GHL_CALL SetImageDecoder( ImageDecoder* decoder ) = 0;
        /// Set sound interface
        virtual void GHL_CALL SetSound( Sound* sound) = 0;
        /// Get game settings
        virtual void GHL_CALL FillSettings( Settings* settings ) = 0;
		/// Load game. called after window created, before first rendered
		virtual bool GHL_CALL Load() = 0;
        /// Unload game, ready for load again
        virtual void GHL_CALL Unload() = 0;
        /// Frame event
        virtual bool GHL_CALL OnFrame( UInt32 usecs ) = 0;
        /// Notify event
        virtual void GHL_CALL OnEvent( Event* event ) = 0;
        /// Release (destroy) application
        virtual void GHL_CALL Release(  ) = 0;
    };



}

/// Entry point
GHL_API int GHL_CALL GHL_StartApplication( GHL::Application* app,int argc, char** argv);

#endif /*GHL_APPLICATION_H*/
