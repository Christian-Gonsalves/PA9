#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstring>

class textBox
{
public:
	textBox(const sf::Vector2f& size, const sf::Vector2f& position, sf::Font& font, int characterSize = 24);

	void setText(const std::string& text);
	void setPostion(sf::Vector2f& position);
	void draw(sf::RenderWindow& window);
	void setHighlight(bool highlight);


private:
	sf::RectangleShape boxText;
	sf::Text text;
	bool isHighlighted;

};