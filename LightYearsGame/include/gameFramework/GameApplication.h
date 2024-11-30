#pragma once 

#include <framework/Application.h>
#include "framework/Core.h"

namespace FromHeLL
{
	class Actor;
	class GameApplication : public Application
	{
	public:
		
		GameApplication();
		GameApplication(int iWidth, int iHeight, const std::string& sWindowName, sf::Uint32 uStyle, float fFrameRate);
		virtual void Tick(float fDeltaTime)  override ;
		virtual ~GameApplication();
		
	private :	
		weak<Actor> pActor;
		float fTimer = 0.0f;

		
	};
}