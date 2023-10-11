#include "MainScene.hpp"
#include <iostream>

void MainScene::setUp(){
	std::cout << "setUp" << std::endl;
}

void MainScene::update(){
	GameManager* gameManager = this->getGameManager();
	sf::RenderWindow* window = gameManager->getWindow();
	std::cout << "update" << std::endl;
}	