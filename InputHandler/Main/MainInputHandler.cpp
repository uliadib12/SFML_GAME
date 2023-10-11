#include "MainInputHandler.hpp"

MainInputHandler::MainInputHandler() {
	this->m_keyMap["Up"] = sf::Keyboard::Up;
	this->m_keyMap["Up_Alternate"] = sf::Keyboard::W;
	this->m_keyMap["Down"] = sf::Keyboard::Down;
	this->m_keyMap["Down_Alternate"] = sf::Keyboard::S;
	this->m_keyMap["Left"] = sf::Keyboard::Left;
	this->m_keyMap["Left_Alternate"] = sf::Keyboard::A;
	this->m_keyMap["Right"] = sf::Keyboard::Right;
	this->m_keyMap["Right_Alternate"] = sf::Keyboard::D;
	this->m_keyMap["Enter"] = sf::Keyboard::Return;
	this->m_keyMap["Exit"] = sf::Keyboard::Escape;

	_moveCursorCommand = new MoveCursorCommand();
	_actionCommand = new ActionCommand();
}

MainInputHandler::~MainInputHandler() {
	delete _moveCursorCommand;
}

Command* MainInputHandler::handleInputEvent(sf::Event& event) {
	return nullptr;
}

Command* MainInputHandler::handleInputRealTime(sf::Event& event) {
	if(sf::Keyboard::isKeyPressed(m_keyMap["Up"]) || 
	   sf::Keyboard::isKeyPressed(m_keyMap["Up_Alternate"]) ||
	   sf::Keyboard::isKeyPressed(m_keyMap["Down"]) ||
	   sf::Keyboard::isKeyPressed(m_keyMap["Down_Alternate"]) ||
	   sf::Keyboard::isKeyPressed(m_keyMap["Left"]) ||
	   sf::Keyboard::isKeyPressed(m_keyMap["Left_Alternate"]) ||
	   sf::Keyboard::isKeyPressed(m_keyMap["Right"]) ||
	   sf::Keyboard::isKeyPressed(m_keyMap["Right_Alternate"]))
	   	return _moveCursorCommand;

	 if(sf::Keyboard::isKeyPressed(m_keyMap["Enter"]) || 
	 	sf::Keyboard::isKeyPressed(m_keyMap["Exit"]))
	   	return _actionCommand;

	return nullptr;
}