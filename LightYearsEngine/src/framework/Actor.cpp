#include "framework/Actor.h"
#include "framework/Core.h"
#include "framework/AssetManager.h"
#include "framework/MathUtility.h" 
#include "framework/World.h"

namespace FromHeLL
{

	Actor::Actor(World* oOwningWorld, const String& sTexturePath)
		: Object() // Not needed since it empty constructer, it will called first regardless
		, m_oOwningWorld(oOwningWorld)
		, m_bHasBaganPlay(false)
		, m_oSprite{}
		, m_spTexture{}
		, m_vScreenSize{}
	{
		
		SetTexture( sTexturePath );
		LOG("Actor Created");
		
	}
	Actor::~Actor()
	{
		LOG("Actor Destroyed");
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
		return m_oOwningWorld->GetWindowSize();
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
	}

	const sf::Vector2f& Actor::GetActorLocation() const
	{
		return m_oSprite.getPosition();
	}

	void Actor::AddActorLocationLocationOffset(const sf::Vector2f& vOffset)
	{
		SetActorLocation( GetActorLocation() + vOffset );
	}

	
	void Actor::SetActorRotation(float fNewRotation)
	{
		m_oSprite.setRotation( fNewRotation );
	}

	float Actor::GetActorRotation() const
	{
		return m_oSprite.getRotation();
	}

	void Actor::AddActorLocationRotationOffset( float fOffsetAmmount)
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

	void Actor::Tick(float fDeltatime)
	{
		
	}
}