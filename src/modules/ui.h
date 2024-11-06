#ifndef UI
#define UI

#include "../main.h"


typedef struct {
    // Text
    char      *Text;
    Vector2   TextPosition;
    int       TextWidth;
    int       TextHeight;
    Color     TextColor;
    Color     TextHighlightColor;
    int       TextFontSize;

    // Rectangle
    Rectangle ButtonSize;
    Color     ButtonColor;
    Color     ButtonHighlightColor;
    bool      ButtonPress;
    bool      ButtonHighlightTrue;
} Button;

Button CreateButton(Font textFont, int TextFontSize, char *text, int X, int Y, Color TextC, Color TextHLC, Color ButtonC, Color ButtonHLC); 
void DrawButton(Button *ThisButton, Font TextFont);
void PressButton(Button *ThisButton, Vector2 MousePosition);
void UnloadButton(Button *ThisButton);

// this is not finish
typedef struct {
    char     *Text;
    Color     TextColor;
    Rectangle Window; 
    Color     WindowColor;
} TextBox;
// this is not finish

typedef struct {
	float Start;
	float Ends;
} Range;

typedef struct {
	Rectangle Slider;
	Color     SliderColor;
	Rectangle SliderLine;
	Color     SliderLineColor;
	Range	  MaxRange;
	int       IntValue;
	bool      SliderPress;

} Slider;

Slider CreateSlider(float X, float Y, int Width, int Height, float MaxRange, int IntValue); 
void DrawSlider(Slider   *ThisSlider);
void UpdateSlider(Slider *ThisSlider, Vector2 MousePosition);


#endif
