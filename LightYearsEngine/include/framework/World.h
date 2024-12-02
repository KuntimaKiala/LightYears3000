#pragma once 
#include <SFML/Graphics.hpp>

#include "framework/Core.h"

namespace FromHeLL
{
	class Application;
	class Actor;
	class World
	{
		public :
			World(Application* pOwningApp);
			virtual ~World();
			void BeginPlayInternal();
			void TickInternal(float deltaTime);
			void Render(sf::RenderWindow& oWindow);
			sf::Vector2u GetWindowSize() const;
			template<typename ActorType> 
			weak<ActorType> SpawnActor();
		

		private :
			void BeginPlay();
			void Tick(float deltaTime);
			Application* m_pOwningApp;
			bool m_bBeganPlay;
			List <shared<Actor>> m_aActors;
			List <shared<Actor>> m_aPendingActors;
			
	};

	template<typename ActorType>
	weak<ActorType> World::SpawnActor() 
	{
		shared <ActorType> oNewActor{ new ActorType{ this } };
		m_aPendingActors.push_back(oNewActor);
		return oNewActor;
	}

}