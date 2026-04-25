#include <EditorState.h>

void EditorState::loadState(stateType newType, const AssetManager *mng)
{
	loadSrcMng(mng);
	titleFont = srcMng->getFont("ProggyClean_Large");
	type = newType;
}

void EditorState::update()
{
	// configure the menu state 
#ifdef CONFIG_WINDOW
	ImGui::Begin("Configuration", NULL, ImGuiWindowFlags_AlwaysAutoResize);
	ImGui::InputFloat("Title.x", &titleXmult);
	ImGui::InputFloat("Title.y", &titleYmult);
	ImGui::End();
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
}
