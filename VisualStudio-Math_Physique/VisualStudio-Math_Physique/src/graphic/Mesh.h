#ifndef MESH_CLASS_H
#define MESH_CLASS_H

#include<string>

#include"VAO.h"
#include"EBO.h"
#include"Camera.h"
#include"Texture.h"
#include "Shader.h"

class Mesh
{
private:
	std::vector <Vertex> vertices;
	std::vector <GLuint> indices;
	VAO vao;
	VBO vbo;
	EBO ebo;

public:
	// Initializes the mesh
	Mesh(std::vector <Vertex>& vertices, std::vector <GLuint>& indices);
	Mesh(std::vector <Vertex>* vertices, std::vector <GLuint>* indices);

	// Draws the mesh
	void Draw(Shader& shader, Camera& camera);

	~Mesh();
};
#endif