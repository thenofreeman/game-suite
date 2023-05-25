#include "SnakeEngine.h"

SnakeEngine::SnakeEngine(sf::RenderWindow& window)
    : Engine{window}
{ }

SnakeEngine::~SnakeEngine()
{ }

void SnakeEngine::handleEvent(const sf::Event& event)
{
    // snake.processEvent(event);
}

void SnakeEngine::update(sf::Time deltaTime)
{
    snake.update(deltaTime);
}

void SnakeEngine::draw()
{
    window->draw(snake);
}
