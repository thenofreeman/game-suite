#include "Snake/Block.h"

Block::Block()
    : shape{sf::Vector2f(15.f, 15.f)}
{
    shape.setFillColor(sf::Color::White);
    setPosition(100, 100);
}

Block::~Block()
{ }

void Block::update(const sf::Time& frameTime)
{

}

void Block::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(shape, states);
}

void Block::setPosition(const sf::Vector2f& position)
{
    sf::Transformable::setPosition(position);
    shape.setPosition(position);
}

void Block::setPosition(float x, float y)
{
    setPosition(sf::Vector2f(x, y));
}
