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
	}

	void OnEvent(Nebula::Event& event) override
	{
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