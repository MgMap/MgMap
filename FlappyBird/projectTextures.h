//
// Created by minau on 12/8/2022.
//

#ifndef SFML_PROJECT_PROJECTTEXTURES_H
#define SFML_PROJECT_PROJECTTEXTURES_H

#include <SFML/Graphics.hpp>
#include <map>
#include "projectEnums.h"

class projectTextures
        {
private:
    static std::map<projectEnums, sf::Texture> map;
    static void load(projectEnums texture);
    static std::string getPath(projectEnums texture);
public:
    static sf::Texture& getTexture(projectEnums texture);
};


#endif //SFML_PROJECT_PROJECTTEXTURES_H
