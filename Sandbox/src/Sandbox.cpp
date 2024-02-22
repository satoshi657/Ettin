#include "Ettin.h"

class Sandbox : public Ettin::Application
{
public:
	
	Sandbox()
	{

	}
	~Sandbox()
	{

	}
};
Ettin::Application* Ettin::CreateApplication()
{
	return new Sandbox();
}
