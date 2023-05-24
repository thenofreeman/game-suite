#pragma once

#include <SFML/Graphics.hpp>

class Player : public sf::Drawable, public sf::Transformable
{
    public:
        Player();
        virtual ~Player();

        void processEvents();
        void update(const sf::Time& deltaTime);

        sf::RectangleShape getShape();

        void setPosition(const sf::Vector2f& position);
        void setPosition(float x, float y);

    private:
        sf::Vector2f velocity;
        sf::RectangleShape shape;

        void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};
