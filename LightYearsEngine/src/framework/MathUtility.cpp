#include "framework/MathUtility.h"


namespace FromHeLL
{
	const float PI = 3.14159265358979f;
	sf::Vector2f RotationToVector(float fRotation, bool bDegree /*= true*/)
	{
		if ( bDegree )
		{
			float fRadians = DegreesToRadians( fRotation );
			return sf::Vector2f( std::cos( fRadians ), std::sin( fRadians )  );
		}

		return sf::Vector2f( std::cos( fRotation ), std::sin( fRotation ) );
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
