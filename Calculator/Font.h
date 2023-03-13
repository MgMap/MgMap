//
// Created by minau on 2/14/2023.
//

#ifndef SFML_PROJECT_FONT_H
#define SFML_PROJECT_FONT_H
#include <SFML/Graphics.hpp>

class Font
{
private:
    static sf::Font font;
    static void loadFont();

public:
   static sf::Font& getFont();

};


#endif //SFML_PROJECT_FONT_H
