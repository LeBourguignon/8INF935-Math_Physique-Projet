#include "ParticuleMesh.h"

std::vector<Vertex>* getVertices(float x, float y, float z)
{
	Vertex vertices[] =
	{//						COORDINATES						  /			COLORS				//
		Vertex{glm::vec3(-0.1f + x, -0.1f + y,	0.1f + z),	glm::vec3(0.0f, 0.0f, 1.0f)},
		Vertex{glm::vec3(-0.1f + x, -0.1f + y,	-0.1f + z),	glm::vec3(0.0f, 0.0f, 0.0f)},
		Vertex{glm::vec3(0.1f + x,	-0.1f + y,	-0.1f + z),	glm::vec3(1.0f, 0.0f, 0.0f)},
		Vertex{glm::vec3(0.1f + x,	-0.1f + y,	0.1f + z),	glm::vec3(1.0f, 0.0f, 1.0f)},
		Vertex{glm::vec3(-0.1f + x, 0.1f + y,	0.1f + z),	glm::vec3(0.0f, 1.0f, 1.0f)},
		Vertex{glm::vec3(-0.1f + x, 0.1f + y,	-0.1f + z),	glm::vec3(0.0f, 1.0f, 0.0f)},
		Vertex{glm::vec3(0.1f + x,  0.1f + y,	-0.1f + z),	glm::vec3(1.0f, 1.0f, 0.0f)},
		Vertex{glm::vec3(0.1f + x,  0.1f + y,	0.1f + z),	glm::vec3(1.0f, 1.0f, 1.0f)}
	};
	std::vector <Vertex>* verts = new std::vector <Vertex>(vertices, vertices + sizeof(vertices) / sizeof(Vertex));
	return verts;
}

std::vector<GLuint>* getIndices()
{
	GLuint indices[] =
	{
		0, 1, 2,
		0, 2, 3,
		0, 4, 7,
		0, 7, 3,
		3, 7, 6,
		3, 6, 2,
		2, 6, 5,
		2, 5, 1,
		1, 5, 4,
		1, 4, 0,
		4, 5, 6,
		4, 6, 7
	};
	std::vector <GLuint>* ind = new std::vector <GLuint>(indices, indices + sizeof(indices) / sizeof(GLuint));
	return ind;
}

ParticuleMesh::ParticuleMesh(float x, float y, float z)
	: Mesh(getVertices(x, y, z), getIndices())
{
}