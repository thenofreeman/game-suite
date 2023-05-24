#pragma once

#include <SFML/Graphics.hpp>

class Engine
{
    public:
        Engine(sf::RenderWindow& window);
        virtual ~Engine();

        virtual void handleEvent(const sf::Event& event) = 0;
        virtual void update(sf::Time deltaTime) = 0;
        virtual void draw() = 0;

    protected:
        sf::RenderWindow* window;

};
