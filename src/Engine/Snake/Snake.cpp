#include "Snake/Snake.h"

#include <iostream>

Snake::Snake()
    : head{},
      velocity{100, 100}
{ }

Snake::~Snake()
{ }

void processEvent(const sf::Event& event)
{ }

void Snake::update(const sf::Time& deltaTime)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
    {
        head.setPosition(head.getPosition().x, head.getPosition().y - velocity.y * deltaTime.asSeconds());
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
    {
        head.setPosition(head.getPosition().x, head.getPosition().y + velocity.y * deltaTime.asSeconds());
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        head.setPosition(head.getPosition().x - velocity.x * deltaTime.asSeconds(), head.getPosition().y);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        head.setPosition(head.getPosition().x + velocity.x * deltaTime.asSeconds(), head.getPosition().y);
    }
}

void Snake::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(head, states);
}
