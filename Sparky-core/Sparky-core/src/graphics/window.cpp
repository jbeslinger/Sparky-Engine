#include "window.h"
#include <iostream>

namespace sparky { namespace graphics {

	bool Window::m_Keys[MAX_KEYS];
	bool Window::m_MouseButtons[MAX_BUTTONS];
	double Window::mx, Window::my; // Mouse X, mouse Y

	void window_resize(GLFWwindow* window, int width, int height);
	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

	// Constructor
	Window::Window(const char *title, int width, int height)
	{
		m_Title = title;
		m_Width = width;
		m_Height = height;
		if (!init())
			glfwTerminate();

		for (int i = 0; i < MAX_KEYS; i++)
		{
			m_Keys[i] = false;
		}
		for (int i = 0; i < MAX_BUTTONS; i++)
		{
			m_MouseButtons[i] = false;
		}
	}

	// Destructor
	Window::~Window()
	{
		glfwTerminate();
	}

	// Trys to open a GLFW window, throws an error to console upon failure
	bool Window::init()
	{
		// Try to initialize GLFW
		if (!glfwInit())
		{
			std::cout << "Failed to initialize GLFW." << std::endl;
			return false;
		}	

		// Try to create a GLFW window
		m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
		if (!m_Window)
		{
			glfwTerminate();
			std::cout << "Failed to create GLFW window." << std::endl;
			return false;
		}
		
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, this);
		glfwSetWindowSizeCallback(m_Window, window_resize);
		glfwSetKeyCallback(m_Window, key_callback);

		// Try to initialize GLEW; MUST BE INIT AFTER GLFW
		if (glewInit() != GLEW_OK)
		{
			std::cout << "Could not initialize GLEW!" << std::endl;
			return false;
		}

		std::cout << "OpenGL " << glGetString(GL_VERSION) << std::endl;

		return true;
	}

	bool Window::isKeyPressed(unsigned int keycode)
	{
		// TODO: Log this as error!
		if (keycode >= MAX_KEYS)
			return false;

		return m_Keys[keycode];
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

	void window_resize(GLFWwindow *window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}

	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		Window* win = (Window*) glfwGetWindowUserPointer(window);
		win->m_Keys[key] = action != GLFW_RELEASE;
	}

} }