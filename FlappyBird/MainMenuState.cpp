//
// Created by minau on 12/1/2022.
//

#include "MainMenuState.h"


MainMenuState::MainMenuState()
{
    init();
    disableStates(HIDDEN);
}

void MainMenuState::init()
{
    _background.setTexture(Textures::getTexture(BACKGROUND));
    _title.setTexture(Textures::getTexture(TITLE));
    _playButton.setTexture(Textures::getTexture(PLAY_BUTTON));
    _title.setPosition((SCREEN_WIDTH / 2) - (_title.getGlobalBounds().width / 2),
                       _title.getGlobalBounds().height / 2);
    _playButton.setPosition((SCREEN_WIDTH / 2) -
                            (_playButton.getGlobalBounds().width / 2),
                            (SCREEN_LENGTH/2)-_playButton.getGlobalBounds().height / 2);

}

void MainMenuState::update()
{

}

void MainMenuState::eventHandler(sf::RenderWindow &window, sf::Event event)
{
    if(!checkState(HIDDEN))
    {
        if (MouseEvents::isClicked(_playButton, window))
        {
            enableState(HIDDEN);
            std::cout << "Game State";
        }
    }

}

void MainMenuState::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    if(!checkState(HIDDEN))
    {
        window.draw(_background);
        window.draw(_title);
        window.draw(_playButton);
    }
}

sf::Sprite MainMenuState::getPlayButton()
{
    return _playButton;
}