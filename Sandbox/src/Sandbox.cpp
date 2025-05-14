#include <Rhy.h>

class Sandbox : public Rhy::Application
{
public:
	Sandbox()
	{
		
	}

	~Sandbox()
	{
		
	}
};

Rhy::Application* Rhy::CreateApplication()
{
	return new Sandbox();
}