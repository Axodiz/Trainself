#ifndef EDITORSTATE_H
#define EDITORSTATE_H

#include <imgui.h>
#include <IState.h>

class EditorState : public IState
{
public:
	void loadState(StateType newType, std::shared_ptr<AssetManager> srcMng) override;
	void update() override;
	
private:
	// menu parameters
	// title
	const char *m_titleText = "EDITOR";
	ImFont *m_titleFont = NULL;
	ImU32 m_titleColor = IM_COL32(255, 255, 255, 255);
	float m_titleXPos = 0.0f;
	float m_titleYPos = -0.75f;

	// buttons
	const char *m_btnText = "to main";
	ImFont *m_btnFont = NULL;
	float m_btnXPos = 0.0f;
	float m_btnYPos = 0.0f;
	int m_btnXSize = 120;
	int m_btnYSize = 40;
	ImU32 m_btnColorBG = IM_COL32(63, 255, 63, 255);
	ImU32 m_btnColorHover = IM_COL32(127, 255, 127, 255);
	ImU32 m_btnColorText = IM_COL32(255, 255, 255, 255);

	ImFont *m_fontDefault = NULL;
};

#endif
