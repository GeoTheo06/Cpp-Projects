#include <iostream>
#include <Windows.h>

// Function to check if two RGB colors are approximately equal
bool colorsMatch(COLORREF color1, COLORREF color2, int tolerance = 5)
{
	int r1 = GetRValue(color1);
	int g1 = GetGValue(color1);
	int b1 = GetBValue(color1);

	int r2 = GetRValue(color2);
	int g2 = GetGValue(color2);
	int b2 = GetBValue(color2);

	int diffR = abs(r1 - r2);
	int diffG = abs(g1 - g2);
	int diffB = abs(b1 - b2);

	return (diffR <= tolerance && diffG <= tolerance && diffB <= tolerance);
}

// Function to search for a specific color on the screen
void searchForColor(COLORREF targetColor)
{
	HDC hdc = GetDC(NULL);
	RECT screenRect;
	GetClientRect(GetDesktopWindow(), &screenRect);

	for(int x = 0; x < screenRect.right; ++x)
	{
		for(int y = 0; y < screenRect.bottom; ++y)
		{
			COLORREF pixelColor = GetPixel(hdc, x, y);
			if(colorsMatch(pixelColor, targetColor))
			{
				std::cout << "Color found at coordinates: (" << x << ", " << y << ")\n";
			}
		}
	}

	ReleaseDC(NULL, hdc);
}

int main()
{
// Specify the target color you want to search for
	COLORREF targetColor = RGB(0, 0, 0);  // Red color

	// Continuously search for the color in real-time
	while(true)
	{
		searchForColor(targetColor);
	}

	return 0;
}