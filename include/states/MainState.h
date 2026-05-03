#ifndef MAINSTATE_H
#define MAINSTATE_H

#include <states/IState.h>

class MainState : public IState
{
public:
	using IState::IState;
	void update() override;
	
private:
	// menu elements
	// title
	const char *m_titleText = "TRAINSELF";
	const char *m_titleFont = "ProggyClean_Large";
	struct UI::Label m_titleLabel {
		{0.0f, -0.75f}, // pos
		{255, 255, 255, 255} // color
	};

	// buttons
	const char *m_btnText = "to editor";
	const char *m_btnFont = "ProggyClean_Default";
	struct UI::Color m_btnColorText {255, 255, 255, 255};
	struct UI::Btn m_btn {
		// rect
		{
			{63, 255, 63, 255}, // color
			{0.0f, 0.0f}, // pos
			{120, 40}, // size
			20.0f // round
		},
		{127, 255, 127, 255}, // hover
		{255, 255, 255, 255} // text color
	};
};

#endif
