#ifndef __LINE_MESH_H__
#define __LINE_MESH_H__

#include "Mesh.h"

class LineMesh : public Mesh
{
public:
	// Initializes the mesh
	LineMesh(std::vector <Vertex>& vertices, std::vector <GLuint>& indices);
	LineMesh(std::vector <Vertex>* vertices, std::vector <GLuint>* indices);

	// Draws the mesh
	virtual void Draw(Shader& shader, Camera& camera);
};

#endif