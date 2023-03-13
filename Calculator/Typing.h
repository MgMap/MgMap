//
// Created by minau on 3/5/2023.
//

#ifndef SFML_PROJECT_TYPING_H
#define SFML_PROJECT_TYPING_H
#include <SFML/Graphics.hpp>
#include "Base.h"
#include "MouseEvents.h"
#include "Base.h"
#include "RPN.h"

class Typing : public sf::Drawable
{
    sf::Text textedType;
    sf::Text solution;
    std::string textTypeStr = "";
    std::string solutionStr ="";
    sf::Font font;
    Base base;
    void setupDefaultsVisuals(); //visuals
    //backspace function
    void backSpaceF();
public:
    Typing();

    //visuals
    void textColor(const sf::Color& color);
    void textSize(const unsigned int& charSize);
    void textFont(const sf::Font& textFont);
    void textPosition(const sf::Vector2f& pos);

    //
    void update();
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
protected:
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};


#endif //SFML_PROJECT_TYPING_H
