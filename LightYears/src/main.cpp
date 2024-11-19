#include <iostream>
#include <memory>
#include "framework/Application.h"

int main()
{
	std::unique_ptr< FromHeLL::Application > App = std::make_unique< FromHeLL::Application >(500, 700, "Light Years 3000", 120.0f);
	App->Run();
	
	App.release();
	return 0;
}