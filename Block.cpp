#include <iostream>
#include <string>

#include "Block.hpp"

Block::Block(int size, int maxSize, float maxHeight, float width) :
	m_size(size), 
	m_maxSize(maxSize), 
	m_maxHeight(maxHeight) 
{
	resize(); 
	setWidth(width); 
}

void Block::resize()
{
	float width = m_boundBox.getSize().x; 
	float height = ((float)m_size / m_maxSize) * m_maxHeight; 
	float heightDiff = m_boundBox.getSize().y - height; 
	m_boundBox.setSize(sf::Vector2f(width, height)); 
	m_boundBox.setOrigin(sf::Vector2f(0, height)); 
	m_sizeText.setString(std::to_string(m_size)); 
	adjustText(); 
}

void Block::adjustText()
{
	if (m_sizeText.getFont())
	{
		// desired height depends on the width
		float fontRatio = (0.3 * m_boundBox.getSize().x) / m_sizeText.getGlobalBounds().height;
		float fontSize = fontRatio * m_sizeText.getCharacterSize();
		float startx = m_boundBox.getPosition().x;
		float starty = m_boundBox.getPosition().y - m_boundBox.getSize().y;
		float offsetx = 0;
		m_sizeText.setCharacterSize(fontSize);
		offsetx = (m_boundBox.getSize().x - m_sizeText.getGlobalBounds().width) / 2;
		m_sizeText.setOrigin(sf::Vector2f(0, m_sizeText.getCharacterSize() + 10)); 
		m_sizeText.setPosition(sf::Vector2f(startx + offsetx, starty));
	}
}

int Block::getSize() const
{
	return m_size; 
}

int Block::getMaxSize() const
{
	return m_maxSize; 
}

float Block::getMaxHeight() const
{
	return m_maxHeight; 
}

float Block::getWidth() const
{
	return m_boundBox.getSize().x; 
}

const sf::Color& Block::getFillColor() const
{
	return m_boundBox.getFillColor(); 
}

const sf::Font* Block::getFont() const
{
	return m_sizeText.getFont(); 
}

const sf::Color& Block::getTextColor()
{
	return m_sizeText.getFillColor(); 
}

void Block::setSize(int size)
{
	m_size = size; 
	resize(); 
}

void Block::setMaxSize(int maxSize)
{
	m_maxSize = maxSize; 
	resize(); 
}

void Block::setMaxHeight(float maxHeight)
{
	m_maxHeight = maxHeight; 
	resize(); 
}

void Block::setWidth(float width)
{
	m_boundBox.setSize(sf::Vector2f(width, m_boundBox.getSize().y));
	adjustText(); 
}

void Block::setFillColor(const sf::Color& color)
{
	m_boundBox.setFillColor(color); 
}

void Block::setFont(const sf::Font& font)
{
	m_sizeText.setFont(font); 
	adjustText(); 
}

void Block::setTextColor(const sf::Color& color)
{
	m_sizeText.setFillColor(color); 
}

void Block::rise(int size)
{
	setSize(m_size + size); 
}

void Block::drop(int size)
{
	setSize(m_size - size); 
}

void Block::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform(); 
	target.draw(m_boundBox, states); 
	if(getFont())
		target.draw(m_sizeText, states); 
}
