//
// Created by minau on 2/14/2023.
//

#ifndef SFML_PROJECT_BUTTON_H
#define SFML_PROJECT_BUTTON_H
#include <SFML/Graphics.hpp>
#include "Font.h"
#include "Helper.h"
#include "MouseEvents.h"

class Button : public sf::Drawable
{
private:
    sf::CircleShape circle;
    sf::Text text;
    sf::Color original = {255, 149, 0}, originalText = sf::Color::White, hovered = sf::Color::Cyan, hoverText;
public:
    Button();
    Button(const std::string& text);
    Button(const std::string& text, const sf::Color& textColor,const sf::Color& backgroundColor);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void setBackgroundColor(const sf::Color& color);
    void setTextColor(const sf::Color& color);
    void setText(const std::string& text);
    const std::string& getText() const;
    const void setPosition(sf::Vector2f position);
    void setRadius(float radius);

    sf::FloatRect getGlobalBounds();
    void eventHandler(sf::RenderWindow& window, sf::Event event);

    void init(const std::string &text, const sf::Color &color, const sf::Color &color1);
};


#endif //SFML_PROJECT_BUTTON_H
