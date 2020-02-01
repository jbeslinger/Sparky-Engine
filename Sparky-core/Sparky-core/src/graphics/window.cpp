#include "window.h"
#include <iostream>

namespace sparky { namespace graphics {

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
		return true;
	}

	// Returns a bool when the window is closed
	bool Window::closed() const
	{
		return glfwWindowShouldClose(m_Window);
	}

	// Checks GLFW poll events
	void Window::update() const
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

} }