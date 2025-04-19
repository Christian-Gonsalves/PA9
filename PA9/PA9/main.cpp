#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


int main() {

	sf::RenderWindow window(sf::VideoMode({ 1280, 720 }), "TA BASH");
	sf::CircleShape circle;
	sf::Vector2f circlePosition(540, 240);
	circle.setFillColor(sf::Color::Blue);
	circle.setPosition(circlePosition);
	circle.setRadius(100);
	sf::SoundBuffer buffer("../Audio/sound3.wav");
	sf::Sound sound(buffer);


	while (window.isOpen())
	{

		while (const std::optional event = window.pollEvent())
		{

			if (event->is<sf::Event::Closed>())
			{
				window.close();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
			{
				sound.play();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
			{

			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))\
			{

			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
			{


			}

			window.clear();
			window.draw(circle);
			window.display();
		}
	}
}