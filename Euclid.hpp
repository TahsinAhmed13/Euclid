#pragma once 

#include <SFML/Graphics.hpp>

#include "Block.hpp"

class Euclid
{
private: 
	sf::RenderWindow m_win; 
	Block m_first; 
	Block m_second; 

private: 
	void refresh(); 
	int step(); 

public: 
	Euclid(const sf::Vector2u& size, int a, int b); 

	const sf::Vector2u& getSize() const; 
	const sf::Font* getFont() const; 

	void setSize(const sf::Vector2u& size); 
	void setFont(const sf::Font& font); 

	int run(); 
};