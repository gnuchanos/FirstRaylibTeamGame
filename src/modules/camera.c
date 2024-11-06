#include "camera.h"
#include "../main.h"

// Simple way to Crate Camera for fps player -------------------------------------------------------
cam GOCAM() {
    cam _;
    _.GO.target   = (Vector2){ 0.0f, 0.0f };
	_.GO.offset   = (Vector2){ ScreenWidth/2.0f, ScreenHeight/2.0f };
	_.GO.rotation = 0.0f;
	_.GO.zoom     = 1.0f;	
    return _; 
}



