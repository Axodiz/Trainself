#ifndef ISTATE_H
#define ISTATE_H

#include <AssetManager.h>
#include <ProductUI.h>

enum stateType {
	STATE_MAIN,
	STATE_EDITOR,
	DEFAULT
};

class IState
{
public:
	virtual void loadState(stateType new_type, const AssetManager *mng) = 0;
	virtual void update() = 0;

	void reset_isChange() { is_change = false; }

	bool get_isChange() const { return is_change; }
	stateType getType() const { return type; }
	stateType getChangeType() const { return changeState; }

protected:
	void loadSrcMng(const AssetManager *mng) { srcMng = mng; }

	stateType type = DEFAULT;
	const AssetManager *srcMng = NULL;
	bool is_change = false;
	stateType changeState = DEFAULT;
};

#endif
