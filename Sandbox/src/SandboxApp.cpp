#include <Zeo.h>

class Sandbox : public Zeo::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Zeo::Application* Zeo::CreateApplication()
{
	return new Sandbox();
}