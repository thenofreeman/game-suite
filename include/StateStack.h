#pragma once

#include <SFML/Graphics.hpp>

#include "State.h"
#include "StateID.h"

class StateStack : private sf::NonCopyable
{
    public:
        enum class Action
        {
            Push, Pop, Clear,
        };

        explicit StateStack(State::Context context);
        virtual ~StateStack();

        void handleEvent(const sf::Event& event);
        void update(sf::Time deltaTime);
        void draw();

        template <typename T>
        void registerState(StateID stateID);

        void pushState(StateID stateID);
        void popState();
        void clearStates();

        bool isEmpty() const;

    private:
        std::vector<std::unique_ptr<State>> states;

        State::Context context;
        std::map<StateID, std::function<std::unique_ptr<State>()>> factories;

        std::unique_ptr<State> createState(StateID stateID);
        void applyPendingChanges();

        struct PendingChange
        {
            explicit PendingChange(Action action, StateID stateID = StateID::None);

            Action action;
            StateID stateID;
        };

        std::vector<PendingChange> pendingList;

};

template <typename StateType>
void StateStack::registerState(StateID stateID)
{
    factories[stateID] = [this]() {
        return std::unique_ptr<State>(new StateType(*this, context));
    };
}
