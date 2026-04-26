#include <ProductUI.h>

void UI::loadUI(GLFWwindow *window)
{
	// load interface library
	IMGUI_CHECKVERSION();

	ImGui::CreateContext();

	if(!ImGui_ImplGlfw_InitForOpenGL(window, true)){
		std::cout << "Failed to implemet ImGui to GLFW" << std::endl;
		abort();
	}

	if(!ImGui_ImplOpenGL3_Init("#version 330")){
		std::cout << "Failed to implement ImGui to OpenGL3" << std::endl;
		abort();
	}
}

void UI::newFrame()
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
}

void UI::render()
{
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void UI::shutdownUI()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
}

void UI::drawLabel(const char *text, ImFont *font, const ImVec2 position, const ImU32 color)
{
	ImGuiViewport *viewport = ImGui::GetMainViewport();
	ImVec2 windowCenter = ImVec2(viewport->GetCenter());
	ImVec2 windowSize = ImVec2(viewport->Size);

	ImGui::PushFont(font);

	ImVec2 textSize = ImGui::CalcTextSize(text);

	float startXPos = windowCenter.x - textSize.x / 2;
	float startYPos = windowCenter.y - textSize.y / 2;
	float textXPos = startXPos + windowSize.x / 2 * position.x;
	float textYPos = startYPos + windowSize.y / 2 * position.y;

	ImDrawList *drawList = ImGui::GetBackgroundDrawList();
	drawList->AddText(ImVec2(textXPos, textYPos), color, text);

	ImGui::PopFont();
}

bool UI::drawButton(
		const char *text,
	   	ImFont *font,
	   	const ImVec2 position,
		const ImVec2 &size,
	   	const ImU32 color_bg,
		const ImU32 color_hover,
		const ImU32 color_text
		)
{
	ImGuiViewport *viewport = ImGui::GetMainViewport();
	ImVec2 windowCenter = ImVec2(viewport->GetCenter());
	ImVec2 windowSize = ImVec2(viewport->Size);

	float btnXPos = windowCenter.x - size.x / 2 + windowSize.x / 2 * position.x;
	float btnYPos = windowCenter.y - size.y / 2 + windowSize.y / 2 * position.y;

	ImVec2 minPos = ImVec2(btnXPos, btnYPos);
	ImVec2 maxPos = ImVec2(btnXPos + size.x , btnYPos + size.y);
	ImRect btnRect(minPos, maxPos);

	bool hovered = btnRect.Contains(ImGui::GetMousePos());
	bool clicked = hovered && ImGui::IsMouseClicked(ImGuiMouseButton_Left);

	ImDrawList *drawList = ImGui::GetBackgroundDrawList();

	ImU32 bg = hovered ? color_hover : color_bg;
	drawList->AddRectFilled(minPos, maxPos, bg, 6.0f);


	ImGui::PushFont(font);

	ImVec2 textSize = ImGui::CalcTextSize(text);
	float textXPos = windowCenter.x - textSize.x / 2 + windowSize.x / 2 * position.x;
	float textYPos = windowCenter.y - textSize.y / 2 + windowSize.y / 2 * position.y;

	drawList->AddText(ImVec2(textXPos, textYPos), color_text, text);

	ImGui::PopFont();

	
	return clicked;
}
