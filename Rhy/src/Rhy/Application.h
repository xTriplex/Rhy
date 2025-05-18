#pragma once

#include "Rhy/Core.h"
#include "Rhy/LayerStack.h"
#include "Rhy/Events/Event.h"

#include "Rhy/Window.h"

namespace Rhy
{
	class WindowCloseEvent;

	class RHY_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& e);
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

	private:
		bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	// To be defined in client.
	Application* CreateApplication();
}


