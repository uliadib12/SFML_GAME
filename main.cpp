#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "GameManager.hpp"
#include "Scene/Main/MainScene.hpp"
#include "Scene/Main/InputHandler/MainInputHandler.hpp"

#include <iostream>

// set up window
sf::RenderWindow* setUpWindow(uint width, uint height){
    // setup width and height
    uint widthScreen = sf::VideoMode::getDesktopMode().width;
    uint heightScreen = sf::VideoMode::getDesktopMode().height;
    uint widthWindow = width;
    uint heightWindow = height;

    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(widthWindow, heightWindow), "Game", sf::Style::Close);
    window->setPosition(sf::Vector2i(widthScreen/2 - widthWindow/2, (heightScreen/2 - heightWindow/2)));
    window->setVerticalSyncEnabled(true);

    return window;
}

int main()
{
    sf::RenderWindow* window = setUpWindow(1000, 600);
    sf::Clock clock;

    MainInputHandler* inputHandler = new MainInputHandler();
    MainScene* scene = new MainScene(inputHandler);
    GameManager* gameManager = new GameManager(window, scene, &clock);

    while (window->isOpen())
    {
        gameManager->update();

        window->clear();
        window->display();
    }

    return 0;
}