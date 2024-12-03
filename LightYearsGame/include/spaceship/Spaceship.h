#pragma once 
#include <framework/Actor.h>
#include <framework/Core.h>

namespace FromHeLL
{
	class Spaceship : public Actor
	{

		public:
			//Spaceship() : Actor(nullptr, "") {} if needed; 
			Spaceship() = delete;
			Spaceship( World* pOwningWorld, const String& sTexturePath = "" );
			void SetVelocity( sf::Vector2f vNewVelocity );
			sf::Vector2f GetVelocity() const { return m_vVelocity; }
			virtual void Shoot() {};
			virtual void Tick( float fDeltatime ) override;
			virtual ~Spaceship();

		private :
				sf::Vector2f m_vVelocity;
			protected :

	};
}
