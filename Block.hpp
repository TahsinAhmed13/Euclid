#pragma once

#include <SFML/Graphics.hpp>

class Block : public sf::Drawable, public sf::Transformable
{
private: 
	int m_size; 
	int m_maxSize; 
	float m_maxHeight; 
	sf::RectangleShape m_boundBox; 
	sf::Text m_sizeText; 

private: 
	void resize(); 

public: 
	Block(int size, int maxSize, float maxHeight, float width); 

	int getSize() const; 
	int getMaxSize() const; 
	float getMaxHeight() const; 
	float getWidth() const; 
	const sf::Vector2f& getPosition() const; 
	const sf::Color& getFillColor() const; 
	const sf::Font* getFont() const; 

	void setSize(int size); 
	void setMaxSize(int maxSize); 
	void setMaxHeight(float maxHeight); 
	void setWidth(float width); 
	void setPosition(const sf::Vector2f& pos); 
	void setFillColor(const sf::Color& color); 
	void setFont(const sf::Font& font); 

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const; 
};
