#pragma once 
#include "framework/Object.h"
#include "framework/Core.h"
#include <SFML/Graphics.hpp>

namespace FromHeLL
{
	class World;
	class Actor : public Object
	{
		public :
			
			Actor(World* oOwningWorld, const String& sTexturePath = "");
			void BeginPlayInternal();
			void SetTexture(const String& sTexturePath);
			void Render(sf::RenderWindow& oWindow);
			void TickInternal(float fDeltaTime);
			virtual void BeginPlay();
			virtual void Tick(float fDeltatime);
			virtual ~Actor();
		private :
			World* m_oOwningWorld;
			bool m_bHasBaganPlay;
			sf::Sprite m_oSprite;
			shared<sf::Texture> m_spTexture;
			
	};


}