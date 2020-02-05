#include "shader.h"

namespace sparky { namespace graphics {

	Shader::Shader(const char* vertPath, const char* fragPath)
		: m_VertPath(vertPath), m_FragPath(fragPath)
	{
		m_ShaderID = load();
	}

	GLuint Shader::load()
	{
		GLuint program = glCreateProgram(); // Used to put all shaders into one program
		GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
		GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);

		const char* vertSource = read_file(m_VertPath).c_str();
		const char* fragSource = read_file(m_FragPath).c_str();

		// Compile the vertex shader & check to see if the vertex shader loaded properly
		glShaderSource(vertex, 1, &vertSource, NULL);
		glCompileShader(vertex);

		GLint result;
		glGetShaderiv(vertex, GL_COMPILE_STATUS, &result);
		if (result == GL_FALSE)
		{
			GLint length;
			glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &length);
			std::vector<char> error(length);
			glGetShaderInfoLog(vertex, length, &length, &error[0]);
			std::cout << "Failed to compile vertex shader!" << std::endl << &error[0] << std::endl;
			glDeleteShader(vertex);
			return 0;
		}

		// Compile the vertex shader & check to see if the vertex shader loaded properly

		glShaderSource(fragment, 1, &fragSource, NULL);
		glCompileShader(fragment);

		GLint result;
		glGetShaderiv(fragment, GL_COMPILE_STATUS, &result);
		if (result == GL_FALSE)
		{
			GLint length;
			glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &length);
			std::vector<char> error(length);
			glGetShaderInfoLog(fragment, length, &length, &error[0]);
			std::cout << "Failed to compile fragment shader!" << std::endl << &error[0] << std::endl;
			glDeleteShader(fragment);
			return 0;
		}

		glAttachShader(program, vertex);
		glAttachShader(program, fragment);
		glLinkProgram(program);
		glValidateProgram(program);

		glDeleteShader(vertex);
		glDeleteShader(fragment);

		return program;
	}

} }