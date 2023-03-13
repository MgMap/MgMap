//
// Created by minau on 12/8/2022.
//

#ifndef SFML_PROJECT_SCREEN_H
#define SFML_PROJECT_SCREEN_H
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.h"
#include <string>
#include "projectTextures.h"

class Screen {

public:
    Screen();
    Screen(std::string text, int number);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;

};


#endif //SFML_PROJECT_SCREEN_H
