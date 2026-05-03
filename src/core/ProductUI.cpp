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

void UI::drawLabel(const char *text, const char *font, const struct Label &label)
{
	ImGuiViewport *viewport = ImGui::GetMainViewport();
	ImVec2 windowCenter = ImVec2(viewport->GetCenter());
	ImVec2 windowSize = ImVec2(viewport->Size);

	ImGui::PushFont(srcMng->getFont(font));

	ImVec2 textSize = ImGui::CalcTextSize(text);

	float startXPos = windowCenter.x - textSize.x / 2;
	float startYPos = windowCenter.y - textSize.y / 2;
	float textXPos = startXPos + windowSize.x / 2 * label.pos.x;
	float textYPos = startYPos + windowSize.y / 2 * label.pos.y;

	ImColor textColor(label.color.r, label.color.g, label.color.b, label.color.a);

	ImDrawList *drawList = ImGui::GetBackgroundDrawList();
	drawList->AddText(ImVec2(textXPos, textYPos), textColor, text);

	ImGui::PopFont();
}

bool UI::drawButton(const struct Btn &btn, const char *text, const char *font)
{
	ImGuiViewport *viewport = ImGui::GetMainViewport();
	ImVec2 windowCenter = ImVec2(viewport->GetCenter());
	ImVec2 windowSize = ImVec2(viewport->Size);

	float btnXPos = windowCenter.x - float(btn.rect.size.x)/ 2 + windowSize.x / 2 * btn.rect.pos.x;
	float btnYPos = windowCenter.y - float(btn.rect.size.y)/ 2 + windowSize.y / 2 * btn.rect.pos.y;

	ImVec2 minPos = ImVec2(btnXPos, btnYPos);
	ImVec2 maxPos = ImVec2(btnXPos + btn.rect.size.x, btnYPos + btn.rect.size.y);
	ImRect btnRect(minPos, maxPos);

	bool hovered = btnRect.Contains(ImGui::GetMousePos());
	bool clicked = hovered && ImGui::IsMouseClicked(ImGuiMouseButton_Left);

	ImDrawList *drawList = ImGui::GetBackgroundDrawList();

	ImColor btnColorHover {btn.hover.r, btn.hover.g, btn.hover.b, btn.hover.a};
	ImColor btnColorBG {btn.rect.color.r, btn.rect.color.g, btn.rect.color.b, btn.rect.color.a};
	ImU32 bg = hovered ? btnColorHover : btnColorBG;
	drawList->AddRectFilled(minPos, maxPos, bg, btn.rect.round);


	if(font){
		ImGui::PushFont(srcMng->getFont(font));

		ImVec2 textSize = ImGui::CalcTextSize(text);
		float textXPos = windowCenter.x - textSize.x / 2 + windowSize.x / 2 * btn.rect.pos.x;
		float textYPos = windowCenter.y - textSize.y / 2 + windowSize.y / 2 * btn.rect.pos.y;

		ImColor textColor {btn.clrText.r, btn.clrText.g, btn.clrText.b, btn.clrText.a};

		drawList->AddText(ImVec2(textXPos, textYPos), textColor, text);

		ImGui::PopFont();
	}
	
	return clicked;
}

void UI::configBegin()
{
	ImGui::PushFont(srcMng->getFont("ProggyClean_Default"));
	ImGui::Begin("Configuration", NULL, ImGuiWindowFlags_AlwaysVerticalScrollbar);
}

void UI::configEnd()
{
	ImGui::End();
	ImGui::PopFont();
}

void UI::configLabel(struct Label &label, const std::string &name)
{
	ImGui::SliderFloat((name + ".x").c_str(), &label.pos.x, -1.0f, 1.0f);
	ImGui::SliderFloat((name + ".y").c_str(), &label.pos.y, -1.0f, 1.0f);

	ImGui::SliderInt((name + ".red").c_str(), &label.color.r, 0, 255);
	ImGui::SliderInt((name + ".green").c_str(), &label.color.g, 0, 255);
	ImGui::SliderInt((name + ".blue").c_str(), &label.color.b, 0, 255);
	ImGui::SliderInt((name + ".alpha").c_str(), &label.color.a, 0, 255);

	ImGui::Spacing();
}

void UI::configBtn(struct Btn &btn, const std::string &name)
{
	ImGui::SliderInt((name + ".red").c_str(), &btn.rect.color.r, 0, 255);
	ImGui::SliderInt((name + ".green").c_str(), &btn.rect.color.g, 0, 255);
	ImGui::SliderInt((name + ".blue").c_str(), &btn.rect.color.b, 0, 255);
	ImGui::SliderInt((name + ".alpha").c_str(), &btn.rect.color.a, 0, 255);

	ImGui::SliderFloat((name + ".x").c_str(), &btn.rect.pos.x, -1.0f, 1.0f);
	ImGui::SliderFloat((name + ".y").c_str(), &btn.rect.pos.y, -1.0f, 1.0f);

	ImGui::InputInt((name + ".sizeX").c_str(), &btn.rect.size.x);
	ImGui::InputInt((name + ".sizeY").c_str(), &btn.rect.size.y);

	float maxRounding;
	if(btn.rect.size.x >= btn.rect.size.y)
		maxRounding = (float)btn.rect.size.y / 2;
	else
		maxRounding = (float)btn.rect.size.x / 2;
	ImGui::SliderFloat((name + ".rounding").c_str(), &btn.rect.round, 0.0f, maxRounding);

	ImGui::SliderInt((name + ".hoverRed").c_str(), &btn.hover.r, 0, 255);
	ImGui::SliderInt((name + ".hoverGreen").c_str(), &btn.hover.g, 0, 255);
	ImGui::SliderInt((name + ".hoverBlue").c_str(), &btn.hover.b, 0, 255);
	ImGui::SliderInt((name + ".hoverAlpha").c_str(), &btn.hover.a, 0, 255);

	ImGui::SliderInt((name + ".textRed").c_str(), &btn.clrText.r, 0, 255);
	ImGui::SliderInt((name + ".textGreen").c_str(), &btn.clrText.g, 0, 255);
	ImGui::SliderInt((name + ".textBlue").c_str(), &btn.clrText.b, 0, 255);
	ImGui::SliderInt((name + ".textAlpha").c_str(), &btn.clrText.a, 0, 255);
}
