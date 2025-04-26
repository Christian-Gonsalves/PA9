#include "textBox.hpp"

textBox::textBox(const sf::Vector2f& size, const sf::Vector2f& position, sf::Font& font, int characterSize) : text(font), isHighlighted(false)
{
	boxText.setSize(size);
	boxText.setFillColor(sf::Color::Black);
	boxText.setPosition(position);
	boxText.setOutlineColor(sf::Color::White);
	boxText.setOutlineThickness(1.5f);

	text.setCharacterSize(characterSize);
	text.setFillColor(sf::Color::White);
	text.setPosition(sf::Vector2f(position.x, position.y));
}

void textBox::setText(const std::string& text)
{
	this->text.setString(text);

}

void textBox::setPostion(sf::Vector2f& position)
{
	boxText.setPosition(sf::Vector2f(position.x, position.y));
}

void textBox::draw(sf::RenderWindow& window)
{
	window.draw(boxText);
	window.draw(this->text);
}

void textBox::setHighlight(bool highlight)
{
	isHighlighted = highlight;
	if (highlight)
	{
		boxText.setFillColor(sf::Color::Magenta);
	}
	else
	{
		boxText.setFillColor(sf::Color::Black);
	}
}
