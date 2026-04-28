#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include <unordered_map>
#include <memory>

#include <IState.h>
#include <MainState.h>
#include <EditorState.h>

class StateMachine
{
public:
	StateMachine(std::shared_ptr<AssetManager> srcMng){ m_srcMng = srcMng; }

	void update();
	void changeState(StateType stateType);

private:
	std::unique_ptr<IState> m_currentState{nullptr};
	std::unordered_map<StateType, std::unique_ptr<IState>> m_states;
	std::shared_ptr<AssetManager> m_srcMng{nullptr};
};

#endif
