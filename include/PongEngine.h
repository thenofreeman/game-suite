#pragma once

#include <SFML/Graphics.hpp>

#include "Engine.h"
#include "Pong/Player.h"
#include "Pong/Ball.h"

class PongEngine : public Engine
{
    public:
        PongEngine(sf::RenderWindow& window);
        virtual ~PongEngine();

        virtual void handleEvent(const sf::Event& event);
        virtual void update(sf::Time deltaTime);
        virtual void draw();

    private:
        sf::RenderWindow* window;

        int scores[2];
        Player* players[2];
        Player* localPlayer;
        Ball ball;


};
