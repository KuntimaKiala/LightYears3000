#include "framework/Actor.h"
#include "framework/Core.h"
#include "framework/AssetManager.h"

namespace FromHeLL
{

	Actor::Actor(World* oOwningWorld, const String& sTexturePath)
		: Object() // Not needed since it empty constructer, it will called first regardless
		, m_oOwningWorld(oOwningWorld)
		, m_bHasBaganPlay(false)
		, m_oSprite{}
		, m_spTexture{}
	{
		LOG("Actor Created");
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
		shared <sf::Texture> oTexture = AssetManager::GetAssetManager().LoadTexture( sTexturePath );
		if (!oTexture) return;

		m_oSprite.setTexture( *oTexture );

		int textureWidth  = oTexture->getSize().x;
		int textureHeight = oTexture->getSize().y;

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
		
	}

	void Actor::Tick(float fDeltatime)
	{
		
	}
}