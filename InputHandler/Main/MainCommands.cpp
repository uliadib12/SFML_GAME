#include "MainCommands.hpp"

void MoveCursorCommand::execute(GameManager* gameManager){
	InputHandlerInterface* inputHandler = gameManager->getInputHandler();

		if(sf::Keyboard::isKeyPressed(inputHandler->m_keyMap["Up"])
			|| sf::Keyboard::isKeyPressed(inputHandler->m_keyMap["Up_Alternate"])){
				std::cout << "Up" << std::endl;
			}

		if(sf::Keyboard::isKeyPressed(inputHandler->m_keyMap["Down"])
			|| sf::Keyboard::isKeyPressed(inputHandler->m_keyMap["Down_Alternate"])){
				std::cout << "Down" << std::endl;
			}

		if(sf::Keyboard::isKeyPressed(inputHandler->m_keyMap["Left"])
			|| sf::Keyboard::isKeyPressed(inputHandler->m_keyMap["Left_Alternate"])){
				std::cout << "Left" << std::endl;
			}
			
		if(sf::Keyboard::isKeyPressed(inputHandler->m_keyMap["Right"])
			|| sf::Keyboard::isKeyPressed(inputHandler->m_keyMap["Right_Alternate"])){
			std::cout << "Right" << std::endl;
		}
}

void ActionCommand::execute(GameManager* gameManager){
	InputHandlerInterface *inputHandler = gameManager->getInputHandler();

	if(sf::Keyboard::isKeyPressed(inputHandler->m_keyMap["Enter"]))
		std::cout << "Enter" << std::endl;

	if(sf::Keyboard::isKeyPressed(inputHandler->m_keyMap["Exit"]))
		std::cout << "Exit" << std::endl;
}