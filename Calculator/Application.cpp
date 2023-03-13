//
// Created by minau on 2/14/2023.
//

#include "Application.h"
#include "Base.h"
#include "Typing.h"

void Application::run()
{
    Base b;
    Typing t;
    //plus.Button::setPosition({50,50});
    sf::RenderWindow window({300,550,32}, "Calculator");
    while( window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(sf::Event::Closed == event.type)
                window.close();

            b.eventHandler(window,event);
            t.addEventHandler(window,event);
        }
        t.update();
        window.clear();
        window.draw(b);
        window.draw(t);
        window.display();
    }
}
