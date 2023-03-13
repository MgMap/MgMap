//
// Created by minau on 11/30/2022.
//

#include "Textures.h"
std::map<textureEnum, sf::Texture> Textures::map;
void Textures::load(textureEnum texture)
{
 map[texture].loadFromFile(getPath(texture));
}

std::string Textures::getPath(textureEnum texture)
{
    switch(texture)
    {
        case BACKGROUND: return "pics/background.jpg";
        case GROUND: return "pics/flappy_ground (1).png";
        case PIPE_UP: return "pics/Pipe up.png";
        case PIPE_DOWN: return "pics/Pipe down.png";
        case PLAY_BUTTON: return "pics/playbutton.png";
        case BAT: return "pics/bat-NESW-red (1).png";
        case BIRD1: return "pics/bluebird-upflap.png";
        case BIRD2: return "pics/bluebird-midflap.png";
        case BIRD3: return "pics/bluebird-downflap.png";
        case SPLASH: return "pics/IMG_0038.png";
        case TITLE: return "pics/title.png";
        case LAND: return "pics/flappy_ground (1).png";
        case SCORINGPIPE: return "pics/InvisibleScoringPipe.png";
        case GAMEOVERSPRITE: return "pics/game_over_sprite-removebg-preview.png";
        //
    }
}

sf::Texture &Textures::getTexture(textureEnum texture) {
     load(texture);
     return map[texture];
}
