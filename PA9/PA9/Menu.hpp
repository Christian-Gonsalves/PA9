#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <iostream>
#include <string>



using std::cout;
using std::cin;
using std::endl;
using std::string;

#define MAX_NUMBER_OF_ITEMS 3 //max number of items for the menu

//Menu class declaration 
class Menu
{

public:
	//constructors
	Menu(float width, float height);
	~Menu();

	/*
	* @param: a render window from the sfml library
	* @param: a Screen object
	* loads menu to the screen
	* returns: none
	*/
	void load_menu(sf::RenderWindow& window);

	/*
	* @param: a render window from the sfml library
	* @param: a Screen object
	* loads the credits screen
	* returns: none
	*/
	void credits(sf::RenderWindow& window);

	/*
	* @param: a render window from the sfml library
	* draws menu onto window
	* returns: none
	*/
	void draw(sf::RenderWindow& window);

	/*
	* @param: none
	* Moves the menu option up
	* returns: none
	*/
	void MoveUp();

	/*
	* @param: none
	* Moves the menu option down
	* returns: none
	*/
	void MoveDown();

	/*
	* @param: none
	* returns the option that is currently selected on the menu
	* returns: an integer
	*/
	int GetPressedItem() {
		return selectedItemIndex;
	}

private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text* menu;
	sf::SoundBuffer buffer;
};

