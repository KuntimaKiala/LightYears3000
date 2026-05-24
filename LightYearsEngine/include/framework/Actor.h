#pragma once 
#include "framework/Object.h"

namespace FromHeLL
{
	class World;
	class Actor : public Object
	{
	public:
		Actor(World* pOwningWorld);
		void BeginPlayInternal();
		virtual void BeginPlay();
		virtual void Tick(float fDeltaTime );
		virtual ~Actor();

	private:
		World* m_pOwningWorld;
		bool m_bHasBeganPlaying;
	};

}