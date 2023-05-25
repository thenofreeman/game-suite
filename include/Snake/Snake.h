#pragma once

#include <list>

#include <SFML/Graphics.hpp>

#include "Snake/Block.h"

class Snake : public sf::Drawable
{
    public:
        Snake();
        virtual ~Snake();

        void processEvent(const sf::Event& event);
        void update(const sf::Time& frameTime);

    private:
        std::list<Block*> body;
        Block* head;
        sf::Vector2f velocity;

        void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};
