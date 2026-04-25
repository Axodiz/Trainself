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
	ImGui::InputFloat("Title.x", &titleXmult);
	ImGui::InputFloat("Title.y", &titleYmult);
	ImGui::End();
	ImGui::PopFont();
#endif

	ImGuiViewport *viewport = ImGui::GetMainViewport();
	ImVec2 windowPos = ImVec2(viewport->Pos);
	ImVec2 windowSize = ImVec2(viewport->Size);

	// creating application title
	ImGui::PushFont(titleFont);

	ImVec2 textSize = ImGui::CalcTextSize(title);

	float titleXPos = windowSize.x / 2 * titleXmult;
	float titleYPos = windowSize.y / 2 * titleYmult;
	float textXPos = windowPos.x + windowSize.x / 2 - textSize.x / 2 + titleXPos;
	float textYPos = windowPos.y + windowSize.y / 2 - textSize.y / 2 + titleYPos;
	ImVec2 textPos = ImVec2(textXPos, textYPos);

	ImDrawList *drawList = ImGui::GetBackgroundDrawList();
	drawList->AddText(textPos, titleColor, title);

	ImGui::PopFont();


	ImGui::PushFont(defaultFont);

	ImGui::SetNextWindowPos(viewport->GetCenter());
	ImGui::SetNextWindowSize(ImVec2(0.0f, 0.0f));
	ImGui::Begin(
			"HIDDEN_WINDOW",
			NULL,
			ImGuiWindowFlags_NoSavedSettings |
			ImGuiWindowFlags_NoMove |
			ImGuiWindowFlags_NoTitleBar |
			ImGuiWindowFlags_NoResize |
			ImGuiWindowFlags_NoNav |
			ImGuiWindowFlags_NoBackground |
			ImGuiWindowFlags_NoFocusOnAppearing
			);
	if(ImGui::Button("to editor")){
		is_change = true;
		changeState = STATE_EDITOR;
	}
	ImGui::End();

	ImGui::PopFont();
}
