#pragma once

#include "Core.h"

namespace Rhy
{
	class RHY_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in client.
	Application* CreateApplication();
}


