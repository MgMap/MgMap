//
// Created by minau on 11/30/2022.
//

#include "Fonts.h"
std::map<fontsEnum, sf::Font> Fonts::map;

void Fonts::load(fontsEnum font)
{
    map[font].loadFromFile((getPath(font)));
}

std::string Fonts::getPath(fontsEnum font)
{
    switch(font)
    {
        case FLAPPY_FONT: return "fonts/RoTwimchRegular-WyR3n.ttf";
        case OPEN_SANS: return "fonts/OpenSans-Bold.ttf";
        case LAST_FONT:
            break;
    }
}

sf::Font &Fonts::getFont(fontsEnum font)
{
    load(font);
    return map[font];
}