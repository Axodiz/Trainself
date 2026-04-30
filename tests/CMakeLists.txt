add_executable(run_tests
	test_StateMachine.cpp
)

target_link_libraries(run_tests
	PRIVATE
		GTest::gtest_main
		srcLib
)

include(GoogleTest)
gtest_discover_tests(run_tests)
