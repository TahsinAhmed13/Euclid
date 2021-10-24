#include <SFML/Graphics.hpp>

#include "Euclid.hpp"

Euclid::Euclid(const sf::Vector2u& size, int a, int b) :
	m_win(sf::VideoMode(size.x, size.y), "Euclid"),
	m_first(a, std::max(a, b), 0, 0), 
	m_second(b, std::max(a, b), 0, 0)
{
	setSize(size); 
	// default colors
	m_first.setFillColor(sf::Color::Red); 
	m_second.setFillColor(sf::Color::Blue); 
	m_first.setTextColor(sf::Color::Black); 
	m_second.setTextColor(sf::Color::Black); 
}

const sf::Vector2u& Euclid::getSize() const
{
	return m_win.getSize(); 
}

const sf::Font* Euclid::getFont() const
{
	return m_first.getFont(); 
}

void Euclid::setSize(const sf::Vector2u& size)
{
	float maxHeight = 0.8 * size.y; 
	float width = 0.2 * size.x; 
	m_win.setSize(size); 
	m_first.setMaxHeight(maxHeight); 
	m_second.setMaxHeight(maxHeight); 
	m_first.setWidth(width); 
	m_second.setWidth(width); 
	m_first.setPosition(sf::Vector2f(width, size.y)); 
	m_second.setPosition(sf::Vector2f(size.x - 2 * width, size.y));
}

void Euclid::setFont(const sf::Font& font)
{
	m_first.setFont(font); 
	m_second.setFont(font); 
}

void Euclid::refresh()
{
	m_win.clear(sf::Color::White); 
	m_win.draw(m_first); 
	m_win.draw(m_second); 
	m_win.display(); 
}

int Euclid::step()
{
	int a = m_first.getSize(); 
	int b = m_second.getSize(); 
	
	if (a == 0 || b == 0)
		return 1; 
	else if (a > b)
		m_first.drop(b);
	else
		m_second.drop(a); 
	return 0; 
}

int Euclid::run()
{
	while (m_win.isOpen())
	{
		sf::Event event; 
		while (m_win.pollEvent(event))
		{
			switch (event.type)
			{
				case sf::Event::Closed: 
					m_win.close(); 
					break; 
				case sf::Event::Resized: 
					setSize(sf::Vector2u(event.size.width, event.size.height)); 
					break; 
			}
		}

		// TODO: add timer
		// step(); 
		refresh(); 
	}
	return 0; 
}