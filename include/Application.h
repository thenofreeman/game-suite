#pragma once

#include <string>

#include <SFML/Graphics.hpp>

#include "StateStack.h"

class Application
{
    public:
        Application(std::string title, int width, int height);
        virtual ~Application();

        void run();
        void registerStates();

    private:
        std::string title;
        sf::RenderWindow window;

        sf::Time deltaTime;
        sf::Time timePerFrame;

        StateStack states;

        void processEvents();
        void update();
        void render();
};
