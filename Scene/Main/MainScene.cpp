#include "MainScene.hpp"
#include <iostream>

MainScene::MainScene(InputHandlerInterface* inputHandler) : Scene(inputHandler){
	
}

void MainScene::update(){
	std::cout << "update" << std::endl;
}	