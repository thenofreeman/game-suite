#include "Ball.h"

#include <cstdlib>

Ball::Ball()
    : shape{5},
      velocity{150, 150}
{
    reset();
    std::srand(std::time(nullptr));
}

Ball::~Ball()
{ }

sf::Vector2f Ball::getVelocity()
{
    return velocity;
}

void Ball::setVelocity(const sf::Vector2f& velocity)
{
    this->velocity = velocity;
}

sf::CircleShape Ball::getShape()
{
    return shape;
}

void Ball::setPosition(const sf::Vector2f& position)
{
    sf::Transformable::setPosition(position);
    shape.setPosition(position);
}

void Ball::setPosition(float x, float y)
{
    setPosition(sf::Vector2f(x, y));
}

void Ball::reset()
{
    sf::Vector2f randomPosition (400.f + (std::rand() % 200 +1), 200.f + (std::rand() % 100 +1));
    velocity = velocity * (std::rand() % 2 == 0 ? -1.f : 1.f);
    setPosition(randomPosition);
}

void Ball::update(const sf::Time& deltaTime)
{
    setPosition(getPosition() + velocity * deltaTime.asSeconds());
}

void Ball::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // states.transform *= getTransform();
    target.draw(shape, states);
}
