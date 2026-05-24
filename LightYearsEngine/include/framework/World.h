#pragma once
#include "framework/Core.h"

namespace FromHeLL
{
	class Application;
	class Actor;
	class World
	{
	public:
		World(Application* pOwningApp);

		virtual ~World();
		void BeginPlayInternal();
		void TickInternal(float fDeltaTime);

		template<typename ActorType> 
		Weak<ActorType> SpanwActor();
	private:
		virtual void BeginPlay();
		virtual void Tick(float fDelta );

		Application* m_pOwningApp;
		bool m_bBeginPlay;
		List<Shared<Actor>> m_aActors;
		List<Shared<Actor>> m_aPendingActors;

	};

	template<typename ActorType>
	inline Weak<ActorType> World::SpanwActor()
	{
		Shared<ActorType> pNewActor{ new ActorType(this) };
		m_aPendingActors.push_back( pNewActor );
		return pNewActor;
	}

}
