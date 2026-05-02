#ifndef MAINSTATE_H
#define MAINSTATE_H

#include <states/IState.h>

class MainState : public IState
{
public:
	using IState::IState;
	void update() override;
	
private:
	// menu parameters
	// title
	const char *m_titleText = "TRAINSELF";
	const char *m_titleFont = "ProggyClean_Large";
	struct UI::Color m_titleColor {255, 255, 255, 255};
	float m_titleXPos = 0.0f;
	float m_titleYPos = -0.75f;

	// buttons
	const char *m_btnText = "to editor";
	const char *m_btnFont = "ProggyClean_Default";
	float m_btnXPos = 0.0f;
	float m_btnYPos = 0.0f;
	int m_btnXSize = 120;
	int m_btnYSize = 40;
	struct UI::Color m_btnColorBG {63, 255, 63, 255};
	struct UI::Color m_btnColorHover {127, 255, 127, 255};
	struct UI::Color m_btnColorText {255, 255, 255, 255};
};

#endif
