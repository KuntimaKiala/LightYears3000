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
		if ( IsActorOutOfWIndowBounds() )
		{
			Destroy();
		}
	}
	void Bullet::Move( float fDeltaTime )
	{
		SetActorRotation( 270.0f ); 
		AddActorLocationOffset( GetActorForwardDirection() * m_fSpeed * fDeltaTime );
	}
}