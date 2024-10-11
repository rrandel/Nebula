#include <Nebula.hpp>

class ExampleLayer : public Nebula::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}
	void OnUpdate() override
	{
		NB_INFO("ExampleLayer::Update");
	}
	void OnEvent(Nebula::Event& event) override
	{
		NB_TRACE("{0}", event);
	}
};

class Sandbox : public Nebula::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{
	}
};
Nebula::Application* Nebula::CreateApplication()
{
	return new Sandbox();
}