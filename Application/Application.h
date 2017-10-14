#pragma once

#include <iostream>

#include <GL\glew.h>
#include <GLFW\glfw3.h>

#include "Meshes\Meshes.h"

class Application
{
	public:

		Application();
		~Application();

		void Run();
		
	private:

		GLFWwindow* _window;
		const int _windowWidth = 800;
		const int _windowHeight = 600;
		const char* _windowTitle = "Game Engine";


		void initSystem();
		void createWindow();
		void applicationLoop();

		void framebuffer_size_callback(GLFWwindow* window, int width, int height)
		{
			glViewport(0, 0, width, height);
		}

		void processInput(GLFWwindow* win)
		{
			if (glfwGetKey(win, GLFW_KEY_ESCAPE) == GLFW_PRESS)
				glfwSetWindowShouldClose(win, true);
		}

		Meshes meshes;
};