#pragma once 

#include <SFML/Graphics.hpp>
#include "framework/Core.h"


namespace FromHeLL
{
	class World;
	class Application
	{
		public: 
			Application();
			Application(int iWidth, int iHeight, const std::string& sWindowName, sf::Uint32 uStyle, float fFrameRate = 60.0f);
			virtual ~Application();
			virtual void Tick(float fDeltaTime) ;
			void Run();

			template <typename WorldType>
			weak< WorldType> Loadworld();

	private :

		
		void TickInternal(float fDeltaTime) ;

		virtual void Render();
		void RenderInternal();
		
		
		int m_iWidth;
		int m_iHeight;
		sf::RenderWindow m_oWindow;

		float m_fTargetFPS;
		sf::Clock m_oClock;
		
		shared<World> m_spCurrentWorld;
		float m_fCleanCycleInterval;
		sf::Clock m_oCleanCycleClock;
	
	protected :
		
	};


	template <typename WorldType>
	weak< WorldType> Application::Loadworld()
	{
		shared<WorldType> spNewWorld{ new WorldType{this} };
		m_spCurrentWorld = spNewWorld;
		m_spCurrentWorld->BeginPlayInternal();
		return spNewWorld;
	}
}