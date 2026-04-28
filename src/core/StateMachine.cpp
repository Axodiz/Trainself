#include <StateMachine.h>
#include <iostream>

void StateMachine::update()
{
	m_currentState->update();
	if(m_currentState->getChanged()){
		m_currentState->resetChanged();
		changeState(m_currentState->getChangeType());
	}
}

void StateMachine::changeState(StateType stateType)
{
	auto it = m_states.find(stateType);
	if(it == m_states.end()){

		IState *newState;
		switch(stateType)
		{
		case STATE_MAIN:
			newState = new MainState();
			break;
		case STATE_EDITOR:
			newState = new EditorState();
			break;
		case STATE_DEFAULT:
		default:
			newState = NULL;
			std::cout << "STATE_MACHINE : CHANGE DEFAULT" << std::endl;
			break;
		}
		
		newState->loadState(stateType, m_srcMng);
		m_states[stateType] = newState;
	}

	m_currentState = m_states[stateType];
}
