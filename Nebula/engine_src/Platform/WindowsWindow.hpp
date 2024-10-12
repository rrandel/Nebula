#pragma once

#include "Nebula/Core/Window.hpp"
#include <GLFW/glfw3.h>

namespace Nebula {

	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		inline uint32_t GetWidth() const override { return m_Data.Width; }
		inline uint32_t GetHeight() const override { return m_Data.Height; }

		inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }

		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

		inline virtual void* GetNativeWindow() const override { return m_Window; }

	private:
		void Init(const WindowProps& props);
		void Shutdown();

	private:
		GLFWwindow* m_Window;

		
		struct WindowData
		{
			std::string Title;
			[[maybe_unused]] uint32_t Width; // Suppress warning
			[[maybe_unused]] uint32_t Height; // Suppress warning
			bool VSync;

			EventCallbackFn EventCallback;
		};

		WindowData m_Data;
	};

}
