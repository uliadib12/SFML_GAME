#pragma once

#include "../../component/Scene.hpp"

class MainScene : public Scene {
	public:
		MainScene(InputHandlerInterface* inputHandler) : Scene(inputHandler){};
		void update() override;
};