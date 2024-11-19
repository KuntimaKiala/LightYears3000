#include "framework/Application.h"


namespace FromHeLL
{
	Application::Application()
		: m_oWindow{sf::VideoMode(1000, 1200), "FromHeLL"}
		, m_fTargetFPS{60.0f}
		, m_oClock{}
	{

	}

	Application::Application(int iWidth, int iHeight, const std::string& sWindowName, float fFrameRate)
		: m_oWindow{ sf::VideoMode(iWidth, iHeight), sWindowName }
		, m_fTargetFPS{ fFrameRate }
		, m_oClock{}
	
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
				_Tick(fTargetDeltaTime);
				Render();
			}

		}
	}

	void Application::_Tick(float fDeltaTime) const
	{
		std::cout << "TIcking at framerate :" << 1.0f / fDeltaTime << std::endl;
	}

	Application::~Application()
	{

	}
	void Application::Render() 
	{

	}
}