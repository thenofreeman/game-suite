#include "State.h"
#include "StateStack.h"

State::Context::Context(sf::RenderWindow& window)
    : window{&window}
{ }

State::State(StateStack& stateStack, Context context)
    : stateStack{&stateStack},
      context{context}
{ }

State::~State()
{ }

void State::requestStackPush(StateID stateID)
{
    stateStack->pushState(stateID);
}

void State::requestStackPop()
{
    stateStack->popState();
}

void State::requestStateClear()
{
    stateStack->clearStates();
}
