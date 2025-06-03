#pragma once

#include "Rhy/Core.h"
#include "Rhy/LayerStack.h"
#include "Rhy/Events/Event.h"

#include "Rhy/Window.h"

namespace Rhy
{
	class ImGuiLayer;
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

		inline Window& GetWindow() { return *m_Window; }
		inline static Application& Get() { return *s_Instance; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

	private:
		static Application* s_Instance;
	};

	// To be defined in client.
	Application* CreateApplication();
}


