#ifndef __APPLICATION_H__
#define __APPLICATION_H__
#include <SFML/Graphics.hpp>
#include "framework/Core.h"

namespace FromHeLL
{
	class World;
	class Application
	{
	public:
		Application();
		~Application();
		void Run();

		template<typename WorldType>
		Weak<WorldType> LoadWorld();
	private:

		void TickInternal(float fDeltaTime);
		void RenderInternal();
		virtual void Render();
		virtual void Tick(float fDeltaTime);

		sf::RenderWindow m_oRenderWindow;
		float m_fTargetFrameRate;
		sf::Clock m_oTickClock;

		Shared<World> m_pCurrentWorld;
	};

	template<typename WorldType>
	inline Weak<WorldType> Application::LoadWorld()
	{
		Shared<WorldType> pNewWorld{ new WorldType( this ) };
		m_pCurrentWorld = pNewWorld;
		m_pCurrentWorld->BeginPlayInternal();
		return pNewWorld;

	}
}
#endif // !__APPLICATION_H__
