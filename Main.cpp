#include <SFML/Graphics.hpp>

#include "Block.hpp"

int main()
{
	sf::RenderWindow win (sf::VideoMode(1920, 1080), "Euclid"); 
	Block block(50, 100, 1080, 200); 
	block.setPosition(sf::Vector2f((1920 - 100) / 2, 1080)); 
	block.setFillColor(sf::Color::Red); 

	while (win.isOpen())
	{
		sf::Event event; 
		while (win.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				win.close(); 
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Up && block.getSize() <= 95)
					block.setSize(block.getSize() + 5);
				else if (event.key.code == sf::Keyboard::Down && block.getSize() >= 5)
					block.setSize(block.getSize() - 5); 
			}
		}

		win.clear(sf::Color::White); 
		win.draw(block); 
		win.display(); 
	}
}