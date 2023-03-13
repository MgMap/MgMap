//
// Created by minau on 2/14/2023.
//

#include "Base.h"

Base::Base()
{
    setUp();
}
void Base::eventHandler(sf::RenderWindow &window, sf::Event event)
{
    for(Button& b: button)
    {
        b.eventHandler(window,event);
    }
}

void Base::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    for(const Button& b: button)
    {
        window.draw(b);
    }
}

void Base::setUp()
{
    float x =0;
    float y = 200;
    int index = 0;
    float width, height;
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 4 ; j++)
        {
            Button b(symbols[index]);
            b.setPosition({x,y});
            button[index++] = b;

            width = b.getGlobalBounds().width;
            height = b.getGlobalBounds().height;
            x+= width +10;
        }
        y+= height +10;
        x=0;
    }
}
