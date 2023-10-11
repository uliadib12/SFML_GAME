#pragma once

#include <SFML/Window.hpp>
#include <map>
#include <memory>
#include <string>
#include "Command.hpp"

class Command;

class InputHandlerInterface
{
public:
	virtual ~InputHandlerInterface() {};
	virtual Command* handleInputEvent(sf::Event& event) = 0;
	virtual Command* handleInputRealTime(sf::Event& event) = 0;
	std::map<std::string, sf::Keyboard::Key> m_keyMap;
	std::map<std::string, sf::Mouse::Button> m_mouseButtonMap;
};