#include "src/graphics/window.h"
#include "src/math/math.h"
#include <iostream>

int main()
{
	using namespace sparky;
	using namespace graphics;
	using namespace math;

	Window window("Sparky!", 480, 270);
	glClearColor(0.5f, 0.0f, 1.0f, 1.0f);

	vec3 a(3.0f, 3.0f, 3.0f);
	vec3 b(4, 4, 4);

	vec3 c = a + b;

	std::cout << "A = " << a << std::endl;
	std::cout << "B = " << b << std::endl;
	std::cout << "C = " << c << std::endl;

	while (!window.closed())
	{
		window.clear();

		window.update();
	}

	return 0;
}