#pragma once

#include "Scene.hpp"
#include "InputHandlerInterface.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Scene;

class GameManager
{
	public:
		GameManager(sf::RenderWindow* window,Scene* scene, sf::Clock* clock); 
		~GameManager();

		void setScene(Scene* scene);
		void update();

		InputHandlerInterface* getInputHandler();
		Scene* getScene();
		sf::RenderWindow* getWindow();
		sf::Clock* getClock();

	private:
		sf::RenderWindow* _window;
		Scene* _scene;
		InputHandlerInterface* inputHandler;
		sf::Clock* _clock;
		void setUpScene();
		void setUpInputHandler();
};