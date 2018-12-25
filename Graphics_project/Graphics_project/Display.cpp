#include "Display.h"



Display::Display(int WIDTH, int HEIGHT)
	:width(WIDTH), height(HEIGHT)
{}

int Display::create_window(){
	
	if (!glfwInit()) {
		cout << "GLFW NOT INITIATED!!!" << endl;
	}

	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	//glfwWindowHint(GLFW_CONTEXT_REVISION, 0);

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
		Display::processInput();
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
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
	if (glfwGetKey(window, GLFW_KEY_ENTER)==GLFW_PRESS)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}


void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

Display::~Display()
{
}
