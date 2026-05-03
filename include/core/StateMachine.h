#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include <unordered_map>
#include <memory>

#include <states/IState.h>
#include <states/MainState.h>
#include <states/EditorState.h>

class StateMachine
{
public:
	StateMachine() = default;

	// update current state
	// if current state == null; do nothing
	// if current state set changed flag; change to another state
	void update();

	// change current state to stateType
	// if stateType == STATE_DEFAULT; do nothing
	void changeState(StateType stateType);

#ifdef DEBUG_TESTS
	const std::unique_ptr<IState> &getCurrentState() const
	{
		return m_currentState;
	}
#endif

private:
	std::unique_ptr<IState> m_currentState{nullptr};
	std::unordered_map<StateType, std::unique_ptr<IState>> m_states;
};

#endif
