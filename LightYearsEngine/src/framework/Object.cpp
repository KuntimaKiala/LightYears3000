#include "framework/Object.h"
#include "framework/Core.h"

namespace FromHeLL
{
	Object::Object()
		: m_bIsPendingDestroy{false}
	{
	}

	Object::~Object()
	{
		LOG("Object Destroyed");
	}

	void Object::Destroy()
	{
		m_bIsPendingDestroy = true;
	}
}