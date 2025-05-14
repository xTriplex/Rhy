#pragma once
//#include "Application.h"

#ifdef R_PLATFORM_WINDOWS

extern Rhy::Application* Rhy::CreateApplication();

int main(int argc, char** argv)
{
	//printf("Rhy Engine\n");
	auto application = Rhy::CreateApplication();
	application->Run();
	delete application;
}
#endif

