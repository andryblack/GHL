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

	struct Settings {
		UInt32 width;
		UInt32 height;
		bool fullscreen;
        const char* title;
        bool depth;
	};
	
}