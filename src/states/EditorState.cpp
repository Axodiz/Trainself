#include <states/EditorState.h>

void EditorState::update()
{
	// configure the menu state 
//#ifdef CONFIG_WINDOW
//	ImGui::PushFont(m_fontDefault);
//	ImGui::Begin("Configuration", NULL, ImGuiWindowFlags_AlwaysAutoResize);
//	ImGui::InputFloat("TitlePos.x", &m_titleXPos);
//	ImGui::InputFloat("TitlePos.y", &m_titleYPos);
//	ImGui::InputFloat("ButtonPos.x", &m_btnXPos);
//	ImGui::InputFloat("ButtonPos.y", &m_btnYPos);
//	ImGui::InputInt("ButtonSize.x", &m_btnXSize);
//	ImGui::InputInt("ButtonSize.y", &m_btnYSize);
//	ImGui::End();
//	ImGui::PopFont();
//#endif

	// draw main state
	UI::drawLabel(m_titleText, m_titleFont, m_titleXPos, m_titleYPos, m_titleColor);

	if(UI::drawButton(
			m_btnText,
			m_btnFont,
			m_btnXPos,
		   	m_btnYPos,
			m_btnXSize,
		   	m_btnYSize,
			m_btnColorBG,
			m_btnColorHover,
			m_btnColorText
			)){
		m_changed = true;
		m_stateChange = STATE_MAIN;
	}
}
