#ifndef MAINFILE
#define MAINFILE

// Raylib ------------------------------------------
#include <raylib.h>
#include <raymath.h>


// C Headers ----------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "modules/camera.h"

#if defined(PLATFORM_DESKTOP)
    #define GLSL_VERSION            330
#else   // PLATFORM_ANDROID, PLATFORM_WEB
    #define GLSL_VERSION            100
#endif

// Colors --------------------------------------------
#define GPurple0 CLITERAL(Color){   31,  0,  71, 255 } 
#define GPurple1 CLITERAL(Color){   34,  2,  77, 255 } 
#define GPurple2 CLITERAL(Color){   49,  3, 110, 255 } 
#define GPurple3 CLITERAL(Color){   67,  5, 150, 255 } 
#define GPurple4 CLITERAL(Color){   86,  6, 194, 255 } 
#define GPurple5 CLITERAL(Color){  110, 10, 245, 255 }

typedef enum {
    LOGO     = 0,
    MENU     = 1,
    GAMEPLAY = 2,
    END      = 3,
} GameScenes;

#define ScreenWidth  940
#define ScreenHeight 640
#define GameTitle "Game Title Here!"

#endif
