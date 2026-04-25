#include <StateMachine.h>

void StateMachine::loadFont(ImFont *font, std::string name)
{
	srcMng.loadFont(font, name);
}

void StateMachine::update()
{
	currentState->update();
	if(currentState->get_isChange()){
		currentState->reset_isChange();
		change(currentState->getChangeType());
	}
}

void StateMachine::change(stateType type)
{
	auto it = states.find(type);
	if(it == states.end()){

		IState *newState;
		switch(type)
		{
		case STATE_MAIN:
			newState = new MainState();
			break;
		case STATE_EDITOR:
			newState = new EditorState();
			break;
		case DEFAULT:
		default:
			newState = NULL;
			std::cout << "STATE_MACHINE : CHANGE DEFAULT" << std::endl;
			break;
		}
		
		newState->loadState(type, &srcMng);
		states[type] = newState;
	}

	currentState = states[type];
}
