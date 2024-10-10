#pragma once
#include "Base.hpp"
#include "Nebula/Events/Event.hpp"

namespace Nebula {

	class Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}
