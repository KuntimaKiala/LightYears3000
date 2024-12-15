#pragma once 
#include "weapon/BulletShooter.h"
#include <framework/Core.h>
#include "weapon/Bullet.h"
#include "framework/World.h"


namespace FromHeLL
{
		BulletShooter::BulletShooter( Actor* pOwner, float fCooldowTime )
			: Shooter( pOwner )
			, m_oCooldownClock{}
			, m_fCoolDownTime{ fCooldowTime }
		{
		}

		bool BulletShooter::IsOnCooldown() const
		{
			if ( m_oCooldownClock.getElapsedTime().asSeconds() > m_fCoolDownTime )
			{
				return false;
			}
			return true;
		}
		void BulletShooter::ShootImplementation()
		{
			m_oCooldownClock.restart();
			


 			weak<Bullet> spNewBullet = GetOwner()->GetWorld()->SpawnActor<Bullet>(  GetOwner(), "SpaceShooterRedux/PNG/Lasers/laserRed11.png" );
			spNewBullet.lock()->SetActorRotation( 0.0f );

			spNewBullet.lock()->SetActorRotation( GetOwner()->GetActorRotation() );
			spNewBullet.lock()->SetActorLocation( GetOwner()->GetActorLocation() );
			//spNewBullet.lock()->SetActorRotation( GetOwner()->GetActorRotation() + 50.0f);
		}
	
}