#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include <unordered_map>

#include <IState.h>
#include <MainState.h>
#include <EditorState.h>

class StateMachine
{
public:
	StateMachine(const AssetManager *srcMng)
		: m_srcMng(srcMng){};

	void update();
	void changeState(StateType stateType);

private:
	IState *m_currentState = NULL;
	std::unordered_map<StateType, IState *> m_states;
	const AssetManager *m_srcMng = NULL;
};

#endif
