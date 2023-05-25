#include "Snake/Block.h"

Block::Block()
    : blockSize{25, 25},
      shape{}
{
    shape.setFillColor(sf::Color(100, 250, 50));
}

Block::~Block()
{ }

void Block::update(const sf::Time& frameTime)
{

}

void Block::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(shape);
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
