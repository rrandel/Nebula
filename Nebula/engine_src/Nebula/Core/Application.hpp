#pragma once
#include "Base.hpp"

#include "Nebula/Core/LayerStack.hpp"
#include "Nebula/Events/Event.hpp"
#include "Nebula/Events/ApplicationEvent.hpp"

namespace Nebula {

	class Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
	private:
		bool m_Running = true;
		LayerStack m_LayerStack;

	};

	// To be defined in CLIENT
	Application* CreateApplication();

}
