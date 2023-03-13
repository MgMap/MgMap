//
// Created by minau on 12/1/2022.
//

#include "Land.h"

Land::Land()
{
 init();
}

void Land::init()
{
    sf::Sprite sprite;
    sf::Sprite sprite2;

    sprite.setTexture(Textures::getTexture(LAND));
    sprite2.setTexture(Textures::getTexture(LAND));
    sprite.setPosition(0,SCREEN_LENGTH -
                         sprite.getGlobalBounds().height);
    sprite2.setPosition(sprite.getGlobalBounds().width , SCREEN_LENGTH-
                                                        sprite.getGlobalBounds().height);
    landSprites.push_back(sprite);
    landSprites.push_back(sprite2);
}


void Land::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    for(int i = 0; i < landSprites.size(); i++)
    {
        target.draw(landSprites[i]);
    }

}

void Land::animate() {
    for (int i = 0; i < landSprites.size(); i++) {
        //multiple with dt to get framerate independent game play
        float movement = LAND_SPEED * dt;
        landSprites.at(i).move(-movement, 0.0f);
        //need some fixing here
        if (landSprites.at(i).getPosition().x + landSprites.at(i).getGlobalBounds().width < 0) {
            sf::Vector2f position(SCREEN_WIDTH,landSprites.at(i).getPosition().y);
            landSprites.at(i).setPosition(position);
        }
    }
}

const std::vector<sf::Sprite> &Land::GetSprites() const
{
    return landSprites;
}
