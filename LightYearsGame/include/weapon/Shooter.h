#pragma once 


namespace FromHeLL
{
	class Actor;
	class Shooter
	{
		public :
			
			void Shoot(); 
			Actor* GetOwner() const { return m_pOwningActor; }
			virtual ~Shooter() = default;
			virtual bool CanShoot() const { return true;  }
			virtual bool IsOnCooldown() const { return false; }
		protected :
			Shooter() = delete;
			Shooter( Actor* pOwner );
		private :
			virtual void ShootImplementation() = 0;
			Actor* m_pOwningActor;
	};
}