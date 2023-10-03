#ifndef __GRAPHIC_H__
#define __GRAPHIC_H__

#include"imgui/imgui.h"
#include"imgui/imgui_impl_glfw.h"
#include"imgui/imgui_impl_opengl3.h"

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<stb/stb_image.h>
#include<glm/glm.hpp>

#include "../engine/Model.h"

#include"Texture.h"
#include"Shader.h"
#include"VAO.h"
#include"VBO.h"
#include"EBO.h"
#include"Camera.h"
#include"Mesh.h"
#include"ParticuleMesh.h"

class Graphic
{
private:
	// Resolution 720p
	const unsigned int width = 1280;
	const unsigned int height = 720;

	Model* model;
	GLFWwindow* window;

	Mesh* floor;

	Shader shaderProgram;

	Camera camera;

	bool show_particule_window = false;
	float pos[3] = { 0.0f, 0.0f, 0.0f }, vel[3] = { 0.0f, 0.0f, 0.0f }, acc[3] = { 0.0f, 0.0f, 0.0f };
	double ttl = 60.0f;

public:
	Graphic(Model* model);
	
	GLFWwindow* getWindow();
	ImGuiIO& getIo();

	void process();

	~Graphic();
};

#endif