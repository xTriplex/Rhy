#include <Rhy.h>

class ExampleLayer : public Rhy::Layer

{

public:
	ExampleLayer()
		: Layer("Example"){}

	void OnUpdate() override
	{
		R_INFO("ExampleLayer::Update");
	}

	void OnEvent(Rhy::Event& event) override
	{
		R_TRACE("{0}", event);
	}
};

class Sandbox : public Rhy::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Rhy::ImGuiLayer());
	}

	~Sandbox()
	{
		
	}
};

Rhy::Application* Rhy::CreateApplication()
{
	return new Sandbox();
}