#pragma once 
#include <box2d/b2_world.h>
#include "framework/Core.h"


namespace FromHeLL
{
	class Actor;

	class  PhysicsContactListener : public b2ContactListener
	{
			virtual void BeginContact( b2Contact* pContact ) override;
			virtual void EndContact( b2Contact* pContact) override;

	};

	class PhysicsSystem
	{
		public :
			static PhysicsSystem& Get();
			void Step( float fDeltaTime );
			b2Body* AddListener( Actor* pActorListener );
			void RemoveListener( b2Body* pBodyRMListener );
			float GetPhysicsScale() const { return m_fPhysicsScale; }
			static void Reset();
		private :
			void ProcessPendingRemoveListeners();
			static unique<PhysicsSystem> m_spPhysicsSystem;
			b2World m_oPhysicsWorld;
			float m_fPhysicsScale;
			int m_iVelocityIteration;
			int m_iPositionIteration;
			PhysicsContactListener m_oContactListener;
			Set<b2Body* > m_vPendingRemoveListeners;
		protected :
			PhysicsSystem();
			
	};
}