#include "src/graphics/window.h"
#include <iostream>

int main()
{
	using namespace sparky;
	using namespace graphics;

	Window window("Hello Window!", 800, 600);
	glClearColor(0.5f, 0.0f, 1.0f, 1.0f);

	while (!window.closed())
	{
		window.clear();
		window.update();
	}

	return 0;
}