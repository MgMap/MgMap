//
// Created by minau on 12/1/2022.
//

#ifndef SFML_PROJECT_MAINMENUSTATE_H
#define SFML_PROJECT_MAINMENUSTATE_H
#include <iostream>
#include "DEFINITIONS.h"
#include <SFML/Graphics.hpp>
#include "Textures.h"
#include "States.h"
#include "MouseEvent.h"

class MainMenuState :public sf::Drawable, public States
        {
public:
    MainMenuState();
    void init();
    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void eventHandler(sf::RenderWindow &window, sf::Event event);
    sf::Sprite getPlayButton();
private:
    sf::Sprite _background;
    sf::Sprite _title;
    sf::Sprite _playButton;
};


#endif //SFML_PROJECT_MAINMENUSTATE_H
