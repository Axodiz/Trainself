#ifndef PRODUCTUI_H
#define PRODUCTUI_H

#include <imgui.h>
#include <imgui_internal.h>
#include <imgui_impl_opengl3.h>
#include <imgui_impl_glfw.h>
#include <GLFW/glfw3.h>

#include <iostream>

namespace UI
{
	// utilities functions
	void loadUI(GLFWwindow *window);
	void newFrame();
	void render();
	void shutdownUI();

	// draw functions
	void drawLabel(const char *text, ImFont *font, const ImVec2 position, const ImU32 color);
	bool drawButton(
			const char *text,
		   	ImFont *font,
		   	const ImVec2 position,
			const ImVec2 &size,
		   	const ImU32 color_bg,
			const ImU32 color_hover,
			const ImU32 color_text
			);
}

#endif
