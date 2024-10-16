#pragma once
#include "Base.hpp"

#include "Window.hpp"
#include "Nebula/Core/LayerStack.hpp"
#include "Nebula/Events/Event.hpp"
#include "Nebula/Events/ApplicationEvent.hpp"

namespace Nebula {

	class Application
	{
	public:
		Application();
		virtual ~Application() = default;
		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	private:
		static Application* s_Instance;

	};

	// To be defined in CLIENT
	Application* CreateApplication();

}
