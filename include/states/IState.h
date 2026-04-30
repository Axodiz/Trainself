#ifndef ISTATE_H
#define ISTATE_H

#include <memory>
#include <core/AssetManager.h>
#include <core/ProductUI.h>

enum StateType {
	STATE_MAIN,
	STATE_EDITOR,
	STATE_DEFAULT
};

class IState
{
public:
	virtual void loadState(StateType newType, std::shared_ptr<AssetManager> srcMng) = 0;
	virtual void update() = 0;

	void resetChanged() { m_changed = false; }

	bool getChanged() const { return m_changed; }
	StateType getType() const { return m_stateType; }
	StateType getChangeType() const { return m_stateChange; }

protected:
	void loadSrcMng(std::shared_ptr<AssetManager> srcMng) { m_srcMng = srcMng; }

	StateType m_stateType = STATE_DEFAULT;
	std::shared_ptr<AssetManager> m_srcMng{nullptr};
	bool m_changed = false;
	StateType m_stateChange = STATE_DEFAULT;
};

#endif
