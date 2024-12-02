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
			//Actor() : Object(nullptr, "") {} if needed; 
			Actor() = delete;
			Actor(World* oOwningWorld, const String& sTexturePath = "SpaceShooterRedux/PNG/playerShip2_red.png" );
			void BeginPlayInternal();
			void SetTexture(const String& sTexturePath);
			void Render(sf::RenderWindow& oWindow);
			void TickInternal(float fDeltaTime);
			void SetActorLocation( const sf::Vector2f& vNewLocation );
			void SetActorRotation( float fNewRotation);
			void AddActorLocationLocationOffset( const sf::Vector2f& vOffset );
			void AddActorLocationRotationOffset( float fOffsetAmount );
			const sf::Vector2f& GetActorLocation() const ;
			float GetActorRotation() const;
			sf::Vector2f GetActorForwardDirection() const ;
			sf::Vector2f GetActorRightDirection() const;
			void SetScreenSize( sf::Vector2<float> vScreenSize ) { m_vScreenSize = vScreenSize; }
			sf::Vector2u GetWindowSize() const;
			virtual void BeginPlay();
			virtual void Tick(float fDeltatime);
			virtual ~Actor();
		private :
			void CenterPivot();
			World* m_oOwningWorld;
			bool m_bHasBaganPlay;
			sf::Sprite m_oSprite;
			shared<sf::Texture> m_spTexture;
			sf::Vector2<float> m_vScreenSize;
			
	};


}