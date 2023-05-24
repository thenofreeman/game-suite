#include "Pong/Player.h"

Player::Player()
    : shape{sf::Vector2f(100, 10)},
      velocity{200, 0}
{ }

Player::~Player()
{ }

sf::RectangleShape Player::getShape()
{
    return shape;
}

void Player::setPosition(const sf::Vector2f& position)
{
    sf::Transformable::setPosition(position);
    shape.setPosition(position);
}

void Player::setPosition(float x, float y)
{
    setPosition(sf::Vector2f(x, y));
}

void Player::update(const sf::Time& deltaTime)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
        setPosition(getPosition().x - velocity.x * deltaTime.asSeconds(), getPosition().y);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
        setPosition(getPosition().x + velocity.x * deltaTime.asSeconds(), getPosition().y);
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // states.transform *= getTransform();
    target.draw(shape, states);
}
