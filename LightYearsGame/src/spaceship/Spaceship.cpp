#include "spaceship/Spaceship.h"

namespace FromHeLL
{
	Spaceship::Spaceship( World* pOwningWorld, const String& sTexturePath )
		: Actor( pOwningWorld , sTexturePath )
		, m_vVelocity{0.0f, 0.0f}
	{

	}

	void Spaceship::SetVelocity( sf::Vector2f vNewVelocity )
	{
		m_vVelocity = vNewVelocity;
	}

	void Spaceship::Tick(float fDeltatime)
	{
		Actor::Tick( fDeltatime );
		AddActorLocationLocationOffset( GetVelocity() * fDeltatime );
	}

	Spaceship::~Spaceship()
	{
	}
}