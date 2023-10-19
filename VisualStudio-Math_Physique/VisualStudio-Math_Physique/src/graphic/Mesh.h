#ifndef __MESH_H__
#define __MESH_H__

#include<string>

#include"VAO.h"
#include"EBO.h"
#include"Camera.h"
#include"Texture.h"
#include "Shader.h"

class Mesh
{
protected:
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
	virtual void Draw(Shader& shader, Camera& camera);

	~Mesh();
};
#endif