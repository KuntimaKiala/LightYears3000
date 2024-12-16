#pragma once 
#include <framework/Actor.h>

namespace FromHeLL
{
	class Bullet : public Actor
	{
		public:
			Bullet() = delete;
			Bullet( World* pOwningWorld,  Actor* pOwningActor, const String& sTexturePath, float fSpeed = 300.0f, float fDamage = 10.0f );
			virtual ~Bullet() = default;
			inline void SetSpeed( float fNewSpeed ) { m_fSpeed = fNewSpeed; }
			inline void SetDamage( float fDamage ) { m_fDamage = fDamage; }
			virtual void Tick( float fDeltaTime ) override ;
			virtual void BeginPlay() override;
		private:
			void Move( float fDeltaTime );
			Actor* m_pActor;
			float m_fSpeed;
			float m_fDamage;
	};
}