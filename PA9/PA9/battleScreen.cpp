#include "BattleScreen.hpp"

BattleScreen::BattleScreen(sf::Texture& bgTex, sf::Texture& andyTex, sf::Texture& playerTex, sf::Font& font)
    : bg(bgTex), exitBattle(false), showDialog(false), andy(andyTex), player(playerTex), pHealthBar(200.f, 20.f), eHealthBar(200.f, 20.f), dialogInit(false),
    /*          size      |     position    | font | charSize*/
    defBox({ 150.f, 50.f }, { 1160.f, 815.f }, font, 24),
    strBox({ 150.f, 50.f }, { 1160.f, 875.f }, font, 24),
    agilBox({ 150.f, 50.f }, { 1160.f, 935.f }, font, 24),
    move1({ 500.f, 100.f }, { 150.f, 800.f }, font, 24),
    move2({ 500.f, 100.f }, { 650.f, 800.f }, font, 24),
    move3({ 500.f, 100.f }, { 150.f, 900.f }, font, 24),
    move4({ 500.f, 100.f }, { 650.f, 900.f }, font, 24),
    dialogBox({ 400.f, 250.f }, { 350.f, 200.f }, font, 24)
{
    //insert data
    defBox.setText(std::string("1. DEF"));
    strBox.setText(std::string("2. STR"));
    agilBox.setText(std::string("3. AGI"));

    move1.setText(std::string("z. Move1"));
    move2.setText(std::string("x. Move2"));
    move3.setText(std::string("c. Move3"));
    move4.setText(std::string("v. Move4"));

    dialogBox.setText(std::string("Andy:\n\nHello, world!"));

    pHealthBar.setPosition(sf::Vector2f(50.f, 50.f));
    eHealthBar.setPosition(sf::Vector2f(50.f, 100.f));
	// set up health bars
	pHealthBar.setPosition(sf::Vector2f(50.f, 50.f));
	eHealthBar.setPosition(sf::Vector2f(50.f, 100.f));
}

void BattleScreen::handleInput(sf::RenderWindow& window)
{
    while (const std::optional<sf::Event> event = window.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
        {
            window.close();
        }
        else if (const auto* keyEvent = event->getIf<sf::Event::KeyPressed>())
        {
            if (keyEvent->code == sf::Keyboard::Key::Escape)
            {
                exitBattle = true;
            }
            else if (showDialog && keyEvent->code == sf::Keyboard::Key::Enter)
            {
                showDialog = false;
                menuState = MenuState::SelectingType;
            }

            else if (!showDialog)
            {
                switch (keyEvent->scancode) {
                case sf::Keyboard::Scancode::Z:
                    selectedMoveIndex = 0;
                    break;
                case sf::Keyboard::Scancode::X:
                    selectedMoveIndex = 1;
                    break;
                case sf::Keyboard::Scancode::C:
                    selectedMoveIndex = 2;
                    break;
                case sf::Keyboard::Scancode::V:
                    selectedMoveIndex = 3;
                    break;
                case sf::Keyboard::Scancode::Numpad1: case sf::Keyboard::Scancode::Num1:
                    selectedTypeIndex = 0;
                    break;
                case sf::Keyboard::Scancode::Numpad2: case sf::Keyboard::Scancode::Num2:
                    selectedTypeIndex = 1;
                    break;
                case sf::Keyboard::Scancode::Numpad3: case sf::Keyboard::Scancode::Num3:
                    selectedTypeIndex = 2;
                    break;
                }
            }
        }
    }
}





void BattleScreen::update()
{
    andy.update();

    if (andy.hasEnteredBattle() && !dialogInit)
    {
        showDialog = true;
        dialogInit = true;
    }

    pHealthBar.update(player.getCurrentHealth(), player.getMaxHealth());
    eHealthBar.update(andy.getCurrentHealth(), andy.getMaxHealth());
}

void BattleScreen::draw(sf::RenderWindow& window)
{
    window.draw(bg);
    andy.draw(window);
    player.drawInBattle(window);
	pHealthBar.draw(window);
	eHealthBar.draw(window);
  
    if (showDialog)
    {
        dialogBox.draw(window);
    }
    if (andy.hasEnteredBattle() && !showDialog)
    {

        defBox.setHighlight(selectedTypeIndex == 0);
        strBox.setHighlight(selectedTypeIndex == 1);
        agilBox.setHighlight(selectedTypeIndex == 2);

        defBox.draw(window);
        strBox.draw(window);
        agilBox.draw(window);

        // if in the SelectingMove state highlight and draw move boxes
        if (menuState == MenuState::SelectingMove)
        {
            move1.setHighlight(selectedMoveIndex == 0);
            move2.setHighlight(selectedMoveIndex == 1);
            move3.setHighlight(selectedMoveIndex == 2);
            move4.setHighlight(selectedMoveIndex == 3);

            move1.draw(window);
            move2.draw(window);
            move3.draw(window);
            move4.draw(window);
        }
    }
}

bool BattleScreen::shouldExitBattle() 
{
    if (exitBattle) {
        exitBattle = false;
        return true;
    }
    else {
        return false;
    }
}
