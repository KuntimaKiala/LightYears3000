#pragma once 

#include <iostream>
#include <SFML/Graphics.hpp>

namespace FromHeLL
{
	class Application
	{
		public: 
			Application();
			Application(int iWidth, int iHeight, const std::string& sWindowName, float fFrameRate = 60.0f);
			~Application();

			void Run();

	private :

		virtual void _Tick(float fDeltaTime) const;
		void _TickInternal(float fDeltaTime) const;

		virtual void _Render();
		void _RenderInternal();
		
		
		int m_iWidth;
		int m_iHeight;
		sf::RenderWindow m_oWindow;
		float m_fTargetFPS;
		sf::Clock m_oClock;
		
		
	
	protected :
		
	};
}