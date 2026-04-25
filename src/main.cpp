#include <imgui.h>
#include <imgui_impl_opengl3.h>
#include <imgui_impl_glfw.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <StateMachine.h>

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

	// load interface library
	IMGUI_CHECKVERSION();

	// load style and fonts
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	(void)io;

	float fontSizeDefault = 16.0f;
	ImFont *fontDefault = io.Fonts->AddFontFromFileTTF("fonts/ProggyClean.ttf", fontSizeDefault);
	ImFont *fontTitle = io.Fonts->AddFontFromFileTTF("fonts/ProggyClean.ttf", fontSizeDefault * 4);

	ImGui::StyleColorsDark();

	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 330");

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

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		// load application state
		state_machine.update();

		// draw interface and events
		ImGui::Render();
		int display_w, display_h;
		glfwGetFramebufferSize(window, &display_w, &display_h);
		glViewport(0, 0, display_w, display_h);
		glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		glfwSwapBuffers(window);

	}

	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
	
}
