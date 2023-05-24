#include "GameState.h"

#include "PongEngine.h"

GameState::GameState(StateStack& stack, Context context)
    : State{stack, context},
      engine{new PongEngine(*context.window)}
{ }

GameState::~GameState()
{ }

void GameState::draw()
{
    engine->draw();
}

bool GameState::update(sf::Time deltaTime)
{
    engine->update(deltaTime);

    return true;
}

bool GameState::handleEvent(const sf::Event& event)
{
    // if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            // requestStackPush(States::Pause);
    // engine->handleEvent(event);

    return true;
}
