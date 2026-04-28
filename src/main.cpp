#include <iostream>

#include <imgui.h>
#include <imgui_impl_opengl3.h>
#include <imgui_impl_glfw.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <StateMachine.h>
#include <ProductUI.h>


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

	StateMachine fsm;
	fsm.loadFont(fontTitle, "ProggyClean_Large");
	fsm.loadFont(fontDefault, "ProggyClean_Default");

	fsm.changeState(STATE_EDITOR);
	fsm.changeState(STATE_MAIN);

	// render loop
	while(!glfwWindowShouldClose(window)){

		glfwPollEvents();

		if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
			glfwSetWindowShouldClose(window, true);
		}

		UI::createNewFrame();

		// load application state
		fsm.update();

		// draw interface and events
		int displayWidth, displayHeight;
		glfwGetFramebufferSize(window, &displayWidth, &displayHeight);
		glViewport(0, 0, displayWidth, displayHeight);
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
