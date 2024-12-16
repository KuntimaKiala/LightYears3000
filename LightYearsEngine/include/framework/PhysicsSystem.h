#pragma once 
#include <box2d/b2_world.h>
#include "framework/Core.h"


namespace FromHeLL
{
	class Actor;
	class PhysicsSystem
	{
		public :
			static PhysicsSystem& Get();
			void Step( float fDeltaTime );
			b2Body* AddListener( Actor* pActorListener );
			float GetPhysicsScale() const { return m_fPhysicsScale; }
		private :
			static unique<PhysicsSystem> m_spPhysicsSystem;
			b2World m_oPhysicsWorld;
			float m_fPhysicsScale;
			int m_iVelocityIteration;
			int m_iPositionIteration;
		protected :
			PhysicsSystem();
			
	};
}