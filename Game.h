#pragma once

#include <string>
#include <array>

#include <SFML/Graphics.hpp>

#include "Player.h"
#include "Ball.h"

class Game
{
    public:
        Game(const std::string& title);
        virtual ~Game();

        void run();

    private:
        std::string title;
        sf::RenderWindow window;
        sf::Vector2f windowSize;

        sf::Time deltaTime;
        sf::Time timePerFrame;

        int scores[2];
        Player* players[2];
        Player* localPlayer;
        Ball ball;

        void processEvents();
        void update();
        void render();

        void updatePlayer(Player* pl);
};
