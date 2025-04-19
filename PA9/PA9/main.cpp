#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


int main() {

	sf::RenderWindow window(sf::VideoMode({ 1200, 1200 }),"TA BASH"); 
	//sf::Music music;
	//if (!music.openFromFile("../Audio/sound1.wav"))
		//return -1; // error

	//music.play();


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
			window.display(); 
		}
	}
}