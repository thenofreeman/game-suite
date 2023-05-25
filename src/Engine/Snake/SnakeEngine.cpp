#include "Snake/SnakeEngine.h"

SnakeEngine::SnakeEngine(sf::RenderWindow& window)
    : Engine{window},
      snake{}
{ }

SnakeEngine::~SnakeEngine()
{ }

void SnakeEngine::handleEvent(const sf::Event& event)
{ }

void SnakeEngine::update(sf::Time deltaTime)
{
    snake.update(deltaTime);
}

void SnakeEngine::draw()
{
    window->draw(snake);
}
