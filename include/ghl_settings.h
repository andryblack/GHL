/*
 *  winlib_settings.h
 *  SR
 *
 *  Created by Андрей Куницын on 04.02.11.
 *  Copyright 2011 andryblack. All rights reserved.
 *
 */

#include "ghl_types.h"

namespace GHL {

	/// Application settings structure
	struct Settings {
		UInt32 width;		///< width
		UInt32 height;		///< height
		bool fullscreen;	///< fullscreen/windowed state
        const char* title;	///< window title
        bool depth;			///< use depth buffer for rendering
        float   screen_dpi;   ///< indicate dpi
	};
	
}