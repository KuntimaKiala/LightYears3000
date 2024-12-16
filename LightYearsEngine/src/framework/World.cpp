#include "framework/World.h"
#include "framework/Core.h"
#include "framework/Actor.h"
#include "framework/Application.h"

namespace FromHeLL
{

	World::World( Application* pOwningApp )
		:m_pOwningApp( pOwningApp )
		,m_bBeganPlay( false )
		,m_aActors{}
		,m_aPendingActors{}
	{
		
	}

	World::~World()
	{
		
	}

	sf::Vector2u World::GetWindowSize() const
	{
		return m_pOwningApp->GetWindowSize();
	}

	void World::BeginPlayInternal()
	{
		if (!m_bBeganPlay)
		{
			m_bBeganPlay = true;
			BeginPlay();
		}
	}

	void World::CleanCycle()
	{
		for ( auto iter = m_aActors.begin(); iter != m_aActors.end(); )
		{
			if (iter->get()->IsPendingDestroy())
			{
				iter = m_aActors.erase(iter);
			}
			else
			{
				++iter;
			}
		}

	}

	void World::BeginPlay()
	{

	}


	void World::TickInternal( float fDeltaTime )
	{

		// auto = List<shared<Actor>>::iterator
		for (shared<Actor> actor : m_aPendingActors)
		{
			m_aActors.push_back(actor);
			actor->BeginPlayInternal();
		}

		m_aPendingActors.clear();

		for ( auto iter = m_aActors.begin(); iter != m_aActors.end(); )
		{
			iter->get()->TickInternal( fDeltaTime );
			++iter;
		}

		
		Tick( fDeltaTime );
	}

	void World::Render( sf::RenderWindow& oWindow )
	{
		for(auto& actor : m_aActors )
		{
			actor->Render( oWindow );
		}
	}

	void World::Tick( float deltaTime )
	{

	}

}