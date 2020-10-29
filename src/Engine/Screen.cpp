#include "Screen.h"

using namespace myengine;

void Screen::SetScreenHeight(int height)
{
	screenHeight = height;
}
void Screen::SetScreenWidth(int width)
{
	screenWidth = width;
}

int Screen::GetScreenHeight()
{
	return screenHeight;
}
int Screen::GetScreenWidth()
{
	return screenWidth;
}

glm::mat4 Screen::GetPerspective()
{
	glm::mat4 perspective = glm::perspective(glm::radians(45.0f), (float)screenHeight / (float)screenWidth, 0.1f, 100.0f);
	return perspective;
}