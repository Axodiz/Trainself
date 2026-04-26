#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include <IState.h>

#include <MainState.h>
#include <EditorState.h>

#include <unordered_map>

class StateMachine
{
public:
	StateMachine() = default;
	void loadFont(ImFont *font, std::string name);
	void update();
	void change(stateType type);

private:
	IState *currentState = NULL;
	std::unordered_map<stateType, IState *> states;
	AssetManager srcMng;
};

#endif
