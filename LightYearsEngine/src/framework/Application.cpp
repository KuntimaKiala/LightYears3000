#include "framework/Application.h"


namespace FromHeLL
{
	Application::Application()
		: m_iWidth(1000)
		, m_iHeight(1000)
		, m_oWindow{sf::VideoMode(m_iWidth, m_iHeight), "FromHeLL"}
		, m_fTargetFPS{60.0f}
		, m_oClock{}
	{

	}

	Application::Application(int iWidth, int iHeight, const std::string& sWindowName, float fFrameRate)
		: m_iWidth(iWidth)
		, m_iHeight(iHeight)
		, m_oWindow{ sf::VideoMode(m_iWidth, m_iHeight), sWindowName }
		, m_fTargetFPS{ fFrameRate }
		, m_oClock{}
	
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		m_oClock.restart();
		float fAccumulatedTime = 0.0f;
		float fTargetDeltaTime = 1.0f / m_fTargetFPS;

		while (m_oWindow.isOpen())
		{

			sf::Event oWindowEvent;
			while (m_oWindow.pollEvent(oWindowEvent))
			{
				if (oWindowEvent.type == sf::Event::EventType::Closed)
				{
					m_oWindow.close();
				}
			}

			fAccumulatedTime += m_oClock.restart().asSeconds();
			while ( fAccumulatedTime > fTargetDeltaTime )
			{
				fAccumulatedTime -= fTargetDeltaTime;
				_TickInternal(fTargetDeltaTime);
				_RenderInternal();
			}

		}
	}

	void Application::_Tick(float fDeltaTime) const
	{
		std::cout << "TIcking at framerate :" << 1.0f / fDeltaTime << std::endl;
	}

	

	void Application::_TickInternal(float fDeltaTime) const
	{
		_Tick(fDeltaTime);
	}
	void Application::_RenderInternal() 
	{
		m_oWindow.clear();

		_Render();

		m_oWindow.display();
	}

	void Application::_Render()
	{
		sf::CircleShape oRect{ 50 };
		oRect.setFillColor(sf::Color::Red);
		oRect.setOrigin(50,50);
		oRect.setPosition(m_oWindow.getSize().x / 2.0f, m_oWindow.getSize().y / 2.0f);
		m_oWindow.draw(oRect);
	}
}