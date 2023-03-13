//
// Created by minau on 12/1/2022.
//

#include "Pipe.h"

Pipe::Pipe() {
    init();
}

void Pipe::init()
{
    landHeight = Textures::getTexture(LAND).getSize().y;
    pipeSpawnOffSetY = 0;
}

void Pipe::update()
{
    randomOffSetY();
   //spawnInvisiblePipe();
    spawnPipeDown();
    spawnPipeUp();
    spawnScoringPipe();
}

void Pipe::randomOffSetY()
{
    pipeSpawnOffSetY = rand() % (landHeight-50);
}

void Pipe::spawnPipeDown()
{
    sf::Sprite sprite;
    sprite.setTexture(Textures::getTexture(PIPE_DOWN));
    sprite.setPosition(SCREEN_WIDTH, -pipeSpawnOffSetY);
    PipeSprites.push_back(sprite);
}

void Pipe::spawnPipeUp()
{
    sf::Sprite sprite;
    sprite.setTexture(Textures::getTexture(PIPE_UP));
    sprite.setPosition(SCREEN_WIDTH, SCREEN_LENGTH -sprite.getGlobalBounds().height - pipeSpawnOffSetY);
    PipeSprites.push_back(sprite);
}

/*void Pipe::spawnInvisiblePipe()
{
    sf::Sprite sprite;
    sprite.setTexture(Textures::getTexture(PIPE_UP));
    sprite.setPosition(SCREEN_WIDTH, SCREEN_LENGTH -sprite.getGlobalBounds().height - pipeSpawnOffSetY);
    sprite.setColor(sf::Color(0,0,0,0));
    PipeSprites.push_back(sprite);
}*/

void Pipe::spawnScoringPipe()
{
    sf::RectangleShape rectangleShape;
    rectangleShape.setSize({69,1024});
    rectangleShape.setPosition(SCREEN_WIDTH, 0);
    rectangleShape.setFillColor(sf::Color(0,0,0,0));
    scoringPipes.push_back(rectangleShape);
}


void Pipe::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    for(int i = 0; i < PipeSprites.size();i++)
    {
        target.draw(PipeSprites.at(i));
    }
    for(int i = 0; i < scoringPipes.size(); i++)
    {
        target.draw(scoringPipes.at(i));
    }
}

void Pipe::animate()
{
    for(int i = 0; i <PipeSprites.size(); i++)
    {
        //get rid of pipes that goes beyond screen
        if(PipeSprites.at(i).getPosition().x + PipeSprites.at(i).getGlobalBounds().width <0)
        {
            PipeSprites.erase(PipeSprites.begin()+i);
        }
        else
        {
            float movement = PIPE_SPEED * dt;
            PipeSprites.at(i).move(-movement, 0);
        }
    }
    for(int i = 0; i <scoringPipes.size(); i++)
    {
        //get rid of pipes that goes beyond screen
        if(scoringPipes.at(i).getPosition().x + scoringPipes.at(i).getGlobalBounds().width <0)
        {
            scoringPipes.erase(scoringPipes.begin()+i);
        }
        else
        {
            float movement = PIPE_SPEED * dt;
            scoringPipes.at(i).move(-movement, 0);
        }
    }
}

const std::vector<sf::Sprite> &Pipe::GetPipeSprites() const
{
    return PipeSprites;
}

std::vector<sf::RectangleShape> &Pipe::GetScoringSprites() {
    return scoringPipes;
}
