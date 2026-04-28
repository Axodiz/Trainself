#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include <unordered_map>

#include <IState.h>
#include <MainState.h>
#include <EditorState.h>

class StateMachine
{
public:
	StateMachine() = default;
	void loadFont(ImFont *font, std::string name);
	void update();
	void changeState(StateType stateType);

private:
	IState *m_currentState = NULL;
	std::unordered_map<StateType, IState *> m_states;
	AssetManager m_srcMng;
};

#endif
