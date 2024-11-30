#include "EntryPoint.h"
#include "framework/Application.h"

int main()
{

	FromHeLL::Application* app = GetApplication( 500, 700, "Light Years 3000", sf::Style::Titlebar | sf::Style::Close, 30.0f);
	app->Run();

	delete app;
	app = nullptr;
	return 0;
}