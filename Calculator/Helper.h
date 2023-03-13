//
// Created by minau on 2/14/2023.
//

#ifndef SFML_PROJECT_HELPER_H
#define SFML_PROJECT_HELPER_H
#include <SFMl/Graphics.hpp>
#include <cmath>

class Helper
{
public:
    template <typename T>
    static void centerText(const T& obj, sf::Text &text);
};

#include "Helper.cpp"
#endif //SFML_PROJECT_HELPER_H
