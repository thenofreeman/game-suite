#pragma once

#include <SFML/Graphics.hpp>

class Block : public sf::Drawable, public sf::Transformable
{
    public:
        Block();
        virtual ~Block();

        void update(const sf::Time& frameTime);

        void setPosition(const sf::Vector2f& position);
        void setPosition(float x, float y);

    private:
        // sf::Color color;
        sf::RectangleShape shape;

        sf::Vector2f prevPosition;
        sf::Vector2i blockSize;

        void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};
