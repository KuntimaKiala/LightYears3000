#pragma once 
#include <SFML/System.hpp>
#include "weapon/Shooter.h"

namespace FromHeLL
{
	class BulletShooter : public Shooter
	{
		public:
			BulletShooter( Actor* pOwner, float fCooldownTime = 1.0f );
			virtual ~BulletShooter() = default;
			virtual bool IsOnCooldown() const override ;
			

		private:
			virtual void ShootImplementation() override;
			sf::Clock m_oCooldownClock;
			float m_fCoolDownTime;
	};
}