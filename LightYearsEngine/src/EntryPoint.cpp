#include "EntryPoint.h"
#include "framework/Application.h"

int main()
{

	FromHeLL::Application* app = GetApplication(500, 700, "Light Years 3000");
	app->Run();

	delete app;
	app = nullptr;
	return 0;
}