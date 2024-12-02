#pragma once 
#include <SFML/Graphics.hpp>


namespace FromHeLL
{
	
	
	sf::Vector2f RotationToVector( float fRotation, bool bDegree = true );
	float DegreesToRadians( float fDegree );
	float RadiansToDegrees( float fRadian );

	template<typename T>
	float VectorLenght(const sf::Vector2<T>& vVector )
	{
		return std::sqrt( vVector.x * vVector.x + vVector.y * vVector.y );
	}
	
	template<typename T>
	void ScaleVector(sf::Vector2<T>& vVectorToScale, float fScaleAmount )
	{
		vVectorToScale *= fScaleAmount;
	}

	template<typename T>
	void Normalize(sf::Vector2<T>& vVectorToNormalize)
	{
		float vLenght = VectorLenght<T>( vVectorToNormalize );
		if ( vLenght > 0.0001f ) ScaleVector<T>( vVectorToNormalize, 1.0f/vLenght );
	
	}

}