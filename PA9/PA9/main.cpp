#include <iostream>
#include "Screen.hpp"
#include "enemyCharacter.hpp"



int main() {
	sf::RenderWindow window(sf::VideoMode({ 1920, 1080 }), "SFML window");
	Screen s;


	s.run(window);
	return 0;
}