#include "GameManager.hpp"
#include <iostream>

GameManager::GameManager(sf::RenderWindow* window,Scene* scene, sf::Clock* clock):
	_window(window),
	_scene(scene),
	_clock(clock)
{
	if(_scene != nullptr)
		this->setUpScene();
}

GameManager::~GameManager() {
	
}

void GameManager::update() {
	float timeElapsed = this->_clock->getElapsedTime().asSeconds();
   this->_clock->restart();
    
	this->setUpInputHandler();
	this->_scene->update();
}

void GameManager::setScene(Scene* scene) {
	this->_scene = scene;
	this->setUpScene();
}

void GameManager::setUpInputHandler() {
	sf::Event event;

    while (_window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
           _window->close();

       Command* command = this->_scene->inputHandler->handleInputEvent(event);
       if(command != nullptr){
       	command->execute(this);
       }
    }

    Command* command = this->_scene->inputHandler->handleInputRealTime(event);
    if(command != nullptr){
    	command->execute(this);
    }
}

void GameManager::setUpScene() {
	this->_scene->setGameManager(this);
}

InputHandlerInterface* GameManager::getInputHandler() {
	return this->_scene->inputHandler;	
}

sf::RenderWindow* GameManager::getWindow() {
	return this->_window;	
}

Scene* GameManager::getScene() {
	return this->_scene;	
}

sf::Clock* GameManager::getClock() {
	return this->_clock;	
}