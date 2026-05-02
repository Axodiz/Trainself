#ifndef PRODUCTUI_H
#define PRODUCTUI_H

#include <cstdint>

#include <imgui.h>
#include <imgui_internal.h>
#include <imgui_impl_opengl3.h>
#include <imgui_impl_glfw.h>

#include <GLFW/glfw3.h>

namespace UI
{
	// utilities structs
	struct Color {
		uint8_t r;
		uint8_t g;
		uint8_t b;
		uint8_t a;
	};

	// utilities functions
	void loadUI(GLFWwindow *window);
	void createNewFrame();
	void render();
	void shutdownUI();

	// draw functions
	void drawLabel(const char *text, const char *font, float XPos, float YPos, struct Color color);
	bool drawButton(
			const char *text,
		   	const char *font,
			float XPos,
			float YPos,
			int XSize,
			int YSize,
			struct Color colorBG,
			struct Color colorHover,
			struct Color colorText
			);
}

#endif
