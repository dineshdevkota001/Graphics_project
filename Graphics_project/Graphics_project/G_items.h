#pragma once
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include"Fileman.h"

using namespace std;

class G_items
{
	const char *vertexShaderSource = "#version 130 \n"
		"in vec3 aPos;\n"
		"void main()\n"
		"{\n"
		"   gl_Position =vec4(aPos.x,aPos.y,aPos.z,1.0f);\n"
		"}\0";

	//Fragment shader in GLSL

	const char *fragmentShaderSource = "#version 130\n"
		"out vec4 FragColor;\n"
		"void main()\n"
		"{\n"
		"   FragColor = vec4(1.0f,0.5f,0.2f,1.0f);\n"
		"}\0";

	GLuint vertexShader, fragmentShader, shaderProgram;
	unsigned int VBO, VAO, EBO;

	int success;
	char infoLog[512];
	Fileman f;
	float vertices[24] = {
		0.5f,  0.5f, 0.0f,  // top right
		0.5f, -0.5f, 0.0f,  // bottom right
	   -0.5f, -0.5f, 0.0f,  // bottom left
	   -0.5f,  0.5f, 0.0f,
		0.25f,  0.25f, 0.5f,  // top right
		0.25f, -0.25f, 0.5f,  // bottom right
	   -0.25f, -0.5f, 0.5f,  // bottom left
	   -0.25f,  0.5f, 0.5f   // top left 
	};
	unsigned int indices[12] = {  // note that we start from 0!
		0, 1, 3,  // first Triangle
		1, 2, 3,
		4, 5, 6,
		4, 6, 7
	};

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

