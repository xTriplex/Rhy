#pragma once
//#include "Application.h"

#ifdef R_PLATFORM_WINDOWS

extern Rhy::Application* Rhy::CreateApplication();

int main(int argc, char** argv)
{
	//printf("Rhy Engine\n");
	int x = 1;
	Rhy::Log::Init();
	R_CORE_WARN("Initialized...");
	R_CRITICAL("Hello. Var={0}", x);
	auto application = Rhy::CreateApplication();
	application->Run();
	delete application;
}
#endif

