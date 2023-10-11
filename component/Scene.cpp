#include "Scene.hpp"

Scene::Scene(InputHandlerInterface* inputHandler) : inputHandler(inputHandler) {};

void Scene::setGameManager(GameManager* gameManager) {
	this->_gameManager = gameManager;	
}

void Scene::update() {
	std::cout << "update" << std::endl;	
}

GameManager* Scene::getGameManager() {
	return this->_gameManager;	
}