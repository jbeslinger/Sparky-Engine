#include "src/graphics/window.h"
#include <iostream>

int main()
{
	using namespace sparky;
	using namespace graphics;

	Window window("Hello Window!", 480, 270);
	glClearColor(0.5f, 0.0f, 1.0f, 1.0f);

	// Dumb triangle variables
	float xOrigin = 0.0f;
	float yOrigin = 0.0f;
	float speed = 0.001f;

	while (!window.closed())
	{
		window.clear();

		// Check if mouse button is being pressed
		if (window.isMouseButtonPressed(GLFW_MOUSE_BUTTON_LEFT))
			std::cout << "Left mouse button clicked!" << std::endl;

		// Move the triangle
		if (window.isKeyPressed(GLFW_KEY_RIGHT))
			xOrigin += speed;
		else if (window.isKeyPressed(GLFW_KEY_LEFT))
			xOrigin -= speed;
		else if (window.isKeyPressed(GLFW_KEY_UP))
			yOrigin += speed;
		else if (window.isKeyPressed(GLFW_KEY_DOWN))
			yOrigin -= speed;

		// Draw triangle
		glBegin(GL_TRIANGLES);
		glVertex2f(xOrigin-0.25f, yOrigin-0.25f);
		glVertex2f(xOrigin+0.0f, yOrigin+0.25f);
		glVertex2f(xOrigin+0.25f, yOrigin-0.25f);
		glEnd();

		window.update();
	}

	return 0;
}