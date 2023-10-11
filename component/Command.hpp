#pragma once

#include "GameManager.hpp"

class GameManager;

class Command {
public:
    virtual ~Command() {}
    virtual void execute(GameManager* gameManager) = 0;
};