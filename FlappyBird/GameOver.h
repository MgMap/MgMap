//
// Created by minau on 12/7/2022.
//

#ifndef SFML_PROJECT_GAMEOVER_H
#define SFML_PROJECT_GAMEOVER_H
#include "DEFINITIONS.h"
#include "States.h"
#include <SFML/Graphics.hpp>
#include "Textures.h"

class GameOver : public sf::Drawable , public States
        {
        public:
            GameOver();
            void init();
            void update();
            void draw(sf::RenderTarget &target, sf::RenderStates states) const;
private:
            sf::Sprite gameOver;
            sf::Clock clock;
};


#endif //SFML_PROJECT_GAMEOVER_H
