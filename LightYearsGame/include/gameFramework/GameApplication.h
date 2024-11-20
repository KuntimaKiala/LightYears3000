#pragma once 
#include <framework/Application.h>



namespace FromHeLL
{
	class GameApplication : public Application
	{
	public:
		
		GameApplication();
		GameApplication(int iWidth, int iHeight, const std::string& sWindowName, float fFrameRate);
		virtual ~GameApplication();
		
	
	};
}