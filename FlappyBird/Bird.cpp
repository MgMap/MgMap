//
// Created by minau on 12/1/2022.
//

#include "Bird.h"

Bird::Bird() {
    init();
}

void Bird::init() {
    iter = 0;
    _birdTextures.push_back(Textures::getTexture(BIRD1));
    _birdTextures.push_back(Textures::getTexture(BIRD2));
    _birdTextures.push_back(Textures::getTexture(BIRD3));
    _birdSprite.setTexture(_birdTextures[iter]);
    setPosition();
    _birdState = STILL;
    sf::Vector2f origin = sf::Vector2f ( _birdSprite.getGlobalBounds().height/2, _birdSprite.getGlobalBounds().width/2);
    _birdSprite.setOrigin(origin);
    _rotation = 0;

}

void Bird::animate()
{
    if(_clock.getElapsedTime().asSeconds()>
       BIRD_ANIMATION_DURATION/ _birdTextures.size())
    {
        if(iter < _birdTextures.size()-1)
        {
            iter++;
        }
        else{
            iter=0;
        }
        _birdSprite.setTexture(_birdTextures.at(iter));
        _birdSprite.setScale(2,2);
        _clock.restart();
    }

}

void Bird::update()
{
    if(_birdState == FALLING) {
        _birdSprite.move(0, GRAVITY * dt);
        _rotation += ROTATION_SPEED * dt;
        if (_rotation > 25.0f) {
            _rotation = 25.0f;
        }
        _birdSprite.setRotation(_rotation);
    }
    else if( _birdState == FLYING)
    {
        _birdSprite.move(0,-FLYING_SPEED *dt);
        _rotation -= ROTATION_SPEED * dt;
        if (_rotation < -25.0f) {
            _rotation = -25.0f;
        }
        _birdSprite.setRotation(_rotation);
    }
    if(_movementClock.getElapsedTime().asSeconds()> FLYING_DURATION)
    {
        _movementClock.restart();
        _birdState = FALLING;
    }
}

void Bird::Tap()
{
    _birdState = FLYING;
    _movementClock.restart();
}

void Bird::draw(sf::RenderTarget &target, sf::RenderStates states) const
{

    target.draw(_birdSprite);
}

void Bird::setPosition()
{
    _birdSprite.setPosition((SCREEN_WIDTH/ 4) - (_birdSprite.getGlobalBounds().width / 2),
            (SCREEN_LENGTH/ 2) - (_birdSprite.getGlobalBounds().height / 2));
}

sf::Sprite Bird::GetBirdSprite() {
    return _birdSprite;
}
