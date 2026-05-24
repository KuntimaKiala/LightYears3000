#pragma once
#include <framework/Application.h>

namespace FromHeLL
{
	class Actor;
	class GameApplication : public Application
	{
	public:
		GameApplication();
		virtual ~GameApplication();

		void virtual Tick(float fDeltaTime) override;
	private:
		float m_fCounter;
		Weak<Actor> m_pActorToDestroy;
	};

}