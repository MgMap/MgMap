//
// Created by minau on 12/8/2022.
//

#include "projectTextures.h"
std::map<projectEnums, sf::Texture> projectTextures::map;

void projectTextures::load(projectEnums texture)
{
    map[texture].loadFromFile(getPath(texture));
}

std::string projectTextures::getPath(projectEnums texture)
{
    switch (texture)
    {
        case GREEN_BALL: return "Project pic/greenball.png";
        case BOUNCING_BALL: return "Project pic/Bouncing ball.png";
        case PONG: return "Project pic/pong.png";
        case CARD: return "Project pic/card.png";
        case POKER_ANALYSIS: return "Project pic/pokeranalysis.png";
        case FLAPPY_BIRD: return "Project pic/flappybird.png";
    }
}

sf::Texture &projectTextures::getTexture(projectEnums texture) {
    load(texture);
    return map[texture];
}
