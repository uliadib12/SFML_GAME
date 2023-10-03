#include <b2_world.h>
#include <b2_math.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <b2_body.h>
#include <b2_polygon_shape.h>
#include <b2_fixture.h>

#include "behaviortree_cpp/action_node.h"
#include "behaviortree_cpp/bt_factory.h"

int main()
{
    // setup width and height
    uint widthScreen = sf::VideoMode::getDesktopMode().width;
    uint heightScreen = sf::VideoMode::getDesktopMode().height;
    uint widthWindow = 500;
    uint heightWindow = 500;

    // setup window
    sf::RenderWindow window(sf::VideoMode(widthWindow, heightWindow), "Pendulum", sf::Style::Close);
    window.setPosition(sf::Vector2i(widthScreen/2 - widthWindow/2, (heightScreen/2 - heightWindow/2)));
    window.setVerticalSyncEnabled(true);
    sf::Clock clock;


    while (window.isOpen())
    {
        float timeElapsed = clock.getElapsedTime().asSeconds();
        clock.restart();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        window.clear();
        window.display();
    }

    return 0;
}