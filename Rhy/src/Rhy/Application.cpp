#include "rpch.h"

#include "Application.h"
#include "Rhy/Events/ApplicationEvent.h"
#include "Rhy/Log.h"

#include "GLFW/glfw3.h"

namespace Rhy
{
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
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
}

