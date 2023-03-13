//
// Created by minau on 2/14/2023.
//

#include "Button.h"

Button::Button() : Button("=",sf::Color::White, {255,149,0})
{

}

Button::Button(const std::string &text) : Button(text,sf::Color::White,{212,212,0})
{

}

Button::Button(const std::string &text, const sf::Color &textColor, const sf::Color &backgroundColor)
{
    init(text,textColor,backgroundColor);
}

void Button::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(circle);
    window.draw(text);
}

void Button::setBackgroundColor(const sf::Color &color)
{
    circle.setFillColor(color);
}

void Button::setTextColor(const sf::Color &color)
{
    text.setFillColor(color);
}

void Button::setText(const std::string &text)
{
    this->text.setString(text);
}

const std::string &Button::getText() const
{
    return text.getString();
}

const void Button::setPosition(sf::Vector2f position)
{
    circle.setPosition(position);
    Helper::centerText(circle,this->text);
}

void Button::setRadius(float radius)
{
    circle.setRadius(radius);
}

void Button::init(const std::string &text, const sf::Color &textColor, const sf::Color &backgroundColor)
{
    this->text.setFont(Font::getFont());
    this->text.setString(text);
    this->text.setFillColor(textColor);
    this->text.setCharacterSize(24);
    circle.setRadius(30);
    Helper::centerText(circle,this->text);
    circle.setFillColor(backgroundColor);
}

sf::FloatRect Button::getGlobalBounds()
{
    return circle.getGlobalBounds();
}

void Button::eventHandler(sf::RenderWindow &window, sf::Event event)
{
    if(MouseEvents::isHover(circle,window))
    {
        circle.setFillColor(hovered);
        text.setFillColor(hoverText);
    }
    else
    {
        circle.setFillColor(original);
        text.setFillColor(originalText);
    }

}
