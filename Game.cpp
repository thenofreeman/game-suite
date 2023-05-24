#include "Game.h"

Game::Game(const std::string& title)
    : title{title},
      window{sf::VideoMode(900, 600), title},
      windowSize{window.getSize()},
      players{new Player(), new Player()},
      localPlayer{players[0]},
      ball{}
{
    // window.setMouseCursorVisible(false);
    players[0]->setPosition(0, window.getSize().y - 10);
    players[1]->setPosition(0, 0);
}

Game::~Game()
{ }

void Game::run()
{
    sf::Clock clock;

    timePerFrame = sf::seconds(1.0f / 60.0f);
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while (window.isOpen())
    {
        deltaTime = clock.restart();

        processEvents();

        timeSinceLastUpdate += deltaTime;

        while (timeSinceLastUpdate > timePerFrame)
        {
            timeSinceLastUpdate -= timePerFrame;

            processEvents();
            update();
        }

        render();
    }
}

void Game::processEvents()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::Closed:
                window.close();
                break;
            default:
                break;
        }
    }
}

void Game::update()
{
    for (Player* pl : players)
    {
        localPlayer->update(timePerFrame);

        if (ball.getShape().getGlobalBounds().intersects(pl->getShape().getGlobalBounds()))
        {
            ball.setVelocity(sf::Vector2f(ball.getVelocity().x, ball.getVelocity().y * -1.f));
        }
    }

    if (ball.getPosition().x <= 0 || ball.getPosition().x >= window.getSize().x - 10)
    {
        ball.setVelocity(sf::Vector2f(ball.getVelocity().x * -1.f, ball.getVelocity().y));
    }
    else if (ball.getPosition().y < 0)
    {
        ball.reset();
        ++scores[0];
    }
    else if (ball.getPosition().y > window.getSize().y)
    {
        ball.reset();
        ++scores[1];
    }

    ball.update(timePerFrame);
}

void Game::render()
{
    window.clear(sf::Color::Black);

    for (Player* pl : players)
        window.draw(*pl);

    window.draw(ball);

    window.setView(window.getDefaultView());
    window.display();
}
