#include <core/ProductUI.h>

#include <iostream>
#include <memory>

#include <core/AssetManager.h>
#include <loadSourceManager.h>

static std::shared_ptr<AssetManager> srcMng = nullptr;

void UI::loadUI(GLFWwindow *window)
{
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

	srcMng = loadSourceManager();
}

void UI::createNewFrame()
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

void UI::drawLabel(const char *text, const char *font, float XPos, float YPos, struct Color color)
{
	ImGuiViewport *viewport = ImGui::GetMainViewport();
	ImVec2 windowCenter = ImVec2(viewport->GetCenter());
	ImVec2 windowSize = ImVec2(viewport->Size);

	ImGui::PushFont(srcMng->getFont(font));

	ImVec2 textSize = ImGui::CalcTextSize(text);

	float startXPos = windowCenter.x - textSize.x / 2;
	float startYPos = windowCenter.y - textSize.y / 2;
	float textXPos = startXPos + windowSize.x / 2 * XPos;
	float textYPos = startYPos + windowSize.y / 2 * YPos;

	ImColor textColor(color.r, color.g, color.b, color.a);

	ImDrawList *drawList = ImGui::GetBackgroundDrawList();
	drawList->AddText(ImVec2(textXPos, textYPos), textColor, text);

	ImGui::PopFont();
}

bool UI::drawButton(
		const char *text,
	   	const char *font,
		float XPos,
		float YPos,
		int XSize,
		int YSize,
		struct Color colorBG,
		struct Color colorHover,
		struct Color colorText
		)
{
	ImGuiViewport *viewport = ImGui::GetMainViewport();
	ImVec2 windowCenter = ImVec2(viewport->GetCenter());
	ImVec2 windowSize = ImVec2(viewport->Size);

	float btnXPos = windowCenter.x - float(XSize )/ 2 + windowSize.x / 2 * XPos;
	float btnYPos = windowCenter.y - float(YSize) / 2 + windowSize.y / 2 * YPos;

	ImVec2 minPos = ImVec2(btnXPos, btnYPos);
	ImVec2 maxPos = ImVec2(btnXPos + XSize , btnYPos + YSize);
	ImRect btnRect(minPos, maxPos);

	bool hovered = btnRect.Contains(ImGui::GetMousePos());
	bool clicked = hovered && ImGui::IsMouseClicked(ImGuiMouseButton_Left);

	ImDrawList *drawList = ImGui::GetBackgroundDrawList();

	ImColor btnColorHover {colorHover.r, colorHover.g, colorHover.b, colorHover.a};
	ImColor btnColorBG {colorBG.r, colorBG.g, colorBG.b, colorBG.a};
	ImU32 bg = hovered ? btnColorHover : btnColorBG;
	drawList->AddRectFilled(minPos, maxPos, bg, 6.0f);


	ImGui::PushFont(srcMng->getFont(font));

	ImVec2 textSize = ImGui::CalcTextSize(text);
	float textXPos = windowCenter.x - textSize.x / 2 + windowSize.x / 2 * XPos;
	float textYPos = windowCenter.y - textSize.y / 2 + windowSize.y / 2 * YPos;

	ImColor textColor {colorText.r, colorText.g, colorText.b, colorText.a};

	drawList->AddText(ImVec2(textXPos, textYPos), textColor, text);

	ImGui::PopFont();

	
	return clicked;
}
