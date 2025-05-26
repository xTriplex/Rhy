#include <Rhy.h>

#include "Rhy/Events/KeyEvent.h"

class ExampleLayer : public Rhy::Layer

{

public:
	ExampleLayer()
		: Layer("Example"){}

	void OnUpdate() override
	{
		// R_INFO("ExampleLayer::Update");
		if (Rhy::Input::IsKeyPressed(R_KEY_TAB))
		{
			R_TRACE("Tab key was pressed!");
		}
	}

	void OnEvent(Rhy::Event& event) override
	{
		if (event.GetEventType() == Rhy::EventType::KeyPressed)
		{
			Rhy::KeyPressedEvent& e = (Rhy::KeyPressedEvent&)event;
			R_TRACE("{0}", (char)e.GetKeyCode());
		}
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