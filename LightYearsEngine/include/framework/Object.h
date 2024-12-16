#pragma once 

namespace FromHeLL
{
	class Object
	{
		public :
			Object();
			virtual ~Object();
			virtual void Destroy();
			bool IsPendingDestroy() const { return m_bIsPendingDestroy; }
		private :
			bool m_bIsPendingDestroy;
	};
}