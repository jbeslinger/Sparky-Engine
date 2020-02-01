#include "window.h"
#include <iostream>

namespace sparky { namespace graphics {

	void windowResize(GLFWwindow* window, int width, int height);

	// Constructor
	Window::Window(const char *title, int width, int height)
	{
		m_Title = title;
		m_Width = width;
		m_Height = height;
		if (!init())
			glfwTerminate();
	}

	// Destructor
	Window::~Window()
	{
		glfwTerminate();
	}

	// Trys to open a GLFW window, throws an error to console upon failure
	bool Window::init()
	{
		if (!glfwInit())
		{
			std::cout << "Failed to initialize GLFW." << std::endl;
			return false;
		}	

		m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
		if (!m_Window)
		{
			glfwTerminate();
			std::cout << "Failed to create GLFW window." << std::endl;
			return false;
		}
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowSizeCallback(m_Window, windowResize);
		return true;
	}

	void Window::clear() const
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	}

	// Checks GLFW poll events
	void Window::update()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	// Returns a bool when the window is closed
	bool Window::closed() const
	{
		return glfwWindowShouldClose(m_Window) == 1;
	}

	void windowResize(GLFWwindow *window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}

} }