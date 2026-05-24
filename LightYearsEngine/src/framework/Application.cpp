#include <iostream>
#include "framework/Application.h"
#include "framework/Core.h"
#include "frameWork/World.h"

namespace FromHeLL {

    Application::Application()
	    : m_oRenderWindow( sf::VideoMode({ 750u, 900u }), "Light Years 3000")
        , m_fTargetFrameRate(60.0f)
        , m_oTickClock()
        , m_pCurrentWorld(NULL)
    {
    }

    Application::~Application()
    {
    }

    void Application::Run()
    {
        m_oTickClock.restart();
        float fAccumulatedTime = 0.0f;
        float fTargetDeltaTime = 1.0f / m_fTargetFrameRate;

        while( m_oRenderWindow.isOpen() )
        {
            while( const auto oEvent = m_oRenderWindow.pollEvent() )
            {
                if( oEvent && oEvent->is<sf::Event::Closed>() )
                {
                    m_oRenderWindow.close();
                }
            }

            float fFrameDeltaTime = m_oTickClock.restart().asSeconds();
            fAccumulatedTime += fFrameDeltaTime;
        
            while( fAccumulatedTime > fTargetDeltaTime )
            {
                fAccumulatedTime -= fTargetDeltaTime;
                TickInternal( fTargetDeltaTime );
                RenderInternal();
            }
        
            //LOG("Real ticking at framerate : %f", 1.0f / fFrameDeltaTime);
        }
    }

    void Application::TickInternal(float fDeltaTime)
    {
        Tick( fDeltaTime );
        
        if( m_pCurrentWorld )
        {
            m_pCurrentWorld->BeginPlayInternal();
            m_pCurrentWorld->TickInternal( fDeltaTime );
        }

    }

    void Application::Tick(float fDeltaTime)
    {
        //LOG("ticking at framerate : %f", 1.0f / fDeltaTime );
    }

    void Application::RenderInternal()
    {
        m_oRenderWindow.clear();

        Render();

        m_oRenderWindow.display();
    }

    void Application::Render()
    {
        sf::RectangleShape oRect(sf::Vector2f{ 100.0f,100.0f });
        oRect.setFillColor(sf::Color::Green);
        oRect.setOrigin(sf::Vector2f{ 50.0f,50.0f });
        oRect.setPosition(sf::Vector2f{ m_oRenderWindow.getSize().x / 2.0f, m_oRenderWindow.getSize().y / 2.0f });

        m_oRenderWindow.draw(oRect);
    }
}


