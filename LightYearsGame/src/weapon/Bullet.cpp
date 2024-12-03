#include "weapon/Bullet.h"


namespace FromHeLL
{
	Bullet::Bullet( World* pOwningWorld, Actor* pOwningActor, const String& sTexturePath, float fSpeed, float fDamage )
		: Actor( pOwningWorld, sTexturePath )
		, m_pActor{ pOwningActor }
		, m_fSpeed{ fSpeed }
		, m_fDamage{ fDamage }
	{
		
	}
	void Bullet::Tick( float fDeltaTime )
	{
		Actor::Tick( fDeltaTime );
		Move( fDeltaTime );
	}
	void Bullet::Move( float fDeltaTime )
	{
		sf::Vector2f f = GetActorForwardDirection();
		AddActorLocationOffset(sf::Vector2f(f.y, -f.x ) * m_fSpeed * fDeltaTime );
	}
}