#ifndef PRODUCTUI_H
#define PRODUCTUI_H

#include <string>

#include <imgui.h>
#include <imgui_internal.h>
#include <imgui_impl_opengl3.h>
#include <imgui_impl_glfw.h>

#include <GLFW/glfw3.h>

namespace UI
{
	// utilities structs
	struct Color {
		int r = 0;
		int g = 0;
		int b = 0;
		int a = 0;
	};
	struct Pos {
		float x = 0;
		float y = 0;
	};
	struct Size {
		int x = 0;
		int y = 0;
	};
	struct Rect {
		struct Color color;
		struct Pos pos;
		struct Size size;

		float round = 0;
	};
	//  final structures
	struct Label {
		struct Pos pos;
		struct Color color;
	};
	struct Btn {
		struct Rect rect;
		struct Color hover;	
		struct Color clrText;
	};

	// utilities functions
	void loadUI(GLFWwindow *window);
	void createNewFrame();
	void render();
	void shutdownUI();

	// draw functions
	void drawLabel(const char *text, const char *font, const struct Label &label);
	// if font == nullptr; don't draw text
	bool drawButton(const struct Btn &btn, const char *text = nullptr, const char *font = nullptr);

#ifdef CONFIG_WINDOW
	void configBegin();
	void configEnd();
	void configLabel(struct Label &label, const std::string &name);
	void configBtn(struct Btn &btn, const std::string &name);
#endif
}

#endif
