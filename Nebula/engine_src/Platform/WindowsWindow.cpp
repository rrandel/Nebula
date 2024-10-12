#include "nbpch.hpp"
#include "WindowsWindow.hpp"

#include "Nebula/Events/ApplicationEvent.hpp"
#include "Nebula/Events/MouseEvent.hpp"
#include "Nebula/Events/KeyEvent.hpp"

#include <glad/glad.h>

namespace Nebula {

	static bool s_GLFWInitialized = false;

	static void GLFWErrorCallback(int32_t error, const char* description)
	{
		NB_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
	}

	Window* Window::Create(const WindowProps& props)
	{
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		Init(props);
	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	void WindowsWindow::Init(const WindowProps& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		NB_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

		if (!s_GLFWInitialized)
		{
			int32_t success = glfwInit();
			NB_CORE_ASSERT(success, "Could not initialize GLFW!");
			glfwSetErrorCallback(GLFWErrorCallback);
			s_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow(props.Width, props.Height, m_Data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);

		int32_t status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		NB_CORE_ASSERT(status, "Failed to initialize GLAD!");

		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);

		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int32_t width, int32_t height)
			{
				auto& data = *(WindowData*)glfwGetWindowUserPointer(window);
				data.Width = width;
				data.Height = height;
				WindowResizeEvent event(width, height);
				data.EventCallback(event);
			});

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
			{
				auto& data = *(WindowData*)glfwGetWindowUserPointer(window);
				WindowCloseEvent event;
				data.EventCallback(event);
			});

		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int32_t key, int32_t scancode, int32_t action, int32_t mods)
			{
				auto& data = *(WindowData*)glfwGetWindowUserPointer(window);
				switch (action)
				{
				case GLFW_PRESS:
					data.EventCallback(KeyPressedEvent(key, 0));
					break;
				case GLFW_RELEASE:
					data.EventCallback(KeyReleasedEvent(key));
					break;
				case GLFW_REPEAT:
					data.EventCallback(KeyPressedEvent(key, 1));
					break;
				}
			});

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int32_t button, int32_t action, int32_t mods)
			{
				auto& data = *(WindowData*)glfwGetWindowUserPointer(window);
				switch (action)
				{
				case GLFW_PRESS:
					data.EventCallback(MouseButtonPressedEvent(button));
					break;
				case GLFW_RELEASE:
					data.EventCallback(MouseButtonReleasedEvent(button));
					break;
				}
			});

		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset)
			{
				auto& data = *(WindowData*)glfwGetWindowUserPointer(window);
				data.EventCallback(MouseScrolledEvent((float)xOffset, (float)yOffset));
			});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos)
			{
				auto& data = *(WindowData*)glfwGetWindowUserPointer(window);
				data.EventCallback(MouseMovedEvent((float)xPos, (float)yPos));
			});
	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		glfwSwapInterval(enabled ? 1 : 0);
		m_Data.VSync = enabled;
	}

	bool WindowsWindow::IsVSync() const
	{
		return m_Data.VSync;
	}

}
