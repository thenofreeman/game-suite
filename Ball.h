#pragma once

#include <SFML/Graphics.hpp>

class Ball : public sf::Drawable, public sf::Transformable
{
    public:
        Ball();
        virtual ~Ball();

        void processEvents();
        void update(const sf::Time& deltaTime);

        sf::Vector2f getVelocity();
        void setVelocity(const sf::Vector2f& velocity);
        sf::CircleShape getShape();

        void setPosition(const sf::Vector2f& position);
        void setPosition(float x, float y);

        void reset();

    private:
        sf::Vector2f velocity;
        sf::CircleShape shape;

        void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};
