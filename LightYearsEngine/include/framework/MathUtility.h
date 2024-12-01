#pragma once 
#include <SFML/Graphics.hpp>


namespace FromHeLL
{
	
	
	sf::Vector2f RotationToVector( float fRotation, bool bDegree = true );
	float DegreesToRadians( float fDegree );
	float RadiansToDegrees( float fRadian );

		

}