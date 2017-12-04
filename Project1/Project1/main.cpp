
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <GLFW\glfw3.h>
#include "Solver.h"
#include "MazeCreate.h"
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glfw3.lib")

int main()
{
	MazeCreate m1;
	new Solver(m1.returnMaze(), 2, 1);
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	glOrtho(0, 16, 0, 16, -1.0, 1.0);
	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);
		m1.draw();
		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
		//std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	glfwTerminate();
	getchar();
	getchar();
	return 0;
}

