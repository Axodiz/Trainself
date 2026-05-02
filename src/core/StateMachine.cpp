#include <core/StateMachine.h>
#include <iostream>

void StateMachine::update()
{
	if(!m_currentState){
		std::cout << "m_currentState hasn't been initialized" << std::endl;
		return;
	}

	m_currentState->update();
	if(m_currentState->getChanged()){
		m_currentState->resetChanged();
		changeState(m_currentState->getChangeType());
	}
}

void StateMachine::changeState(StateType stateType)
{
	if(stateType == STATE_DEFAULT){
		std::cout << "STATE_MACHINE : CHANGE DEFAULT" << std::endl;
		return;
	}
	if(m_currentState){
		m_states[m_currentState->getType()] = std::move(m_currentState);
	}

	auto it = m_states.find(stateType);
	if(it == m_states.end()){

		std::unique_ptr<IState> newState;
		switch(stateType)
		{
		case STATE_MAIN:
			newState = std::make_unique<MainState>(STATE_MAIN);
			break;
		case STATE_EDITOR:
			newState = std::make_unique<EditorState>(STATE_EDITOR);
			break;
		case STATE_DEFAULT:
		default:
			std::cout << "STATE_MACHINE : CHANGE DEFAULT" << std::endl;
			break;
		}
		
		m_states[stateType] = std::move(newState);
	}

	m_currentState = std::move(m_states[stateType]);
}
