//
// Created by minau on 11/30/2022.
//

#ifndef SFML_PROJECT_FONTS_H
#define SFML_PROJECT_FONTS_H
#include "fontsEnum.h"
#include <SFML/Graphics.hpp>
#include <map>

class Fonts {
private:
    static std::map<fontsEnum, sf::Font> map;
    static void load(fontsEnum font);
    static std::string getPath(fontsEnum font);
public:
    static sf::Font& getFont(fontsEnum font);
};


#endif //SFML_PROJECT_FONTS_H
