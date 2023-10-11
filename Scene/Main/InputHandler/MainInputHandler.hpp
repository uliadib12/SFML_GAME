#pragma once

#include "../../../component/InputHandlerInterface.hpp"
#include "MainCommands.hpp"

class MainInputHandler : public InputHandlerInterface {
	public:
	MainInputHandler();
	~MainInputHandler();
	Command* handleInputEvent(sf::Event& event) override;
	Command* handleInputRealTime(sf::Event& event) override;

	private:
	Command* _moveCursorCommand;
	Command* _actionCommand;
};