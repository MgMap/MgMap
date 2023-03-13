
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.h"
#include "GameState.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_LENGTH, 60), "Test");
    GameState gameState;

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
            gameState.eventHandler(window,event);
        }
        window.clear(sf::Color::Black);
        window.draw(gameState);
        gameState.update();
        window.display();
    }
    return 0;
}
