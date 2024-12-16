#include <box2d/b2_body.h>
#include <box2d/b2_polygon_shape.h>
#include <box2d/b2_fixture.h>
#include "framework/PhysicsSystem.h"
#include "framework/Actor.h"
#include "framework/MathUtility.h"

namespace FromHeLL
{
	unique< PhysicsSystem > PhysicsSystem::m_spPhysicsSystem{ nullptr };
	
	

	PhysicsSystem::PhysicsSystem()
		: m_oPhysicsWorld{ b2Vec2{ 0.0f, 0.0f} }
		, m_fPhysicsScale{0.01f/0.01f}
		, m_iVelocityIteration{8}
		, m_iPositionIteration{3}
	{
	}

	PhysicsSystem& PhysicsSystem::Get()
	{
		if ( !m_spPhysicsSystem )
		{
			m_spPhysicsSystem = std::move( unique< PhysicsSystem >{ new PhysicsSystem } );
		}

		return *m_spPhysicsSystem;
	}

	void PhysicsSystem::Step(float fDeltaTime)
	{
		m_oPhysicsWorld.Step( fDeltaTime, m_iVelocityIteration, m_iPositionIteration );
	}

	b2Body* PhysicsSystem::AddListener( Actor* pActorListener )
	{
		if ( pActorListener->IsPendingDestroy() )
		{
			return nullptr;
		}

		b2BodyDef oBodyDef; 
		oBodyDef.type = b2_dynamicBody;
		oBodyDef.userData.pointer = reinterpret_cast<uintptr_t>( pActorListener );
		oBodyDef.position.Set( pActorListener->GetActorLocation().x * GetPhysicsScale(), pActorListener->GetActorLocation().y * GetPhysicsScale() );
		oBodyDef.angle = DegreesToRadians( pActorListener->GetActorRotation() );

		b2Body* oBody = m_oPhysicsWorld.CreateBody( &oBodyDef );
		
		b2PolygonShape oShape; 
		oShape.SetAsBox( pActorListener->GetActorGlobalBounds().width * GetPhysicsScale()/2.0f, pActorListener->GetActorGlobalBounds().height * GetPhysicsScale()/2.0f );
	
		b2FixtureDef oFixtureDef;
		oFixtureDef.shape = &oShape;
		oFixtureDef.density = 1.0f;
		oFixtureDef.friction = 0.3f;
		oFixtureDef.isSensor = true;

		oBody->CreateFixture( &oFixtureDef );
		return oBody;
	}
}