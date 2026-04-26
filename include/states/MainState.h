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
	// title
	const char *titleText = "TRAINSELF";
	ImFont *titleFont = NULL;
	ImU32 titleColor = IM_COL32(255, 255, 255, 255);
	float titleXPos = 0.0f;
	float titleYPos = -0.75f;

	// buttons
	const char *btnText = "to editor";
	ImFont *btnFont = NULL;
	float btnXPos = 0.0f;
	float btnYPos = 0.0f;
	int btnXSize = 120;
	int btnYSize = 40;
	ImU32 btnColor_bg = IM_COL32(63, 255, 63, 255);
	ImU32 btnColor_hover = IM_COL32(127, 255, 127, 255);
	ImU32 btnColor_text = IM_COL32(255, 255, 255, 255);

	ImFont *defaultFont = NULL;
};

#endif
