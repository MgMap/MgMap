//
// Created by minau on 11/30/2022.
//

#include "GameState.h"

GameState::GameState()
{
    srand(time(NULL));
    init();
}

void GameState::init()
{
    _background.setTexture(Textures::getTexture(BACKGROUND));
    enableState(DISABLED);
    _gameStates = READY;
    int scoreCounter = 0;
    scores.update(scoreCounter);
}

void GameState::update()
{
    splashState.update();
    //mainMenuState.update();
    if (_gameStates != GAMEOVER)
    {
        land.animate();
        bird.animate();
    }

    //bird flying
    if (_gameStates == PLAYING)
    {

        pipe.animate();
        if (clock.getElapsedTime().asSeconds() > PIPE_SPAWN_SPEED)
        {
            pipe.update();
            clock.restart();
        }
        bird.update();
    }

    //check collision with land
    std::vector<sf::Sprite> landSprites = land.GetSprites();
    for (int i = 0; i < landSprites.size(); i++)
    {
        if (Collisions::checkLandCollision(bird.GetBirdSprite(), landSprites.at(i))) {
            _gameStates = GAMEOVER;
        }
    }

    //check collision with pipes
    std::vector<sf::Sprite> PipeSprites = pipe.GetPipeSprites();
    for (int i = 0; i < PipeSprites.size(); i++)
    {
        if (Collisions::checkPipeCollision(bird.GetBirdSprite(), 1.3f, PipeSprites.at(i), 1.0f)) {
            _gameStates = GAMEOVER;
        }
    }
    //check scores
    std::vector<sf::RectangleShape> ScoringSprites = pipe.GetScoringSprites();
    if (_gameStates == PLAYING)
    {
        for (int i = 0; i < ScoringSprites.size(); i++) {
            //std::cout << "this works";
            if (Collisions::checkScoring(bird.GetBirdSprite(),ScoringSprites.at(i)))
            {
                scoreCounter++;
                scores.update(scoreCounter);
                std::cout << scoreCounter;
            }
        }
    }

    if(_gameStates == GAMEOVER)
    {
        flash.animate();

        if(clock.getElapsedTime().asSeconds() > GAMEOVER_TIME)
        {
            //std::cout <<clock.getElapsedTime().asSeconds();
            gameOver.update();
        }
    }
}

void GameState::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(_background);
    target.draw(scores);
    target.draw(bird);
    target.draw(pipe);
    target.draw(land);
    target.draw(gameOver);
    target.draw(flash);
    target.draw(mainMenuState);
    target.draw(splashState);
}

void GameState::eventHandler(sf::RenderWindow &window, sf::Event event)
{

    if(mainMenuState.checkState(HIDDEN) && _gameStates != GAMEOVER )
    {
        if (MouseEvents::isClicked(_background, window)) {
            std::cout << "Clicked! ";
            disableStates(DISABLED);
            bird.Tap();
            _gameStates = PLAYING;
        }
    }
    mainMenuState.eventHandler(window,event);
}
