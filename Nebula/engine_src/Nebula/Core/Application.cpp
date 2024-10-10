#include "nbpch.hpp"
#include "Application.hpp"

#include "Nebula/Events/ApplicationEvent.hpp"
#include "Nebula/Core/Log.hpp"

namespace Nebula {

	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategory::Application)) {
			NB_TRACE("Event belongs to Application category: {}", e);
		}

		if (e.IsInCategory(EventCategory::Input)) {
			NB_TRACE("Event belongs to Input category: {}", e);
		}

		while (true);
	}

}