#include <iostream> 
#include <SFML/Graphics.hpp>


int main() 
{
    sf::RenderWindow oRenderWindow(sf::VideoMode({ 100u, 100u }), "Window");

    std::cout << "The Obligatory Hello World" << std::endl;
    return 0;
}