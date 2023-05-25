#include "Snake/Snake.h"

Snake::Snake()
    : body{new Block()},
      head{body.front()},
      velocity{100, 100}
{ }

Snake::~Snake()
{ }

void processEvent(const sf::Event& event)
{

}

void Snake::update(const sf::Time& deltaTime)
{
    Block* block = body.front();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
    {
        block->setPosition(block->getPosition().x, block->getPosition().y - velocity.y * deltaTime.asSeconds());
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
    {
        block->setPosition(block->getPosition().x, block->getPosition().y + velocity.y * deltaTime.asSeconds());
    }
    else
    { }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        block->setPosition(block->getPosition().x - velocity.x * deltaTime.asSeconds(), block->getPosition().y);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        block->setPosition(block->getPosition().x + velocity.x * deltaTime.asSeconds(), block->getPosition().y);
    }
    else
    { }

    Block* prev = block;
    for (Block* block : body)
    {
        block->setPosition(prev->getPosition());
        prev = block;
    }
}

void Snake::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (Block* b : body)
        target.draw(*b);
}
