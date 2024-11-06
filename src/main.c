#include "main.h"
#include "modules/ui.h"
#include <raylib.h>

int main(void) {
    // Default Settings
    InitWindow(ScreenWidth, ScreenHeight, GameTitle);
    SetExitKey(KEY_NULL);
    SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT);
    Vector2 MousePosition = {0.0f, 0.0f};

    Font DefaultFont = LoadFont("./Assets/Font/Sans_normal.ttf");
    int CurrentScene = LOGO; 
    float logoTimer  = 2; char TimerLog[64];

    // ui for menu
    Button StartButton = CreateButton ( 
			DefaultFont, 
			30, 
			"Start Game", 
			10, 
			ScreenHeight/2,  
			GPurple5, GPurple3, // Default Button Color
			GPurple3, GPurple5  // If Mouse Enter Button Area color
	);

	Slider Sound = CreateSlider(100, 100, 300, 10, 100, 50);
	// debug example
	char SounVolumeDebug[64];
	sprintf(SounVolumeDebug, "Sound Volume: %d", (int)Sound.IntValue);




    // Default FPS Camera
    cam CAM = GOCAM();


    SetMousePosition(ScreenWidth/2, ScreenHeight/2);
    SetTargetFPS(60); DisableCursor();
    while (!WindowShouldClose()) {
        // Show Cursor or Hide
        if (IsKeyPressed(KEY_ESCAPE) && CAM.SettingsMode) {
            CAM.SettingsMode = false;
            DisableCursor();
        } else if (IsKeyPressed(KEY_ESCAPE) && !CAM.SettingsMode) {
            CAM.SettingsMode = true;
            EnableCursor(); 
        }
        
        // Get Mouse Position
        MousePosition = GetMousePosition();

		// Scenes Update Start In Here!
        if (CurrentScene == LOGO) {
            if (logoTimer > 0) {
                logoTimer -= 1 * GetFrameTime();
                sprintf(TimerLog, "Timer: %f", logoTimer);
            } else {
                logoTimer = 2;
                CurrentScene = MENU;
                CAM.SettingsMode = true;
                EnableCursor();
            }
        } else if (CurrentScene == MENU) {
            PressButton(&StartButton, MousePosition);
            if (StartButton.ButtonPress) {
                CurrentScene = GAMEPLAY;
                CAM.SettingsMode = false;
                DisableCursor();
            }
	




			// Sound Volume Slider Test
			UpdateSlider(&Sound, MousePosition);
			sprintf(SounVolumeDebug, "Sound Volume: %d", (int)Sound.IntValue);

		} else if (CurrentScene == GAMEPLAY) {



        } else if (CurrentScene == END) {



        }


		// Draw Things Here!
        BeginDrawing();
			ClearBackground(GPurple0);	
			if (CurrentScene == LOGO) {
			

			
			} else if (CurrentScene == MENU) {
			




				// test area
				DrawButton(&StartButton, DefaultFont);
				DrawSlider(&Sound);	
			} else if (CurrentScene == GAMEPLAY) {
				BeginMode2D(CAM.GO);
					




				EndMode2D();
			} else if (CurrentScene == END) {
			
			
			
			}
		EndDrawing();
    }


    // unload things
    UnloadFont(DefaultFont);
    UnloadButton(&StartButton);    
	
	// Sound, Image, -> Must be free

    CloseWindow();
    return 0; }
