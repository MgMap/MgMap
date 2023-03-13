//
// Created by minau on 12/1/2022.
//

#ifndef SFML_PROJECT_COLLISIONS_H
#define SFML_PROJECT_COLLISIONS_H
#include <SFML/Graphics.hpp>

class Collisions
        {
        public:

            static bool checkLandCollision(const sf::Sprite &obj1, const sf::Sprite &obj2);
            static bool checkPipeCollision(sf::Sprite onj1, float scale1, sf::Sprite obj2, float scale2);
            static bool checkScoring(const sf::Sprite &obj1, const sf::RectangleShape &obj2);
};


#endif //SFML_PROJECT_COLLISIONS_H
