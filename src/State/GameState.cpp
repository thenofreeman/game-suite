#include "GameState.h"

#include "Pong/PongEngine.h"
#include "Snake/SnakeEngine.h"

GameState::GameState(StateStack& stack, Context context)
    : State{stack, context},
      engine{new SnakeEngine(*context.window)}
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
