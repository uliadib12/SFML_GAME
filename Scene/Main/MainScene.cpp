#include "MainScene.hpp"
#include <iostream>

void MainScene::setUp(){
	if (!_arialFont.loadFromFile("arial.ttf"))
	{
	   std::cout << "Error loading font" << std::endl;
	}

	if (!_soundBuffer.loadFromFile("sound/uiClick.wav"))
	{
	   std::cout << "Error loading sound" << std::endl;
	}

	_soundUiMove.setBuffer(_soundBuffer);

	_playText.setFont(_arialFont);
	_playText.setString("Play");
	_playText.setFillColor(sf::Color::White);
	_playText.setStyle(sf::Text::Bold);
	_playText.setCharacterSize(_textSize);

	_optionsText.setFont(_arialFont);
	_optionsText.setString("Options");
	_optionsText.setFillColor(sf::Color::White);
	_optionsText.setStyle(sf::Text::Bold);
	_optionsText.setCharacterSize(_textSize);

	_quitText.setFont(_arialFont);
	_quitText.setString("Quit");
	_quitText.setFillColor(sf::Color::White);
	_quitText.setStyle(sf::Text::Bold);
	_quitText.setCharacterSize(_textSize);

	this->changeSelect(0);
}

void MainScene::update(){
	GameManager* gameManager = this->getGameManager();
	sf::RenderWindow* window = gameManager->getWindow();

	_playText.setPosition(window->getView().getCenter().x - _playText.getGlobalBounds().width / 2, window->getView().getCenter().y - _playText.getGlobalBounds().height / 2 + _textSize * 0 - _textSize);
	_optionsText.setPosition(window->getView().getCenter().x - _optionsText.getGlobalBounds().width / 2, window->getView().getCenter().y - _optionsText.getGlobalBounds().height / 2 + _textSize * 1 - _textSize);
	_quitText.setPosition(window->getView().getCenter().x - _quitText.getGlobalBounds().width / 2, window->getView().getCenter().y - _quitText.getGlobalBounds().height / 2 + _textSize * 2 - _textSize);

	window->draw(_playText);
	window->draw(_optionsText);
	window->draw(_quitText);
}

void MainScene::changeSelect(int index){
	_playText.setFillColor(sf::Color::White);
	_playText.setStyle(sf::Text::Bold);
	_optionsText.setFillColor(sf::Color::White);
	_optionsText.setStyle(sf::Text::Bold);
	_quitText.setFillColor(sf::Color::White);
	_quitText.setStyle(sf::Text::Bold);

	switch (index){
		case 0:	
			_playText.setFillColor(sf::Color::Red);
			_playText.setStyle(sf::Text::Bold | sf::Text::Underlined);
			break;
		case 1:
			_optionsText.setFillColor(sf::Color::Red);
			_optionsText.setStyle(sf::Text::Bold | sf::Text::Underlined);
			break;
		case 2:
			_quitText.setFillColor(sf::Color::Red);
			_quitText.setStyle(sf::Text::Bold | sf::Text::Underlined);
			break;
	}

	_selectedIndex = index;
}

void MainScene::moveUpSelect(){
	int index = _selectedIndex;

	if (index == 0)
		index = 2;
	else
		index--;

	_soundUiMove.play();
	changeSelect(index);
}

void MainScene::moveDownSelect(){
	int index = _selectedIndex;	

	if (index == 2)
		index = 0;
	else
		index++;

	_soundUiMove.play();
	changeSelect(index);
}

int MainScene::getSelectedIndex(){
	return _selectedIndex;	
}