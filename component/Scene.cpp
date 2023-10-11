#include "Scene.hpp"

Scene::Scene(InputHandlerInterface* inputHandler) : inputHandler(inputHandler) {};

void Scene::setGameManager(GameManager* gameManager) {
	this->_gameManager = gameManager;	
}

GameManager* Scene::getGameManager() {
	return this->_gameManager;	
}