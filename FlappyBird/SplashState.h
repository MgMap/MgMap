//
// Created by minau on 11/30/2022.
//

#ifndef SFML_PROJECT_SPLASHSTATE_H
#define SFML_PROJECT_SPLASHSTATE_H
#include "TextureEnum.h"
#include "Textures.h"
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.h"
#include <iostream>
#include "MainMenuState.h"
#include "States.h"

class SplashState :public sf::Drawable ,public States{
public:
    SplashState();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void setTexture(textureEnum texture);
    void update();
    //sf::RenderWindow window;
private:

    sf::Clock clock;
    sf::Sprite _background;
    //MainMenuState mainMenuState;
};


#endif //SFML_PROJECT_SPLASHSTATE_H
