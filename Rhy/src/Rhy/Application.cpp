#include "rpch.h"

#include "Application.h"
#include "Rhy/Events/ApplicationEvent.h"
#include "Rhy/Log.h"

#include "GLFW/glfw3.h"

namespace Rhy
{
#define BIND_EVENT_FUNCTION(x) std::bind(&x, this, std::placeholders::_1)
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FUNCTION(Application::OnEvent));
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		while (m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FUNCTION(Application::OnWindowClose));

		R_CORE_TRACE("{0}", e);
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}
}

