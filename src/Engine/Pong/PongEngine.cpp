#include "PongEngine.h"

PongEngine::PongEngine(sf::RenderWindow& window)
    : Engine{window},
      players{new Player(), new Player()},
      localPlayer{players[0]},
      ball{}
{
    players[0]->setPosition(0, window.getSize().y - 10);
    players[1]->setPosition(0, 0);
}

PongEngine::~PongEngine()
{ }

void PongEngine::handleEvent(const sf::Event& event)
{ }

void PongEngine::update(sf::Time deltaTime)
{
    for (Player* pl : players)
    {
        localPlayer->update(deltaTime);

        if (ball.getShape().getGlobalBounds().intersects(pl->getShape().getGlobalBounds()))
        {
            ball.setVelocity(sf::Vector2f(ball.getVelocity().x, ball.getVelocity().y * -1.f));
        }
    }

    if (ball.getPosition().x <= 0 || ball.getPosition().x >= window->getSize().x - 10)
    {
        ball.setVelocity(sf::Vector2f(ball.getVelocity().x * -1.f, ball.getVelocity().y));
    }
    else if (ball.getPosition().y < 0)
    {
        ball.reset();
        ++scores[0];
    }
    else if (ball.getPosition().y > window->getSize().y)
    {
        ball.reset();
        ++scores[1];
    }

    ball.update(deltaTime);
}

void PongEngine::draw()
{
    for (Player* pl : players)
        window->draw(*pl);

    window->draw(ball);

}
