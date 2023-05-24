#include "Application.h"

#include "State.h"
#include "StateID.h"

#include "GameState.h"

Application::Application(std::string title, int width, int height)
    : title{title},
      window{sf::VideoMode(width, height), title},
      states{State::Context{window}}
{
    registerStates();
    states.pushState(StateID::Game);
}

Application::~Application()
{ }

void Application::run()
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

void Application::processEvents()
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

void Application::update()
{
    states.update(timePerFrame);
}

void Application::render()
{
    window.clear();

    states.draw();

    window.setView(window.getDefaultView());

    window.display();
}


void Application::registerStates()
{
    states.registerState<GameState>(StateID::Game);
}
