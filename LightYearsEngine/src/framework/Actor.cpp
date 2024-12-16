#include <box2d/b2_body.h>
#include "framework/Actor.h"
#include "framework/AssetManager.h"
#include "framework/MathUtility.h" 
#include "framework/World.h"
#include "framework/PhysicsSystem.h"

namespace FromHeLL
{

	Actor::Actor( World* oOwningWorld, const String& sTexturePath )
		: Object() // Not needed since it empty constructer, it will called first regardless
		, m_pOwningWorld( oOwningWorld )
		, m_sTexturePath( sTexturePath )
		, m_bHasBaganPlay(false)
		, m_oSprite{}
		, m_spTexture{}
		, m_vScreenSize{}
		, m_pPhysicBody{ nullptr }
		, m_bPhysicEnabled{ false }
	{
		
		SetTexture( m_sTexturePath );
		
		
	}
	Actor::~Actor()
	{
		
	}

	void Actor::CenterPivot()
	{
		sf::FloatRect oBound = m_oSprite.getGlobalBounds();
		m_oSprite.setOrigin( oBound.width/2, oBound.height/2 );
	}

	void Actor::BeginPlayInternal()
	{
		if (!m_bHasBaganPlay)
		{
			m_bHasBaganPlay = true;
			BeginPlay();
		}
	}

	sf::Vector2u Actor::GetWindowSize() const
	{
		return m_pOwningWorld->GetWindowSize();
	}

	void Actor::SetTexture( const String& sTexturePath )
	{
		m_spTexture = AssetManager::GetAssetManager().LoadTexture( sTexturePath );
		if (!m_spTexture) return;

		m_oSprite.setTexture( *m_spTexture);

		int textureWidth  = m_spTexture->getSize().x;
		int textureHeight = m_spTexture->getSize().y;

		m_oSprite.setTextureRect(sf::IntRect{ sf::Vector2i{}, sf::Vector2i{textureWidth, textureHeight} });
		CenterPivot();
	}
	void Actor::SetActorLocation(const sf::Vector2f& vNewLocation)
	{
		m_oSprite.setPosition( vNewLocation );
		UpdatePhysicsBodyTransform();
	}

	const sf::Vector2f& Actor::GetActorLocation() const
	{
		return m_oSprite.getPosition();
	}

	void Actor::AddActorLocationOffset(const sf::Vector2f& vOffset)
	{
		SetActorLocation( GetActorLocation() + vOffset );
	}

	
	void Actor::SetActorRotation(float fNewRotation)
	{
		m_oSprite.setRotation( fNewRotation );
		UpdatePhysicsBodyTransform();
	}

	float Actor::GetActorRotation() const
	{
		return m_oSprite.getRotation() ;
	}

	void Actor::AddActorRotationOffset( float fOffsetAmmount)
	{
		SetActorRotation( GetActorRotation() + fOffsetAmmount );
	}
	
	sf::Vector2f Actor::GetActorForwardDirection() const
	{
		return RotationToVector( GetActorRotation() );
	}

	sf::Vector2f Actor::GetActorRightDirection() const
	{
		return RotationToVector( GetActorRotation() + 90.0f );
	}

	sf::FloatRect Actor::GetActorGlobalBounds() const
	{
		return m_oSprite.getGlobalBounds();
	}

	void Actor::Render(sf::RenderWindow& oWindow)
	{
		if ( IsPendingDestroy() )
			return;
		oWindow.draw( m_oSprite );
	}

	void Actor::TickInternal(float fDeltaTime)
	{
		if (!IsPendingDestroy())
		{
			Tick(fDeltaTime);
		}
	}

	void Actor::BeginPlay()
	{
		
	}

	void Actor::Tick( float fDeltatime )
	{
		
	}
	bool Actor::IsActorOutOfWIndowBounds() const
	{
		float fWindowWidth  = GetWorld()->GetWindowSize().x;
		float fWindowHeight = GetWorld()->GetWindowSize().y;
		
		float fActorWidth = GetActorGlobalBounds().width;
		float fActorHeight = GetActorGlobalBounds().height;
		sf::Vector2f fActorPosition = GetActorLocation();

		if ( fActorPosition.x < - fActorWidth )
		{
			return true;
		}
		else if ( fActorPosition.x > fWindowWidth + fActorWidth )
		{
			return true;
		}
		else if ( fActorPosition.y < -fActorHeight )
		{
			return true;
		}
		
		else if ( fActorPosition.x > fWindowHeight + fActorHeight )
		{
			return true;
		}

		return false;

	}
	void Actor::SetEnablePhysics(bool bEnable)
	{
		m_bPhysicEnabled = bEnable;
		if ( m_bPhysicEnabled )
		{
			InitiaizePhysics();
		}
		else
		{
			UnInitiaizePhysics();
		}
	}

	void Actor::OnActorBeginOverLap( Actor* pOtherActor )
	{
		LOG("OverLap");
	}

	void Actor::OnActorEndOverLap( Actor* pOtherActor )
	{
		LOG("End OverLap");
	}

	void Actor::Destroy()
	{
		UnInitiaizePhysics();
		Object::Destroy();
	}

	void Actor::InitiaizePhysics()
	{
		if( !m_pPhysicBody )
		{
			m_pPhysicBody =  PhysicsSystem::Get().AddListener( this );
		}
	}

	void Actor::UnInitiaizePhysics()
	{
		if( m_pPhysicBody )
		{
			PhysicsSystem::Get().RemoveListener( m_pPhysicBody );
			m_pPhysicBody = nullptr;
		}
	}

	void Actor::UpdatePhysicsBodyTransform()
	{
		if( m_pPhysicBody )
		{
			float fPhysicsScale = PhysicsSystem::Get().GetPhysicsScale();
			b2Vec2 vPosition{ GetActorLocation().x * fPhysicsScale, GetActorLocation().y * fPhysicsScale };
			float fRotation = DegreesToRadians( GetActorRotation() );

			m_pPhysicBody->SetTransform( vPosition, fRotation );
		}
	}
}