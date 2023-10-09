#pragma once

#include <SFML/Audio.hpp>
#include "../../component/Scene.hpp"

class MainScene : public Scene {
	public:
		MainScene(InputHandlerInterface* inputHandler) : Scene(inputHandler) {};
		void setUp() override;
		void update() override;
		void changeSelect(int index);
		void moveUpSelect();
		void moveDownSelect();
		int getSelectedIndex();

	private:
		sf::Font _arialFont;
		sf::SoundBuffer _soundBuffer;
		sf::Sound _soundUiMove;
		int _textSize = 40;
		sf::Text _playText;
		sf::Text _optionsText;
		sf::Text _quitText;

		int _selectedIndex = 0;
};