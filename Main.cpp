#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

#include "Block.hpp"
#include "Main.hpp"

#define WIDTH 1920
#define HEIGHT 1080

int main()
{
	sf::RenderWindow win (sf::VideoMode(WIDTH, HEIGHT), "Euclid"); 
	sf::Font font; 
	sf::Text text; 
	Block block(50, 100, 1080, 500); 

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

	block.setPosition(sf::Vector2f((WIDTH - block.getWidth()) / 2, HEIGHT)); 
	block.setFillColor(sf::Color::Red); 
	block.setFont(font); 
	block.setTextColor(sf::Color::Black); 

	while (win.isOpen())
	{
		sf::Event event; 
		while (win.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				win.close(); 
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Up)
				{
					block.rise(5);
					if (block.getSize() >= block.getMaxSize())
						block.setMaxSize(2 * block.getMaxSize());
				}
				else if (event.key.code == sf::Keyboard::Down && block.getSize() >= 5)
				{
					block.drop(5);
					if (block.getSize() <= block.getMaxSize() / 2)
						block.setMaxSize(block.getMaxSize() / 2);
				}
			}
		}

		win.clear(sf::Color::White); 
		win.draw(block); 
		win.display(); 
	}
	
	return 0; 
}