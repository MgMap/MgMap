//
// Created by minau on 12/1/2022.
//

#ifndef SFML_PROJECT_PIPE_H
#define SFML_PROJECT_PIPE_H
#include <SFML/Graphics.hpp>
#include "States.h"
#include "DEFINITIONS.h"
#include "Textures.h"

class Pipe : public sf::Drawable , public States{
public:
    Pipe();
    void init();
    void spawnPipeUp();
    void spawnPipeDown();
    void spawnInvisiblePipe();
    void spawnScoringPipe();
    void randomOffSetY();
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    void animate();
    const std::vector<sf::Sprite> &GetPipeSprites() const;
    std::vector<sf::RectangleShape> &GetScoringSprites();
    void update();
private:
    int landHeight;
    int pipeSpawnOffSetY;
    std::vector<sf::Sprite> PipeSprites;
    std::vector<sf::RectangleShape> scoringPipes;
};


#endif //SFML_PROJECT_PIPE_H
