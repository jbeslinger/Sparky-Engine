#pragma once

#include "buffers/buffer.h"
#include "buffers/indexbuffer.h"
#include "buffers/vertexarray.h"

#include "../math/math.h"

namespace sparky { namespace graphics {

	class Renderable2D
	{
	protected:
		math::vec3 m_Position;
		math::vec2 m_Size;
		math::vec4 m_Color;

		VertexArray* m_VertexArray;
		IndexBuffer* m_IndexBuffer;

	protected:
		Renderable2D(math::vec3 position, math::vec2 size, math::vec4 color)
			: m_Position(position), m_Size(size), m_Color(color)
		{
			m_VertexArray = new VertexArray();
			
			GLfloat vertices[] =
			{
				0,				0,				0,
				0,				position.y,		0,
				position.x,		position.y,		0,
				position.x,		0,				0
			};

			GLfloat colors[] =
			{
				color.x,	color.y,	color.z,	color.w,
				color.x,	color.y,	color.z,	color.w,
				color.x,	color.y,	color.z,	color.w,
				color.x,	color.y,	color.z,	color.w
			};

			m_VertexArray->addBuffer(new Buffer(vertices, 4 * 3, 3), 0);
			m_VertexArray->addBuffer(new Buffer(colors, 4 * 4, 4), 1);

			GLushort indices[] = { 0, 1, 2, 2, 3, 0 };
			m_IndexBuffer = new IndexBuffer(indices, 6);
		}

		virtual ~Renderable2D()
		{
			delete m_VertexArray;
			delete m_IndexBuffer;
		}

		inline const math::vec3& getPosition() const { return m_Position; }
		inline const math::vec2& getSize() const { return m_Size; }
		inline const math::vec4& getColor() const { return m_Color; }
	};

} }