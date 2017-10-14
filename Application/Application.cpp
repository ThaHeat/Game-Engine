#include "Application.h"
#include "Error.h"

Application::Application()
{
	_window = NULL;
}

Application::~Application()
{
	glfwTerminate();
}

void Application::initSystem()
{
	//Checks if GLFW was initialized
	if (!glfwInit())
	{
		fatalError("GLFW INITIALIZATION FAILED!");
		glfwTerminate();
	}

	createWindow();
	meshes.initMesh();

	glewExperimental = true;	//Enables GLEW experimental features
	if (glewInit() != GLEW_OK)	//Checks if GLEW was initialized
	{
		fatalError("GLEW INITIALIZATION FAILED");
		glfwTerminate();
	}
}

void Application::createWindow()
{
	//GLFW Window hints
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//Creates a window
	_window = glfwCreateWindow(_windowWidth, _windowHeight, _windowTitle, NULL, NULL);
	if (_window == NULL)	//Checks if window was created
	{
		fatalError("FAILED TO CREATE GLFW WINDOW");
		glfwTerminate();
	}

	glfwMakeContextCurrent(_window);
	framebuffer_size_callback(_window, _windowWidth, _windowHeight);
}

void Application::applicationLoop()
{
	while (!glfwWindowShouldClose(_window))
	{
		processInput(_window);

		
		glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		meshes.drawMesh();

		glfwSwapBuffers(_window);
		glfwPollEvents();
	}
}

void Application::Run()
{
	initSystem();
	applicationLoop();
}
