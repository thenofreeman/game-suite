#pragma once

#include <SFML/Graphics.hpp>

#include "Engine.h"
#include "State.h"

class GameState : public State
{
    public:
        GameState(StateStack& stack, Context context);
        virtual ~GameState();

        virtual void draw();
        virtual bool update(sf::Time deltaTime);
        virtual bool handleEvent(const sf::Event& event);

        Engine* engine;

};
