//
// Created by minau on 12/6/2022.
//

#ifndef SFML_PROJECT_SCORES_H
#define SFML_PROJECT_SCORES_H
#include "DEFINITIONS.h"
#include "Fonts.h"
#include "States.h"
#include <SFML/Graphics.hpp>

class Scores :public sf::Drawable , public States
        {
        public:
            Scores();
            void init();
            void update(int scores);
            void draw(sf::RenderTarget &target, sf::RenderStates states) const;
        private:
            //int score;
            sf::Text text;

};


#endif //SFML_PROJECT_SCORES_H
