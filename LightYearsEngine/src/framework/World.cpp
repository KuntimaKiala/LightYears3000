#include "framework/World.h"
#include "framework/Core.h"
#include "framework/Actor.h"

namespace FromHeLL
{

	World::World(Application* pOwningApp)
		:m_pOwningApp(pOwningApp)
		,m_bBeganPlay(false)
		,m_aActors{}
		,m_aPendingActors{}

	{
		LOG("World Created");
	}

	World::~World()
	{
		LOG("World Destroyed");
	}
	void World::BeginPlayInternal()
	{
		if (!m_bBeganPlay)
		{
			m_bBeganPlay = true;
			BeginPlay();
		}
	}

	void World::BeginPlay()
	{

	}


	void World::TickInternal( float deltaTime )
	{
		for ( shared<Actor> actor : m_aPendingActors )
		{
			m_aActors.push_back( actor );
			actor->BeginPlayInternal();
		}

	
		// auto = List<shared<Actor>>::iterator
		for ( auto iter = m_aActors.begin(); iter != m_aActors.end(); )
		{
			if (iter->get()->IsPendingDestroy())
			{
				iter = m_aActors.erase(iter);
			}
			else
			{
				iter->get()->TickInternal(deltaTime);
				++iter;
			}
		}
	
		m_aPendingActors.clear();
		Tick(deltaTime);
	}

	void World::Render( sf::RenderWindow& oWindow )
	{
		for(auto& actor : m_aActors )
		{
			actor->Render( oWindow );
		}
	}

	void World::Tick(float deltaTime)
	{

	}

}