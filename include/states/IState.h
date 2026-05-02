#ifndef ISTATE_H
#define ISTATE_H

#include <core/ProductUI.h>

enum StateType {
	STATE_MAIN,
	STATE_EDITOR,
	STATE_DEFAULT
};

class IState
{
public:
	IState(StateType type) { m_stateType = type; }

	virtual void update() = 0;

	void resetChanged() { m_changed = false; }

	bool getChanged() const { return m_changed; }
	StateType getType() const { return m_stateType; }
	StateType getChangeType() const { return m_stateChange; }

protected:
	StateType m_stateType = STATE_DEFAULT;
	bool m_changed = false;
	StateType m_stateChange = STATE_DEFAULT;
};

#endif
