#ifndef MAINSTATE_H
#define MAINSTATE_H

#include <IState.h>
#include <imgui.h>

class MainState : public IState
{
public:
	void loadState(stateType newType, const AssetManager *mng) override;
	void update() override;
	
private:
	// menu parameters
	const char *title = "TRAINSELF";
	ImFont *titleFont = NULL;
	ImU32 titleColor = IM_COL32(255, 255, 255, 255);
	float titleXmult = 0.0f;
	float titleYmult = -0.75f;

	ImFont *defaultFont = NULL;
};

#endif
