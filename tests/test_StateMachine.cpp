#include <gtest/gtest.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <states/IState.h>
#include <core/ProductUI.h>
#include <core/StateMachine.h>

TEST(StateMachineTest, changeTest)
{
	glfwInit();

	GLFWwindow *window = glfwCreateWindow(800, 600, "test", nullptr, nullptr);
	ASSERT_TRUE(window);
	glfwMakeContextCurrent(window);

	ASSERT_TRUE(gladLoadGLLoader((GLADloadproc)glfwGetProcAddress));

	UI::loadUI(window);

	StateMachine sm;
	EXPECT_EQ(sm.getCurrentState(), nullptr);

	sm.changeState(STATE_DEFAULT);
	EXPECT_EQ(sm.getCurrentState(), nullptr);

	sm.changeState(STATE_MAIN);
	EXPECT_EQ(sm.getCurrentState()->getType(), STATE_MAIN);
	const auto &oldState = sm.getCurrentState();

	sm.changeState(STATE_EDITOR);
	EXPECT_EQ(sm.getCurrentState()->getType(), STATE_EDITOR);

	sm.changeState(STATE_MAIN);

	UI::shutdownUI();
}
