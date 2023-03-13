//
// Created by minau on 12/7/2022.
//

#ifndef SFML_PROJECT_FLASH_H
#define SFML_PROJECT_FLASH_H
#include "DEFINITIONS.h"
#include "States.h"
#include <SFML/Graphics.hpp>

class Flash :public sf::Drawable
        {
        public:
            Flash();
            void init();
            void animate();
            void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        private:
            sf::RectangleShape rectangleShape;
            bool flashOn;
};


#endif //SFML_PROJECT_FLASH_H
