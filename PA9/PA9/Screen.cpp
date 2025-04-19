#include "Screen.hpp"
#include <SFML/Window/Event.hpp>

Screen::Screen()
    : bg1Texture("assets/lvlSelectBackgroundPxl.png"),
    bg1Sprite(bg1Texture)
{
}

bool Screen::loadAssets()
{
    bg1Texture = sf::Texture("assets/lvlSelectBackgroundPxl.png");

    bg1Sprite = sf::Sprite(bg1Texture);
    return true;
}

void Screen::run(sf::RenderWindow& window)
{
    //sf::Event event;
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();
        window.draw(bg1Sprite);
        window.display();
    }
}