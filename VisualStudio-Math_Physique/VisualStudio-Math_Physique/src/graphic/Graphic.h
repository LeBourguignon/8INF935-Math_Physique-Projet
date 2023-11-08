#ifndef __GRAPHIC_H__
#define __GRAPHIC_H__

#include"imgui/imgui.h"
#include"imgui/imgui_impl_glfw.h"
#include"imgui/imgui_impl_opengl3.h"

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<stb/stb_image.h>
#include<glm/glm.hpp>

#include"../engine/Model.h"

#include"Texture.h"
#include"Shader.h"
#include"VAO.h"
#include"VBO.h"
#include"EBO.h"
#include"Camera.h"
#include"Mesh.h"
#include"LineMesh.h"
#include"ParticuleMesh.h"
#include"CuboideMesh.h"

class Graphic
{
private:
	// Resolution 720p
	const unsigned int width = 1280;
	const unsigned int height = 720;

	Model* model;
	GLFWwindow* window;

	Shader shaderProgram;

	Mesh* floor;
	LineMesh* maker;

	Camera camera;

	bool show_particule_window = false, show_demo_window = false, show_cuboide_window = false;

	float ppos[3] = { 0.0f, 0.0f, 0.0f }, pvel[3] = { 0.0f, 0.0f, 0.0f }, pgra[3] = { 0.0f, 0.0f, 0.0f };
	double pmasse = 10.0f;

	float cpos[3] = { 0.0f, 0.0f, 0.0f }, cvel[3] = { 0.0f, 0.0f, 0.0f }, cori[4] = { 1.0f, 0.0f, 0.0f, 0.0f }, crot[3] = { 0.0f, 0.0f, 0.0f }, ctaille[3] = { 0.2f, 0.2f, 0.2f };
	double cmasse = 10.0f;

public:
	// Initilisation du moteur graphique
	Graphic(Model* model);

	// Getters
	GLFWwindow* getWindow();
	ImGuiIO& getIo();

	void updateInput(float deltaFrameTime);
	void updateWindow(float deltaFrameTime, float deltaUpdateTime);

	// Desctruction du moteur graphique
	~Graphic();
};

#endif