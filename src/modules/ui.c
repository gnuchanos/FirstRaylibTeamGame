#include "ui.h"
#include "../main.h"

// Button
// not in loop create first
Button CreateButton(Font textFont, int TextFontSize, char *text, int X, int Y, Color TextC, Color TextHLC, Color ButtonC, Color ButtonHLC)  {
    Button ThisButton;
	
	// Default VAR
    ThisButton.ButtonPress = false;
    ThisButton.ButtonHighlightTrue = false;
    ThisButton.TextColor = TextC;
    ThisButton.TextHighlightColor = TextHLC;
    ThisButton.ButtonColor = ButtonC;
    ThisButton.ButtonHighlightColor = ButtonHLC;
    ThisButton.TextFontSize = TextFontSize;

    // Don't forget free this
    ThisButton.Text = (char*)malloc((strlen(text) + 1) * sizeof(char));
    if (ThisButton.Text == NULL) {
        printf("Malloc Porblem In -> CreateButton"); 
        exit(0);
    }
    strcpy(ThisButton.Text, text);
 
    // Default Extra Width and Height
    ThisButton.TextWidth  = MeasureTextEx(textFont, text, ThisButton.TextFontSize, 1).x;
    ThisButton.TextHeight = MeasureTextEx(textFont, text, ThisButton.TextFontSize, 1).y;
    
    ThisButton.ButtonSize   = (Rectangle){
		X, 
		Y, 
		ThisButton.TextWidth+20, 
		ThisButton.TextHeight+10};
    
	ThisButton.TextPosition = (Vector2){
        ThisButton.ButtonSize.x+10,
        ThisButton.ButtonSize.y+5
    };

	return ThisButton;
}


// In Draw loop
void DrawButton(Button *ThisButton, Font TextFont) {
    if (ThisButton->ButtonHighlightTrue) {
        DrawRectangle(
                ThisButton->ButtonSize.x, ThisButton->ButtonSize.y, 
                ThisButton->ButtonSize.width, ThisButton->ButtonSize.height, ThisButton->ButtonHighlightColor
        );
        DrawTextEx(TextFont, ThisButton->Text, ThisButton->TextPosition, ThisButton->TextFontSize, 1, ThisButton->TextHighlightColor);
    } else {
        DrawRectangle(
                ThisButton->ButtonSize.x, ThisButton->ButtonSize.y, 
                ThisButton->ButtonSize.width, ThisButton->ButtonSize.height, ThisButton->ButtonColor
        );
        DrawTextEx(TextFont, ThisButton->Text, ThisButton->TextPosition, ThisButton->TextFontSize, 1, ThisButton->TextColor);
   
    }
}

// In While loop
void PressButton(Button *ThisButton, Vector2 MousePosition) {
    ThisButton->ButtonHighlightTrue = false; ThisButton->ButtonPress = false;
    if (CheckCollisionPointRec(MousePosition, ThisButton->ButtonSize)) {
        ThisButton->ButtonHighlightTrue = true;
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            ThisButton->ButtonPress = true;
        }
    }

}

// ın the end
void UnloadButton(Button *ThisButton) {
   if (ThisButton->Text != NULL) {
    printf("INFO: This Button Free Now -> %s | UwU | \n", ThisButton->Text);
    free(ThisButton->Text);
   } else { printf("INFO: Button Text Is NULL"); }
}

// Slider
Slider CreateSlider(float X, float Y, int Width, int Height, float MaxRange, int IntValue) {
	Slider ThisSlider;
	ThisSlider.IntValue = IntValue;
	ThisSlider.MaxRange = (Range){0, MaxRange};
	float Grab = X + (ThisSlider.IntValue * Width/ThisSlider.MaxRange.Ends);

	ThisSlider.SliderLine = (Rectangle){ X, Y, Width, Height };
	ThisSlider.Slider     = (Rectangle){
		Grab,
		ThisSlider.SliderLine.y-ThisSlider.SliderLine.height/2,
		10,
		ThisSlider.SliderLine.height+10
	};
	
	ThisSlider.SliderColor = GPurple5;
	ThisSlider.SliderLineColor = GPurple3;
	ThisSlider.SliderPress = false;
	return ThisSlider;
}

void DrawSlider(Slider *ThisSlider) {
	DrawRectangle(
		ThisSlider->SliderLine.x,     ThisSlider->SliderLine.y,
		ThisSlider->SliderLine.width, ThisSlider->SliderLine.height,
		ThisSlider->SliderLineColor
	);

	DrawRectangle(
		ThisSlider->Slider.x,     ThisSlider->Slider.y,
		ThisSlider->Slider.width, ThisSlider->Slider.height,
		ThisSlider->SliderColor
	);
}

void UpdateSlider(Slider *ThisSlider, Vector2 MousePosition) {
	if (CheckCollisionPointRec(MousePosition, ThisSlider->Slider)) {
		ThisSlider->SliderPress = true;
	}

	if (ThisSlider->SliderPress) {
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
			if (IsKeyDown(KEY_Q) && ThisSlider->IntValue > ThisSlider->MaxRange.Start) {
				ThisSlider->IntValue -= 1;

			} else if (IsKeyDown(KEY_E) && ThisSlider->IntValue < ThisSlider->MaxRange.Ends) {
				ThisSlider->IntValue += 1;
			
			}

			ThisSlider->Slider.x = ThisSlider->SliderLine.x + (ThisSlider->IntValue * ThisSlider->SliderLine.width / ThisSlider->MaxRange.Ends);
			ThisSlider->SliderColor = GPurple3;
			ThisSlider->SliderLineColor = GPurple5;	
		} 
	}
	
	if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
		ThisSlider->SliderPress = false;
		ThisSlider->SliderColor = GPurple5;
		ThisSlider->SliderLineColor = GPurple3;
	}
}



