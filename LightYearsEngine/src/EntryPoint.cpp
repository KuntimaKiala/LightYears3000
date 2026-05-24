#include <iostream>
#include <memory>
#include "EntryPoint.h"
#include "framework/Application.h"
#include "framework/Core.h"

int main()
{
	std::cout << "App" << std::endl;
	FromHeLL::Unique<FromHeLL::Application> pApp{ GetApplication() };

	pApp->Run();

	return 0;
}