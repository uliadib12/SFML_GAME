#pragma once

#include <vector>
#include "GameManager.hpp"
#include "InputHandlerInterface.hpp"
#include "GameObject.hpp"
#include <iostream>

class GameManager;
class InputHandlerInterface;

class Scene{
	public:
		Scene(InputHandlerInterface* inputHandler);
		virtual ~Scene() {};
		virtual void setUp() = 0;
		virtual void update() = 0;
		void setGameManager(GameManager* gameManager);
		GameManager* getGameManager();
		std::vector<GameObject*> gameObjects;
		InputHandlerInterface* inputHandler;

	private:
		GameManager* _gameManager;
};