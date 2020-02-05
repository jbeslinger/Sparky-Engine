#pragma once

#include "vec3.h"
#include "math_func.h"

namespace sparky { namespace math {

	float toRadians(float degrees);

	// 4x4 Matrix type definition
	struct mat4
	{
		float elements[4 * 4];

		mat4();
		mat4(float diagonal); // Creates a matrix based on main diagonal; https://chortle.ccsu.edu/VectorLessons/vmch13/vmch13_17.html

		static mat4 identity(); // Creates an identity matrix; https://www.varsitytutors.com/hotmath/hotmath_help/topics/identity-matrix
		
		mat4& multiply(const mat4& other);
		friend mat4 operator*(mat4 left, const mat4& right);
		mat4& operator*=(const mat4& other);

		// Projection matrices
		static mat4 orthographic(float left, float right, float top, float bottom, float near, float far); // Creates an orthographic matrix; https://www.scratchapixel.com/lessons/3d-basic-rendering/perspective-and-orthographic-projection-matrix/orthographic-projection-matrix
		static mat4 perspective(float fov, float aspectRatio, float near, float far); // Creates an perspective matrix; https://www.scratchapixel.com/lessons/3d-basic-rendering/perspective-and-orthographic-projection-matrix/opengl-perspective-projection-matrix
		
		// Translation matrices
		static mat4 translation(const vec3& translation);
		static mat4 rotation(float angle, const vec3& axis);
		static mat4 scale(const vec3& scale);
	};

} }