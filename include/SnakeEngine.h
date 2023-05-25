#pragma once

#include <SFML/Graphics.hpp>

#include "Engine.h"
#include "Snake/Snake.h"

class SnakeEngine : public Engine
{
    public:
        SnakeEngine(sf::RenderWindow& window);
        virtual ~SnakeEngine();

        virtual void handleEvent(const sf::Event& event);
        virtual void update(sf::Time deltaTime);
        virtual void draw();

    private:
        Snake snake;

};
