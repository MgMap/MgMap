//
// Created by minau on 11/30/2022.
//

#include "SplashState.h"

SplashState::SplashState()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_LENGTH, 60), "Test");
    setTexture(SPLASH);
    //mainMenuState.init();
    disableStates(HIDDEN);
}

void SplashState::draw(sf::RenderTarget &target, sf::RenderStates states) const{
 if(!checkState(HIDDEN))
 {
     target.draw(_background);
 }
}

void SplashState::setTexture(textureEnum texture) {
    _background.setTexture(Textures::getTexture(texture));
}

void SplashState::update() {
    if(clock.getElapsedTime().asSeconds() >SPLASH_SCREEN_TIME)
    {
      // std::cout << "Go to Main Menu" <<std::endl;
      // window.clear();
        enableState(HIDDEN);
       //mainMenuState.draw(window);
    }
}
