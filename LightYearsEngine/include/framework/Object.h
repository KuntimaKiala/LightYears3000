#pragma once 

namespace FromHeLL
{
	class Object
	{
		public :
			Object();
			virtual ~Object();
			void Destroy();
			bool IsPendingDestroy() const { return m_bIsPendingDestroy; }
		private :
			bool m_bIsPendingDestroy;
	};
}