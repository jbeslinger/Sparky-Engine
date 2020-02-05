#include "src/graphics/window.h"
#include "src/math/math.h"

int main()
{
	using namespace sparky;
	using namespace graphics;
	using namespace math;

	Window window("GLFW Window!", 480, 270);
	glClearColor(0.5f, 0.0f, 1.0f, 1.0f);

	mat4 position = mat4::translation(vec3(2, 3, 4));
	position *= mat4::identity();
	vec4 column = position.columns[3];
	std::cout << column << std::endl;

	position.elements[12] = 2.0f;

	vec4 c0 = position.columns[3];
	vec4 c1 = position.getColumn(3);
	std::cout << &position.elements[12] << std::endl;
	std::cout << &c1.x << std::endl;

	while (!window.closed())
	{
		window.clear();

		window.update();
	}

	return 0;
}