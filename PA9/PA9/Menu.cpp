#include "Menu.hpp"

Menu::Menu(float width, float height)
{

    if (!font.openFromFile("assets/fonts/Morning.otf"))
    {
        std::cout << "Font file not found!" << std::endl;
    }

    //Creates text for the menu
    this->menu = new sf::Text[MAX_NUMBER_OF_ITEMS]{ sf::Text(font),sf::Text(font), sf::Text(font) };
    menu[0].setFillColor(sf::Color::Yellow);
    menu[0].setCharacterSize(70);
    menu[0].setString("Play");
    menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

    menu[1].setFillColor(sf::Color::White);
    menu[1].setCharacterSize(70);
    menu[1].setString("Credits");
    menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

    menu[2].setFillColor(sf::Color::White);
    menu[2].setCharacterSize(70);
    menu[2].setString("Exit");
    menu[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

    selectedItemIndex = 0;
}

Menu::~Menu()
{

}

void Menu::draw(sf::RenderWindow& window)
{
    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    {
        window.draw(menu[i]);
    }

}

void Menu::MoveUp()
{
    if (selectedItemIndex - 1 >= 0)
    {
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex--;
        menu[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}

void Menu::MoveDown()
{
    if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
    {
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex++;
        menu[selectedItemIndex].setFillColor(sf::Color::Red);

    }
}

void Menu::credits(sf::RenderWindow& window)
{
    sf::Font credits_font;
    if (!credits_font.openFromFile("assets/fonts/28 Days Later.ttf"))
    {
        std::cout << "Font file not found!" << std::endl;
    }
    sf::Text* options = new sf::Text[6]{ sf::Text(credits_font),sf::Text(credits_font), sf::Text(credits_font), sf::Text(credits_font), sf::Text(credits_font), sf::Text(credits_font) };
    sf::Texture texture("assets/loading_screen.jpg");
    sf::Sprite sprite(texture);
    //sprite.setScale({ 3, 3 });

    //creates text for credits screen
    options[0].setFillColor(sf::Color::Yellow);
    options[0].setCharacterSize(150);
    options[0].setString("Credits");
    options[0].setPosition(sf::Vector2f(720, 20));

    options[1].setFillColor(sf::Color::Yellow);
    options[1].setCharacterSize(70);
    options[1].setString("Andres");
    options[1].setPosition(sf::Vector2f(800, 254));

    options[2].setFillColor(sf::Color::Yellow);
    options[2].setCharacterSize(70);
    options[2].setString("Alejandro");
    options[2].setPosition(sf::Vector2f(800, 408));

    options[3].setFillColor(sf::Color::Yellow);
    options[3].setCharacterSize(70);
    options[3].setString("Christian");
    options[3].setPosition(sf::Vector2f(800, 562));

    options[4].setFillColor(sf::Color::Yellow);
    options[4].setCharacterSize(70);
    options[4].setString("Gabe");
    options[4].setPosition(sf::Vector2f(800, 716));

    options[5].setFillColor(sf::Color::Yellow);
    options[5].setCharacterSize(35);
    options[5].setString("Press B to return");
    options[5].setPosition(sf::Vector2f(800, 900));

    //draws credits while the window is unless b is pressed
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {

            if (event->is<sf::Event::Closed>())
                window.close();

            if (const auto* keyPressed = event->getIf<sf::Event::KeyReleased>())
            {
                if (keyPressed->scancode == sf::Keyboard::Scancode::B)
                {
                    return;
                }
            }
        }
        window.clear();
        window.draw(sprite);
        for (int i = 0; i < 6; i++)
        {
            window.draw(options[i]);
        }
        window.display();
    }
}
void Menu::load_menu(sf::RenderWindow& window)
{
    Menu menu(window.getSize().x, window.getSize().y);
    //load texture
    sf::Texture texture("assets/loading_screen.jpg");
    sf::Sprite sprite(texture);
    //sprite.setScale({ 3, 3 });
    //load sound
    this->buffer = sf::SoundBuffer("assets/Audio/sound3.wav");
    sf::Sound sound(this->buffer);
    sound.setLooping(true);
    sound.play();

    //draw menu 
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {

            if (event->is<sf::Event::Closed>())
                window.close();

            if (const auto* keyPressed = event->getIf<sf::Event::KeyReleased>())
            {
                if (keyPressed->scancode == sf::Keyboard::Scancode::Up)
                {
                    menu.MoveUp();
                }

                if (keyPressed->scancode == sf::Keyboard::Scancode::Down)
                {
                    menu.MoveDown();
                }

                if (keyPressed->scancode == sf::Keyboard::Scancode::Enter)
                {
                    if (menu.GetPressedItem() == 0)
                    {
                        sound.stop();
                        return;
                    }
                    else if (menu.GetPressedItem() == 1)
                    {
                     
                        menu.credits(window);

                    }
                    else
                    {
                        window.close();
                    }
                }
            }
        }

        //draws elements onto screen
        window.clear();
        window.draw(sprite);
        menu.draw(window);
        window.display();
    }
}
