#include "framework/World.h"
#include "framework/Actor.h"
//#include "framework/Application.h" while pOwningApp is not used its ok



namespace FromHeLL
{
	World::World( Application* pOwningApp )
		: m_pOwningApp( pOwningApp )
		, m_bBeginPlay( false )
		, m_aActors{}
		, m_aPendingActors{}
	{
	}

	World::~World()
	{
	}

	void World::BeginPlayInternal()
	{
		if( !m_bBeginPlay )
		{
			m_bBeginPlay = true; 
			BeginPlay();
		}
	}

	void World::BeginPlay()
	{
		LOG("World Begin Play");
	}

	void World::TickInternal(float fDeltaTime)
	{
		for( Shared<Actor> pPendingActor  : m_aPendingActors )
		{
			m_aActors.push_back( pPendingActor );
			pPendingActor->BeginPlayInternal();
		}
		m_aPendingActors.clear();

		List<Shared<Actor>>::iterator oIt;
		for( oIt = m_aActors.begin(); oIt != m_aActors.end() ;)
		{
			if( oIt->get()->IsPendingDestroyed() )
			{
				oIt = m_aActors.erase( oIt );
			}
			else
			{
				oIt->get()->Tick( fDeltaTime );
				++oIt;
			}
		} 


		Tick( fDeltaTime );
	}

	void World::Tick( float fDeltaTime )
	{
		//LOG("World Ticking at framerate : %f", 1/fDeltaTime);
	}
}