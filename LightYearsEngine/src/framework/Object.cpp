#include "framework/Object.h"
#include "framework/Core.h"



namespace FromHeLL
{
	Object::Object()
		: m_bPendindDestroy( false )
	{
	}
	Object::~Object()
	{
		LOG("Object Destroyed");
	}
	void Object::Destroy()
	{
		m_bPendindDestroy = true;
	}
}

