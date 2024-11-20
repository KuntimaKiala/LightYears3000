#include "gameFramework/GameApplication.h"


FromHeLL::Application* GetApplication(int iWidth, int iHeight, const std::string& sWindowName, float fFrameRate)
{
	return new FromHeLL::GameApplication{ iWidth, iHeight, sWindowName, fFrameRate };
}

FromHeLL::Application* GetApplication()
{
	return new FromHeLL::GameApplication{ };
}

namespace FromHeLL
{
	GameApplication::GameApplication()
		: Application()
	{

	}
	GameApplication::GameApplication(int iWidth, int iHeight, const std::string& sWindowName, float fFrameRate)
		: Application(iWidth, iHeight, sWindowName, fFrameRate)
	{

	}


	GameApplication::~GameApplication()
	{

	}
	
}
