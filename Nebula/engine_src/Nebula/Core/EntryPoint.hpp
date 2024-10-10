#pragma once
#include "Nebula/Events/Event.hpp"

#ifdef NB_PLATFORM_WINDOWS
extern Nebula::Application* Nebula::CreateApplication();

int main(int argc, char** argv)
{
	Nebula::Log::Init();
	Nebula::Event::Init();
	auto app = Nebula::CreateApplication();
	app->Run();
	delete app;
}
#endif
