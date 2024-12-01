#include "gameFramework/GameApplication.h"
#include <framework/World.h>
#include <framework/Actor.h>
#include "Config.h"

FromHeLL::Application* GetApplication(int iWidth, int iHeight, const std::string& sWindowName, unsigned int uStyle, float fFrameRate)
{
	return new FromHeLL::GameApplication{ iWidth, iHeight, sWindowName, uStyle, fFrameRate };
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
		Loadworld<World>();
	}
	GameApplication::GameApplication(int iWidth, int iHeight, const std::string& sWindowName, unsigned int uStyle, float fFrameRate)
		: Application(iWidth, iHeight, sWindowName, uStyle , fFrameRate)
	{
	
		//fTimer = 0.0f;
		weak<World> oNewWorld =  Loadworld<World>();
		//oNewWorld.lock()->SpawnActor<Actor>();
		pActor = oNewWorld.lock()->SpawnActor<Actor>();
		
		pActor.lock()->SetTexture( GetResourceDir() + "SpaceShooterRedux/PNG/playerShip2_red.png");
		}


	GameApplication::~GameApplication()
	{

	}

	void GameApplication::Tick(float fDeltaTime) 
	{
		fTimer += fDeltaTime;
		if (fTimer > 2.0f)
		{
			if (!pActor.expired())
			{
				pActor.lock()->Destroy();
			}
		}
	}
	
}
