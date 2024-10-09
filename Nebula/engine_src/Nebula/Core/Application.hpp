#pragma once
#include "Base.hpp"

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
