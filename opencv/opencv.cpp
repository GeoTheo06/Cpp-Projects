#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <Windows.h>

cv::Vec3b getRGBatCursor(const cv::Mat& image, const cv::Point& cursorPos)
{
	if(cursorPos.x >= 0 && cursorPos.x < image.cols && cursorPos.y >= 0 && cursorPos.y < image.rows)
	{
		cv::Vec3b rgbColor = image.at<cv::Vec3b>(cursorPos);
		return rgbColor;
	}
	else
	{
		std::cerr << "Cursor position is outside the image boundaries!" << std::endl;
		return cv::Vec3b(0, 0, 0);
	}
}
int main()
{
// Get the screen dimensions
	int screen_width = GetSystemMetrics(SM_CXSCREEN);
	int screen_height = GetSystemMetrics(SM_CYSCREEN);

	while(true)
	{
	// Create a device context for the entire screen
		HDC screen_dc = GetDC(NULL);

		// Create a compatible device context
		HDC mem_dc = CreateCompatibleDC(screen_dc);

		// Create a bitmap compatible with the screen
		HBITMAP bitmap = CreateCompatibleBitmap(screen_dc, screen_width, screen_height);

		// Select the bitmap into the compatible device context
		SelectObject(mem_dc, bitmap);

		// Copy the screen contents into the compatible device context
		BitBlt(mem_dc, 0, 0, screen_width, screen_height, screen_dc, 0, 0, SRCCOPY);

		// Create an OpenCV Mat object to store the screenshot
		cv::Mat screenshot(screen_height, screen_width, CV_8UC4);

		// Copy the contents of the compatible device context into the Mat object
		GetBitmapBits(bitmap, screen_width * screen_height * 4, screenshot.data);

		// Release the resources
		DeleteObject(bitmap);
		DeleteDC(mem_dc);
		ReleaseDC(NULL, screen_dc);

		// Save the screenshot as an image
		cv::imwrite("C:/Users/THEOD/Desktop/captures/screenshot.png", screenshot);

		std::cout << "Screenshot saved successfully." << std::endl;


		 // Read the image
		cv::Mat image = cv::imread("C:/Users/THEOD/Desktop/captures/screenshot.png", cv::ImreadModes::IMREAD_COLOR);

		// Capture the cursor position
		POINT cursorPos;
		if(GetCursorPos(&cursorPos))
		{
// Convert cursor position to OpenCV's Point format
			cv::Point cvCursorPos(cursorPos.x, cursorPos.y);

			// Get the RGB color at the cursor location
			cv::Vec3b rgbColor = getRGBatCursor(image, cvCursorPos);

			std::cout << "RGB color at cursor location: "
				<< "R = " << static_cast<int>(rgbColor[2]) << ", "
				<< "G = " << static_cast<int>(rgbColor[1]) << ", "
				<< "B = " << static_cast<int>(rgbColor[0]) << std::endl;
		}
		else
		{
			std::cerr << "Failed to get cursor position!" << std::endl;
			return -1;
		}
	}
}