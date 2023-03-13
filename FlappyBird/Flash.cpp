//
// Created by minau on 12/7/2022.
//

#include "Flash.h"

Flash::Flash()
{
    init();
}

void Flash::init()
{
    rectangleShape = sf::RectangleShape(sf::Vector2f({SCREEN_WIDTH,SCREEN_LENGTH}));
    rectangleShape.setFillColor(sf::Color(255,255,255,0));
    flashOn = true;
}

void Flash::animate()
{
    if(flashOn)
    {
        float alpha = rectangleShape.getFillColor().a + FLASH_SPEED;
        if(alpha >= 255)
        {
            alpha = 255;
            flashOn = false;
        }
        rectangleShape.setFillColor(sf::Color(255,255,255,alpha));
    }
    else
    {
        float alpha = rectangleShape.getFillColor().a - FLASH_SPEED;
        if(alpha <= 0)
        {
            alpha = 0;
            flashOn = false;
        }
        rectangleShape.setFillColor(sf::Color(255,255,255,alpha));
    }
}

void Flash::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(rectangleShape);
}
