#pragma once
#include <string>

namespace FromHeLL
{
	class Application;
}

extern FromHeLL::Application* GetApplication(int iWidth, int iHeight, const std::string& sWindowName, float fFrameRate = 60.0f);
extern FromHeLL::Application* GetApplication();