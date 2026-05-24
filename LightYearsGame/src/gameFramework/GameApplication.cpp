#include "gameFramework/GameApplication.h"
#include "framework/Actor.h"
#include "framework/World.h"

FromHeLL::Application* GetApplication()
{
	return new FromHeLL::GameApplication();
}

namespace FromHeLL
{
	GameApplication::GameApplication()
	{
		Weak<World> pNewWorld = LoadWorld<World>() ;
		pNewWorld.lock()->SpanwActor<Actor>();
		m_pActorToDestroy =  pNewWorld.lock()->SpanwActor<Actor>();
		m_fCounter = 0.0f;
	}

	GameApplication::~GameApplication()
	{
	}

	void GameApplication::Tick(float fDeltaTime)
	{
		m_fCounter += fDeltaTime;
		if( m_fCounter > 2.0f )
		{
			if( !m_pActorToDestroy.expired() )
			{
				m_pActorToDestroy.lock()->Destroy();
			}
		}
	}
}

