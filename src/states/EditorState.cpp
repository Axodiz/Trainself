#include <EditorState.h>

void EditorState::loadState(StateType newType, const AssetManager *mng)
{
	loadSrcMng(mng);
	m_titleFont = m_srcMng->getFont("ProggyClean_Large");
	m_btnFont = m_srcMng->getFont("ProggyClean_Default");
	m_fontDefault= m_srcMng->getFont("ProggyClean_Default");
	m_stateType = newType;
}

void EditorState::update()
{
	// configure the menu state 
#ifdef CONFIG_WINDOW
	ImGui::PushFont(m_fontDefault);
	ImGui::Begin("Configuration", NULL, ImGuiWindowFlags_AlwaysAutoResize);
	ImGui::InputFloat("TitlePos.x", &m_titleXPos);
	ImGui::InputFloat("TitlePos.y", &m_titleYPos);
	ImGui::InputFloat("ButtonPos.x", &m_btnXPos);
	ImGui::InputFloat("ButtonPos.y", &m_btnYPos);
	ImGui::InputInt("ButtonSize.x", &m_btnXSize);
	ImGui::InputInt("ButtonSize.y", &m_btnYSize);
	ImGui::End();
	ImGui::PopFont();
#endif

	UI::drawLabel(m_titleText, m_titleFont, ImVec2(m_titleXPos, m_titleYPos), m_titleColor);

	if(UI::drawButton(
			m_btnText,
			m_btnFont,
			ImVec2(m_btnXPos, m_btnYPos),
			ImVec2(m_btnXSize, m_btnYSize),
			m_btnColorBG,
			m_btnColorHover,
			m_btnColorText
			)){
		m_changed = true;
		m_stateChange= STATE_MAIN;
	}
}
