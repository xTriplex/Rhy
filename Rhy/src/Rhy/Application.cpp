#include "Application.h"

#include "Rhy/Events/ApplicationEvent.h"
#include "Rhy/Log.h"

namespace Rhy
{
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			R_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			R_TRACE(e);
		}
		while (true);
	}
}

