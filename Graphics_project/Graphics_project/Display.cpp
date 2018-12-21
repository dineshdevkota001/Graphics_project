#include "Display.h"



Display::Display(int WIDTH, int HEIGHT)
	:width(WIDTH), height(HEIGHT)
{}

int Display::create_window(){
	
	if (!glfwInit()) {
		cout << "GLFW NOT INITIATED!!!" << endl;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	cout << "loaded glfw contexts" << endl;

	window = glfwCreateWindow(width, height, "OpenGL Viewport", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	cout << "window made" << endl;
	
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}
	cout << "glad initiated!!!" << endl;
	Display::refresh_window();
	return 0;
}

int Display::entrypoint()
{
	Display::create_window();
	graphics.attachShaders();
	Display::refresh_window();
	Display::close_window();

	return 0;
}


void Display::refresh_window() {

	graphics.bindAll();

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		graphics.useprogram();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}


void Display::close_window() {

	graphics.deleteAll();
	glfwTerminate();
}


void Display::processInput()
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}


void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

Display::~Display()
{
}
