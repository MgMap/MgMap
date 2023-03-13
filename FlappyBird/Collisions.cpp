//
// Created by minau on 12/1/2022.
//


#include "Collisions.h"


bool Collisions::checkLandCollision(const sf::Sprite &obj1, const sf::Sprite &obj2)
{

    sf::FloatRect rect1 = obj1.getGlobalBounds();
    sf::FloatRect rect2;
    rect2.top = obj2.getGlobalBounds().top +50;
    rect2.left = obj2.getGlobalBounds().left;
    rect2.width = obj2.getGlobalBounds().width;
    rect2.height = obj2.getGlobalBounds().height;

    if(rect1.intersects(rect2))
    {
        return true;
    }
    else{
        return false;
    }
}


bool Collisions::checkPipeCollision(sf::Sprite obj1, float scale1,  sf::Sprite obj2, float scale2) {
    obj1.setScale(scale1,scale1);
    obj2.setScale(scale2,scale2);
    sf::FloatRect rect1 = obj1.getGlobalBounds();
    sf::FloatRect rect2 = obj2.getGlobalBounds();

    if(rect1.intersects(rect2))
    {
        return true;
    }
    else{
        return false;
    }
}

bool Collisions::checkScoring(const sf::Sprite &obj1, const sf::RectangleShape &obj2)
{
    if( obj2.getPosition().x + obj2.getGlobalBounds().width == obj1.getPosition().x)
    {
        return true;
    }
    else
        return false;

}
