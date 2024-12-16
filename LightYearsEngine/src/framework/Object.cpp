#include "framework/Object.h"
#include "framework/Core.h"

namespace FromHeLL
{
	Object::Object()
		: m_bIsPendingDestroy{ false }
	{
		
	}

	Object::~Object()
	{
		
	}

	void Object::Destroy()
	{
		m_bIsPendingDestroy = true;
	}
}