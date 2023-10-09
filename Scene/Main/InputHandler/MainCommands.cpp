#include "MainCommands.hpp"
#include "../MainScene.hpp"
#include "MainInputHandler.hpp"

void MoveCursorCommand::execute(GameManager* gameManager){
	MainInputHandler* inputHandler = (MainInputHandler*)gameManager->getInputHandler();
	MainScene* scene = (MainScene*)gameManager->getScene();

		if(!(inputHandler->moveState == MoveState::Up)){
			if(sf::Keyboard::isKeyPressed(inputHandler->m_keyMap["Up"])
				|| sf::Keyboard::isKeyPressed(inputHandler->m_keyMap["Up_Alternate"])){
					inputHandler->moveState = MoveState::Up;
					scene->moveUpSelect();
				}
		}

		if(!(inputHandler->moveState == MoveState::Down)){
			if(sf::Keyboard::isKeyPressed(inputHandler->m_keyMap["Down"])
				|| sf::Keyboard::isKeyPressed(inputHandler->m_keyMap["Down_Alternate"])){
					inputHandler->moveState = MoveState::Down;
					scene->moveDownSelect();
				}
		}

		if(!(inputHandler->moveState == MoveState::Left)){
			if(sf::Keyboard::isKeyPressed(inputHandler->m_keyMap["Left"])
				|| sf::Keyboard::isKeyPressed(inputHandler->m_keyMap["Left_Alternate"])){
					inputHandler->moveState = MoveState::Left;
					std::cout << "Left" << std::endl;
				}
		}

		if(!(inputHandler->moveState == MoveState::Right)){
			if(sf::Keyboard::isKeyPressed(inputHandler->m_keyMap["Right"])
				|| sf::Keyboard::isKeyPressed(inputHandler->m_keyMap["Right_Alternate"])){
				inputHandler->moveState = MoveState::Right;
				std::cout << "Right" << std::endl;
			}
		}
			
}

void ActionCommand::execute(GameManager* gameManager){
	InputHandlerInterface *inputHandler = gameManager->getInputHandler();
	MainScene* scene = (MainScene*)gameManager->getScene();
	sf::RenderWindow* window = gameManager->getWindow();

	if(sf::Keyboard::isKeyPressed(inputHandler->m_keyMap["Enter"]))
		switch (scene->getSelectedIndex())
		{
		case 0:
			std::cout << "Play" << std::endl;
			break;
		case 1:
			std::cout << "Options" << std::endl;
			break;
		case 2:
			window->close();
			break;
		default:
			break;
		}

	if(sf::Keyboard::isKeyPressed(inputHandler->m_keyMap["Exit"]))
		std::cout << "Exit" << std::endl;
}