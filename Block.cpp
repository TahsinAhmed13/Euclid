#include "Block.hpp"

#include <string>

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
	m_boundBox.move(sf::Vector2f(0, heightDiff)); 
	m_boundBox.setOrigin(sf::Vector2f(0, m_boundBox.getSize().y)); 
	// m_sizeText.setString(std::to_string(m_size)); 
	// m_sizeText.move(sf::Vector2f(0, heightDiff)); 
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

const sf::Vector2f& Block::getPosition() const
{
	sf::Vector2f pos = m_boundBox.getPosition(); 
	return sf::Vector2f(pos.x, pos.y + m_boundBox.getSize().y); 
}

const sf::Color& Block::getFillColor() const
{
	return m_boundBox.getFillColor(); 
}

const sf::Font* Block::getFont() const
{
	return m_sizeText.getFont(); 
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
	float height = m_boundBox.getSize().y; 
	m_boundBox.setSize(sf::Vector2f(width, height));
	// TODO: adjust character size
}

void Block::setPosition(const sf::Vector2f& pos)
{
	m_boundBox.setPosition(sf::Vector2f(pos.x, pos.y - m_boundBox.getSize().y)); 
	/*
	m_sizeText.setPosition(sf::Vector2f(pos.x, 
		pos.y - m_boundBox.getSize().y - m_sizeText.getGlobalBounds().height)); 
	*/
}

void Block::setFillColor(const sf::Color& color)
{
	m_boundBox.setFillColor(color); 
}

void Block::setFont(const sf::Font& font)
{
	m_sizeText.setFont(font); 
	// TODO: adjust character size
}

void Block::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_boundBox, states); 
	if(getFont())
		target.draw(m_sizeText, states); 
}
