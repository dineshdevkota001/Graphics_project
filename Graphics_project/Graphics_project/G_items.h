#pragma once
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<iostream>

using namespace std;

class G_items
{
	const char *vertexShaderSource = "#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"void main()\n"
		"{\n"
		"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"}\0";

	//Fragment shader in GLSL

	const char *fragmentShaderSource = "#version 330 core\n"
		"out vec4 FragColor;\n"
		"void main()\n"
		"{\n"
		"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
		"}\n\0";

	GLuint vertexShader, fragmentShader, shaderProgram;
	unsigned int VBO, VAO;

public:
	
	G_items();

	void compileVS();
	void compileFS();
	void attachShaders();
	void bindAll();
	void deleteAll();
	void useprogram();

	~G_items();
};

