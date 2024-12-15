#include "framework/PhysicsSystem.h"


namespace FromHeLL
{
	unique< PhysicsSystem > PhysicsSystem::m_spPhysicsSystem{ nullptr };
	
	

	PhysicsSystem::PhysicsSystem()
		: m_oPhysicsWorld{ b2Vec2{ 0.0f, 0.0f} }
		, m_fPhysicsScale{0.01f}
	{
	}

	PhysicsSystem& PhysicsSystem::Get()
	{
		if (!m_spPhysicsSystem)
		{
			m_spPhysicsSystem = std::move(unique< PhysicsSystem >{ new PhysicsSystem });
		}

		return *m_spPhysicsSystem;
	}
}