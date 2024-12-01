#include "framework/MathUtility.h"


namespace FromHeLL
{
	const float PI = 3.1415926535;
	sf::Vector2f RotationToVector(float fRotation, bool bDegree /*= true*/)
	{
		if ( bDegree )
		{
			float fRadians = DegreesToRadians( fRotation );
			return sf::Vector2f( std::cos( fRadians ) , std ::cos( fRadians ) );
		}

		return sf::Vector2f( std::cos(fRotation), std::cos(fRotation) );
	}
	float DegreesToRadians( float fDegree )
	{
		return fDegree * PI/180.0f ;
	}
	float RadiansToDegrees( float fRadian )
	{
		return fRadian * 180.0f / PI;
	}
}
