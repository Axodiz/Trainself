#include <states/EditorState.h>

void EditorState::update()
{
	// configure the menu state 
#ifdef CONFIG_WINDOW
	UI::configBegin();
	UI::configLabel(m_titleLabel, "title");
	UI::configBtn(m_btn, "btn");
	UI::configEnd();
#endif

	// draw main interface
	UI::drawLabel(m_titleText, m_titleFont, m_titleLabel);

	if(UI::drawButton(m_btn, m_btnText, m_btnFont)){
		m_changed = true;
		m_stateChange= STATE_MAIN;
	}
}
