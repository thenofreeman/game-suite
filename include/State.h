#pragma once

#include <SFML/Graphics.hpp>

#include "StateID.h"

class StateStack;

class State
{
    public:
        struct Context
        {
            Context(sf::RenderWindow& window);

            sf::RenderWindow* window;
        };

        State(StateStack& stateStack, Context context);
        virtual ~State();

        virtual void draw() = 0;
        virtual bool update(sf::Time dt) = 0;
        virtual bool handleEvent(const sf::Event& event) = 0;

        Context getContext() const;

    protected:
        void requestStackPush(StateID stateID);
        void requestStackPop();
        void requestStateClear();

    private:
        StateStack* stateStack;
        Context context;

};
