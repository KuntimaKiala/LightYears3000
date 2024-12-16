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
			

			Actor* pActor = GetOwner();
 			weak<Bullet> spNewBullet = pActor->GetWorld()->SpawnActor<Bullet>( pActor, "SpaceShooterRedux/PNG/Lasers/laserRed11.png" );
			spNewBullet.lock()->SetActorRotation( 0.0f );

			spNewBullet.lock()->SetActorLocation( pActor->GetActorLocation() );
		    spNewBullet.lock()->SetActorRotation( pActor->GetActorRotation() + 270.0f );
		}
	
}