#include "player/PlayerSpaceship.h"
#include <SFML/System.hpp>
#include "framework/MathUtility.h"

namespace FromHeLL
{
	PlayerSpaceship::PlayerSpaceship( World* pOwningWorld, const String& sTexturePath )
		: Spaceship( pOwningWorld, sTexturePath )
		, m_vMoveInput{}
		, m_fSpeed{200.0f}
	{
	}
	void PlayerSpaceship::Tick(float fDeltaTime)
	{
		Spaceship::Tick( fDeltaTime );
		InputHandler();
		ApplyInput( fDeltaTime );
	}
	void PlayerSpaceship::InputHandler()
	{
		
		if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Up ))
		{
			m_vMoveInput.y = -1.0f;
		}
		else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Down ))
		{
			m_vMoveInput.y = 1.0f;
		}

		if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Left ))
		{
			m_vMoveInput.x = -1.0f;
		}
		else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Right ))
		{
			m_vMoveInput.x = 1.0f;
		}
		ClampInputOnEgdge();
		NormalizeInput();
		
	}

	void PlayerSpaceship::ApplyInput(float fDeltaTime)
	{
		
		SetVelocity( m_vMoveInput * GetSpeed() );
		m_vMoveInput.x = m_vMoveInput.y = 0.0f;
	}
	void PlayerSpaceship::NormalizeInput()
	{
		Normalize( m_vMoveInput );
		sf::Vector2<float> fPlayerLoc{ GetActorLocation() };
		LOG("Screen : (%u, %u)", GetWindowSize().x, GetWindowSize().y);
		LOG("Player Loc : (%f, %f)", fPlayerLoc.x, fPlayerLoc.y);
	}
	void PlayerSpaceship::ClampInputOnEgdge()
	{
		sf::Vector2<float> vActorLocation{ GetActorLocation() };

		if( vActorLocation.x < 0.0f && m_vMoveInput.x == -1.0f )
		{
			m_vMoveInput.x = 0.0f;
		}

		if (vActorLocation.x > GetWindowSize().x && m_vMoveInput.x == 1.0f )
		{
			m_vMoveInput.x = 0.0f;
		}

		if ( vActorLocation.y < 0.0f &&  m_vMoveInput.y == - 1.0f )
		{
			m_vMoveInput.y = 0.0f;
		}

		if ( vActorLocation.y > GetWindowSize().y && m_vMoveInput.y == 1.0f )
		{
			m_vMoveInput.y = 0.0f;
		}
	}
}