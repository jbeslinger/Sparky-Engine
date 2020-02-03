#include "src/graphics/window.h"
#include "src/math/vec2.h"
#include <iostream>

int main()
{
	using namespace sparky;
	using namespace graphics;
	using namespace math;

	Window window("Sparky!", 480, 270);
	glClearColor(0.5f, 0.0f, 1.0f, 1.0f);

	vec2 myVector(1.0f, 2.0f);

	std::cout << myVector << std::endl;
	
	while (!window.closed())
	{
		window.clear();

		window.update();
	}

	return 0;
}