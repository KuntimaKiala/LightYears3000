#pragma once 
#include <box2d/b2_world.h>
#include "framework/Core.h"

namespace FromHeLL
{
	class PhysicsSystem
	{
		public :
			static PhysicsSystem& Get();
		private :
			static unique<PhysicsSystem> m_spPhysicsSystem;
			b2World m_oPhysicsWorld;
			float m_fPhysicsScale;
		protected :
			PhysicsSystem();
			~PhysicsSystem() = default;
	};
}