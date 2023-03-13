//
// Created by minau on 12/1/2022.
//

#ifndef SFML_PROJECT_LAND_H
#define SFML_PROJECT_LAND_H
#include "DEFINITIONS.h"
#include <SFML/Graphics.hpp>
#include "Textures.h"
#include "States.h"

class Land : public sf::Drawable , public States
        {
        public:
            Land();
            void init();
            void draw(sf::RenderTarget &target, sf::RenderStates states) const;
            void animate();
            const std::vector<sf::Sprite> &GetSprites() const;
        private:
            std::vector<sf::Sprite> landSprites;

};


#endif //SFML_PROJECT_LAND_H
