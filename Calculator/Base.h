//
// Created by minau on 2/14/2023.
//

#ifndef SFML_PROJECT_BASE_H
#define SFML_PROJECT_BASE_H
#include <string>
#include <SFML/Graphics.hpp>
#include "Button.h"

class Base : public sf::Drawable
{
private:

public:
    std::string symbols[20] ={"AC", "(", ")", "/", "7", "8", "9", "*",
                              "4","5", "6","-", "1","2","3", "+", "0","=","",""};
    Button button[20];
    void setUp();
    Base();
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};


#endif //SFML_PROJECT_BASE_H
