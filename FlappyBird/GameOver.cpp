//
// Created by minau on 12/7/2022.
//

#include "GameOver.h"

GameOver::GameOver()
{
    init();
}

void GameOver::init()
{
    enableState(HIDDEN);
    gameOver.setTexture(Textures::getTexture(GAMEOVERSPRITE));
    gameOver.setPosition({SCREEN_WIDTH/2 - gameOver.getGlobalBounds().width/2, SCREEN_LENGTH/2 - gameOver.getGlobalBounds().height/2});
    gameOver.setColor(sf::Color(255,255,255,0));
}

void GameOver::update()
{

    //if(clock.getElapsedTime().asSeconds() > GAMEOVER_TIME )
    {
        disableStates(HIDDEN);
    }
    if(!checkState(HIDDEN))
    {
        float alpha = gameOver.getColor().a + GAMEOVER_SPEED;
        if(alpha >= 255)
        {
            alpha = 255;
        }
        gameOver.setColor(sf::Color(255,255,255,alpha));
    }
}

void GameOver::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    if(!checkState(HIDDEN))
    {
        target.draw(gameOver);
    }
}
