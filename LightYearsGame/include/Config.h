#pragma 
#include <string>


std::string GetResourceDir()
{
#ifdef NDEBUG //release build
	return "assets/"; 
#else 
	return "C:/Users/Kunti/OneDrive/Documents/Udemy/Complete Game Development Series 04/LightYears3000/LightYearsGame/assets/";
#endif
}

