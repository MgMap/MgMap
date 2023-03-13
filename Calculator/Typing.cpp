//
// Created by minau on 3/5/2023.
//

#include "Typing.h"
Typing::Typing()
{
    setupDefaultsVisuals();
    textedType.setString(textTypeStr);
}

void Typing::setupDefaultsVisuals()
{
    textColor(sf::Color::White);
    textSize(30);
    font.loadFromFile("OpenSans-Bold (1).ttf");
    textFont(font);
    textPosition({0, 100});
}

void Typing::textColor(const sf::Color &color)
{
    this->textedType.setFillColor(color);
    this->solution.setFillColor(color);
}

void Typing::textSize(const unsigned int &charSize)
{
    this->textedType.setCharacterSize(charSize);
    this->solution.setCharacterSize(charSize);
}

void Typing::textFont(const sf::Font &textFont)
{
    this->textedType.setFont(font);
    this->solution.setFont(font);
}

void Typing::textPosition(const sf::Vector2f& pos)
{
    this->textedType.setPosition(pos);
    this->solution.setPosition({pos.x,pos.y+50});
}

void Typing::update()
{
    this->textedType.setString(this->textTypeStr);
    this->solution.setString(this->solutionStr);
}

void Typing::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    if(event.type ==sf::Event::MouseButtonPressed)
    {
        for (int i = 0; i < 19; i++)
        {
            if (MouseEvents::isClicked(base.button[i], window))
            {
                if(i == 0)
                {
                    this->textTypeStr = "";
                    this->solutionStr ="";
                }
                else if(i == 17)
                {
                    this->solutionStr = std::to_string(RPN::readPostfix(RPN::infixToPostfix(textTypeStr)));
                }
                else
                this->textTypeStr += base.symbols[i];
            }
        }
    }
}

void Typing::backSpaceF()
{
    std::string temp = "";
    for(int i=0; i<this->textTypeStr.length()-1; ++i) {
        temp += textTypeStr[i];
    }
    textTypeStr = temp;
}

void Typing::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(this->textedType);
    window.draw(this->solution);
    //align window size and text size
}