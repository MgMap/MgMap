//
// Created by minau on 11/30/2022.
//

#ifndef SFML_PROJECT_GAMESTATE_H
#define SFML_PROJECT_GAMESTATE_H
#include "DEFINITIONS.h"
#include "SplashState.h"
#include <SFML/Graphics.hpp>
#include "Bird.h"
#include "Land.h"
#include "Pipe.h"
#include "Collisions.h"
#include "GameStates.h"
#include <time.h>
#include "Scores.h"
#include "Flash.h"
#include "GameOver.h"

class GameState :public sf::Drawable, public States {
public:
    GameState();
    void init();
    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void eventHandler(sf::RenderWindow &window, sf::Event event);
private:
    sf::Sprite _background;
    sf::Clock clock;
    sf::Clock gameOverClock;
    GameOver gameOver;
    Bird bird;
    SplashState splashState;
    Land land;
    Pipe pipe;
    Scores scores;
    Flash flash;
    int scoreCounter;
    MainMenuState mainMenuState;
    int _gameStates;


};


#endif //SFML_PROJECT_GAMESTATE_H
