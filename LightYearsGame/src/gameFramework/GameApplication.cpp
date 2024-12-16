#include "gameFramework/GameApplication.h"
#include <framework/World.h>
#include <framework/Actor.h>
#include <player/PlayerSpaceship.h>
#include <framework/AssetManager.h>
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
		, fTimer{ 0.0f }
	{
		Loadworld<World>();
	}
	GameApplication::GameApplication(int iWidth, int iHeight, const std::string& sWindowName, unsigned int uStyle, float fFrameRate)
		: Application(iWidth, iHeight, sWindowName, uStyle , fFrameRate)
		, fTimer{ 0.0f }
	{
	
		AssetManager::GetAssetManager().SetAssetRootDirectory( GetResourceDir() );
		fTimer = 0.0f;
		weak<World> oNewWorld =  Loadworld<World>();
		
		
		/*pActor = oNewWorld.lock()->SpawnActor<Actor>();
		pActor.lock()->SetTexture( GetResourceDir() + "SpaceShooterRedux/PNG/playerShip2_red.png" );
		pActor.lock()->SetActorLocation( sf::Vector2f( iWidth/2.0f, iHeight/2.0f )) ;
		pActor.lock()->SetActorRotation( 45.0f );*/
		
		pActor = oNewWorld.lock()->SpawnActor<PlayerSpaceship>();
		pActor.lock()->SetScreenSize( sf::Vector2f( iHeight, iWidth ));
		pActor.lock()->SetTexture(  "SpaceShooterRedux/PNG/playerShip2_red.png" );
		pActor.lock()->SetActorLocation( sf::Vector2f( iWidth/2.0f, iHeight/2.0f )) ;


		weak<Spaceship> spSpaceShipTest = oNewWorld.lock()->SpawnActor<Spaceship>();
		spSpaceShipTest.lock()->SetScreenSize(sf::Vector2f(iHeight, iWidth));
		spSpaceShipTest.lock()->SetTexture( "SpaceShooterRedux/PNG/playerShip2_red.png" );
		spSpaceShipTest.lock()->SetActorLocation(sf::Vector2f{ 100.0f, 50.0f });
		
		}


	GameApplication::~GameApplication()
	{
		
	}

	void GameApplication::Tick(float fDeltaTime) 
	{
		fTimer += fDeltaTime;
		if (fTimer > 10.0f)
		{
			if (!pActor.expired())
			{
				pActor.lock()->Destroy();
			}
		}
	}
	
}
