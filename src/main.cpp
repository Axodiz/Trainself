#include <imgui.h>
#include <imgui_impl_opengl3.h>
#include <imgui_impl_glfw.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <StateMachine.h>
#include <ProductUI.h>

#include <iostream>

int main(){

	glfwInit();

	// get current monitor parameters and set their to window
	GLFWmonitor *monitor = glfwGetPrimaryMonitor();
	const GLFWvidmode *mode = glfwGetVideoMode(monitor);

	glfwWindowHint(GLFW_RED_BITS, mode->redBits);
	glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
	glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
	glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);

	GLFWwindow *window = glfwCreateWindow(mode->width, mode->height, "Trainself", monitor, NULL);
	if(!window){
		std::cout << "Failed to create window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
		std::cout << "Failed to load GLAD" << std::endl;
		glfwTerminate();
		return -1;
	}

	UI::loadUI(window);

	float fontSizeDefault = 16.0f;
	ImFont *fontDefault = ImGui::GetIO().Fonts->AddFontFromFileTTF("fonts/ProggyClean.ttf", fontSizeDefault);
	ImFont *fontTitle = ImGui::GetIO().Fonts->AddFontFromFileTTF("fonts/ProggyClean.ttf", fontSizeDefault * 4);

	ImGui::StyleColorsDark();

	StateMachine state_machine;
	state_machine.loadFont(fontTitle, "ProggyClean_Large");
	state_machine.loadFont(fontDefault, "ProggyClean_Default");

	state_machine.change(STATE_EDITOR);
	state_machine.change(STATE_MAIN);

	// render loop
	while(!glfwWindowShouldClose(window)){

		glfwPollEvents();

		if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
			glfwSetWindowShouldClose(window, true);
		}

		UI::newFrame();

		// load application state
		state_machine.update();

		// draw interface and events
		int display_w, display_h;
		glfwGetFramebufferSize(window, &display_w, &display_h);
		glViewport(0, 0, display_w, display_h);
		glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		UI::render();

		glfwSwapBuffers(window);

	}

	UI::shutdownUI();

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
	
}
