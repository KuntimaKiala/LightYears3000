#pragma once 
#include "weapon/Shooter.h"

namespace FromHeLL
{
	Shooter::Shooter( Actor* pOwner )
		: m_pOwningActor{ pOwner }
	{

	}


	void Shooter::Shoot()
	{
		if ( CanShoot() && !IsOnCooldown() )
			ShootImplementation();
	}
	
}