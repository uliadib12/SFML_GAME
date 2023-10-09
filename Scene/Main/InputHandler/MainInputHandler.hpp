#pragma once

#include "../../../component/InputHandlerInterface.hpp"
#include "MainCommands.hpp"

enum MoveState {
	None,
	Up,	
	Down,
	Left,
	Right
};

class MainInputHandler : public InputHandlerInterface {
	public:
	MainInputHandler();
	~MainInputHandler();
	Command* handleInputEvent(sf::Event& event) override;
	Command* handleInputRealTime(sf::Event& event) override;
	MoveState moveState;

	private:
	Command* _moveCursorCommand;
	Command* _actionCommand;
};