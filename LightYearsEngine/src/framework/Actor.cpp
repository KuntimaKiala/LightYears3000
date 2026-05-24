#include "framework/Actor.h"
#include "framework/Core.h"
#include "framework/World.h"


namespace FromHeLL
{
	Actor::Actor(World* pOwningWorld)
		: m_pOwningWorld( pOwningWorld )
		, m_bHasBeganPlaying( false )
	{
	}

	Actor::~Actor()
	{
		LOG("Actor Destroyed");
	}

	void Actor::BeginPlayInternal()
	{
		if( !m_bHasBeganPlaying )
		{
			m_bHasBeganPlaying = true;
			BeginPlay();
		}
	}

	void Actor::BeginPlay()
	{
		LOG("Actor Begin Play");
	}

	void Actor::Tick(float fDeltaTime)
	{
		LOG("Actor Ticking at framerate : %f", 1/fDeltaTime);
	}
}