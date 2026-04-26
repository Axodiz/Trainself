#include <MainState.h>

void MainState::loadState(stateType newType, const AssetManager *mng)
{
	loadSrcMng(mng);
	titleFont = srcMng->getFont("ProggyClean_Large");
	defaultFont = srcMng->getFont("ProggyClean_Default");
	type = newType;
}

void MainState::update()
{
	// configure the menu state 
#ifdef CONFIG_WINDOW
	ImGui::PushFont(defaultFont);
	ImGui::Begin("Configuration", NULL, ImGuiWindowFlags_AlwaysAutoResize);
	ImGui::InputFloat("TitlePos.x", &titleXPos);
	ImGui::InputFloat("TitlePos.y", &titleYPos);
	ImGui::InputFloat("ButtonPos.x", &btnXPos);
	ImGui::InputFloat("ButtonPos.y", &btnYPos);
	ImGui::InputInt("ButtonSize.x", &btnXSize);
	ImGui::InputInt("ButtonSize.y", &btnYSize);
	ImGui::End();
	ImGui::PopFont();
#endif

	UI::drawLabel(titleText, titleFont, ImVec2(titleXPos, titleYPos), titleColor);

	if(UI::drawButton(
			btnText,
			btnFont,
			ImVec2(btnXPos, btnYPos),
			ImVec2(btnXSize, btnYSize),
			btnColor_bg,
			btnColor_hover,
			btnColor_text
			)){
		is_change = true;
		changeState = STATE_EDITOR;
	}
}
