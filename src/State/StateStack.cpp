#include "StateStack.h"

#include <cassert>

StateStack::StateStack(State::Context context)
    : states{},
      pendingList{},
      context{context},
      factories{}
{ }

StateStack::~StateStack()
{ }

void StateStack::handleEvent(const sf::Event& event)
{
    for (auto itr = states.rbegin(); itr != states.rend(); ++itr)
	{
		if (!(*itr)->handleEvent(event))
			break;
	}

    applyPendingChanges();
}

void StateStack::update(sf::Time deltaTime)
{
    for (auto itr = states.rbegin(); itr != states.rend(); ++itr)
	{
		if (!(*itr)->update(deltaTime))
			break;
	}

    applyPendingChanges();
}

void StateStack::draw()
{
    for (std::unique_ptr<State>& state : states)
        state->draw();
}

void StateStack::pushState(StateID stateID)
{
    pendingList.push_back(PendingChange(Action::Push, stateID));
}

void StateStack::popState()
{
    pendingList.push_back(PendingChange(Action::Pop));
}

void StateStack::clearStates()
{
    pendingList.push_back(PendingChange(Action::Clear));
}

bool StateStack::isEmpty() const
{
    return states.empty();
}

std::unique_ptr<State> StateStack::createState(StateID stateID)
{
    auto found = factories.find(stateID);
    assert (found != factories.end());

    return found->second();
}

void StateStack::applyPendingChanges()
{
    for (PendingChange change : pendingList)
    {
        switch (change.action)
        {
            case Action::Push:
                states.push_back(createState(change.stateID));
                break;
            case Action::Pop:
                states.pop_back();
                break;
            case Action::Clear:
                states.clear();
                break;
        }
    }

    pendingList.clear();
}

StateStack::PendingChange::PendingChange(Action action, StateID stateID)
    : action{action},
      stateID{stateID}
{ }
