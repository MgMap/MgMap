//
// Created by minau on 12/1/2022.
//

#ifndef SFML_PROJECT_BIRD_H
#define SFML_PROJECT_BIRD_H
#include "DEFINITIONS.h"
#include "Textures.h"
#include "States.h"
#include <vector>
#include "BirdState.h"

class Bird : public sf::Drawable , public States{
public:
    Bird();
    void init();
    void animate();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void update();
    void setPosition();
    void Tap();
    sf::Sprite GetBirdSprite();
private:
    int iter;
    std::vector<sf::Texture> _birdTextures;
    sf::Sprite _birdSprite;

    sf::Clock _clock;
    sf::Clock _movementClock;

    int _birdState;
    float _rotation;
};


#endif //SFML_PROJECT_BIRD_H
