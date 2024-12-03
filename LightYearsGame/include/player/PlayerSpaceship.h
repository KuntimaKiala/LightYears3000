#pragma 
#include "spaceship/Spaceship.h"


namespace FromHeLL
{
	class BulletShooter;
	class PlayerSpaceship : public Spaceship
	{
		public :
			//PlayerSpaceship() : Spaceship(nullptr, "") {} if needed; 
			PlayerSpaceship() = delete;
			PlayerSpaceship( World* pOwningWorld, const String& sTexturePath = "SpaceShooterRedux/PNG/playerShip2_red.png" );
			void SetSPeed( float fNewSpeed ) { m_fSpeed = fNewSpeed; }
			float GetSpeed() const { return m_fSpeed; }
			virtual void Tick( float fDeltaTime ) override ;
			virtual void Shoot() override;
			virtual ~PlayerSpaceship() = default ;
		private :
			void InputHandler();
			void ApplyInput(float fDeltaTime);
			void NormalizeInput();
			void ClampInputOnEgdge();
			sf::Vector2f m_vMoveInput;
			float m_fSpeed;
			unique<BulletShooter> m_spShooter;
		protected :
	};

}