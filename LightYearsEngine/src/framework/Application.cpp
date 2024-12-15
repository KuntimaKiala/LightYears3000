#include "framework/Application.h"
#include "framework/Core.h"
#include "framework/World.h"
#include "framework/AssetManager.h"

namespace FromHeLL
{
	Application::Application()
		: m_iWidth(1000)
		, m_iHeight(1000)
		, m_oWindow{sf::VideoMode(m_iWidth, m_iHeight), "FromHeLL", sf::Style::Fullscreen}
		, m_fTargetFPS{60.0f}
		, m_oClock{}
		, m_spCurrentWorld{ nullptr }
		, m_fCleanCycleInterval{2.0f}
		, m_oCleanCycleClock{}
	{
		LOG("Application Created");
	}

	Application::Application(int iWidth, int iHeight, const std::string& sWindowName, sf::Uint32 uStyle, float fFrameRate)
		: m_iWidth(iWidth)
		, m_iHeight(iHeight)
		, m_oWindow{ sf::VideoMode(m_iWidth, m_iHeight), sWindowName, uStyle }
		, m_fTargetFPS{ fFrameRate }
		, m_oClock{}
		, m_spCurrentWorld{nullptr}
		, m_fCleanCycleInterval{ 2.0f }
		, m_oCleanCycleClock{}
	
	{
		LOG("Application Created");
	}

	Application::~Application()
	{
		LOG("Application Destroyed");
	}

	void Application::Tick(float fDeltaTime)
	{

	}

	void Application::Run()
	{
		m_oClock.restart();
		float fAccumulatedTime = 0.0f;
		float fTargetDeltaTime = 1.0f / m_fTargetFPS;

		while ( m_oWindow.isOpen() )
		{

			sf::Event oWindowEvent;
			while ( m_oWindow.pollEvent(oWindowEvent) )
			{
				if ( oWindowEvent.type == sf::Event::EventType::Closed )
				{
					m_oWindow.close();
				}
				else if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Escape ) )
				{
					m_oWindow.close();
				}
			}

			fAccumulatedTime += m_oClock.restart().asSeconds();
			while ( fAccumulatedTime > fTargetDeltaTime )
			{
				fAccumulatedTime -= fTargetDeltaTime;
				TickInternal(fTargetDeltaTime);
				RenderInternal();
			}

		}
	}

	void Application::TickInternal(float fDeltaTime) 
	{
		Tick(fDeltaTime);

		if ( m_spCurrentWorld )
		{
			//m_spCurrentWorld->BeginPlayInternal(); called from  weak< WorldType> Application::Loadworld() check header file
			m_spCurrentWorld->TickInternal( fDeltaTime );
		}
		if ( m_oCleanCycleClock.getElapsedTime().asSeconds() >= m_fCleanCycleInterval )
		{
			m_oCleanCycleClock.restart();
			AssetManager::GetAssetManager().CleanCycle() ;
			if ( m_spCurrentWorld )
			{
				m_spCurrentWorld->CleanCycle();
			}
		}
	}
	void Application::RenderInternal() 
	{
		m_oWindow.clear();

		Render();

		m_oWindow.display();
	}



	void Application::Render()
	{
		/*sf::CircleShape oRect{ 50 };
		oRect.setFillColor(sf::Color::Red);
		oRect.setOrigin(50,50);
		oRect.setPosition(m_oWindow.getSize().x / 2.0f, m_oWindow.getSize().y / 2.0f);
		m_oWindow.draw(oRect);*/

		if (m_spCurrentWorld)
			m_spCurrentWorld->Render( m_oWindow );
	}

}