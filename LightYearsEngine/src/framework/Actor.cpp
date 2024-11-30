#include "framework/Actor.h"
#include "framework/Core.h"

namespace FromHeLL
{

	Actor::Actor(World* oOwningWorld, const String& sTexturePath)
		: m_oOwningWorld(oOwningWorld)
		, m_bHasBaganPlay(false)
		, m_oSprite{}
		, m_oTexture{}
	{
		SetTexture(sTexturePath);
	}
	Actor::~Actor()
	{
		LOG("Actor Destroyed");
	}

	void Actor::BeginPlayInternal()
	{
		if (!m_bHasBaganPlay)
		{
			m_bHasBaganPlay = true;
			BeginPlay();
		}
	}

	void Actor::SetTexture( const String& sTexturePath )
	{
		m_oTexture.loadFromFile( sTexturePath );
		m_oSprite.setTexture( m_oTexture );

		int textureWidth  = m_oTexture.getSize().x;
		int textureHeight = m_oTexture.getSize().y;

		m_oSprite.setTextureRect(sf::IntRect{ sf::Vector2i{}, sf::Vector2i{textureWidth, textureHeight} });
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
		LOG("Actor Begin Play");
	}

	void Actor::Tick(float fDeltatime)
	{
		LOG("Actor Ticking");
	}
}