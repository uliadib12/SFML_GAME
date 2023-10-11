#pragma once

#include "../../component/Command.hpp"
#include "../../component/InputHandlerInterface.hpp"

#include <SFML/Window.hpp>

#include <iostream>

class MoveCursorCommand : public Command {
public:
	virtual void execute(GameManager* gameManager) override;
};

class ActionCommand : public Command {
public:
	virtual void execute(GameManager* gameManager) override;
};