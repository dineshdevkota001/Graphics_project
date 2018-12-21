#pragma once
#include"G_items.h"

using namespace std;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

class Display
{
private:
	const int width, height;
	G_items graphics;
	GLFWwindow* window;
public:
	Display(int WIDTH,int HEIGHT);
	void processInput();
	void close_window();
	void refresh_window();
	int create_window();
	int entrypoint();
	
	~Display();
};

