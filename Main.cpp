#include <ctime>
#include <iostream>
#include <random>
#include <string>

#include <SFML/Graphics.hpp>

#include "Euclid.hpp"
#include "Main.hpp"

#define WIDTH 1920
#define HEIGHT 1080

int main()
{
	sf::Font font; 
	std::string fontPath = ASSETS_DIR; 
	fontPath += "Roboto-Regular.ttf"; 
#ifdef _WIN32
	int pos = 0; 
	while ((pos = fontPath.find("/", pos)) != std::string::npos)
		fontPath.replace(pos, 1, "\\"); 
#endif
	if (!font.loadFromFile(fontPath))
	{
		std::cerr << "Cannot load font at " << fontPath << std::endl; 
		return 0; 
	}

	std::default_random_engine randEngine(time(0)); 
	std::uniform_int_distribution<int> dist(1, 200); 

	Euclid euclid(sf::Vector2u(WIDTH, HEIGHT), dist(randEngine), dist(randEngine)); 
	euclid.setFont(font); 
	return euclid.run(); 
}