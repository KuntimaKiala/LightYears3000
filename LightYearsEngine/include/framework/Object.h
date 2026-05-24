#pragma once 



namespace FromHeLL
{
	class Object
	{
	public:
		Object();
		virtual ~Object();
		void Destroy();
		bool IsPendingDestroyed() const { return m_bPendindDestroy; }
	private:
		bool m_bPendindDestroy;
	};

}