#ifndef __SPHERE_MESH_H__
#define __SPHERE_MESH_H__

#include "Mesh.h"

#include "../engine/Matrix34.h"

class SphereMesh : public Mesh
{
private:
	Matrix34 transformMatrix;

	std::vector<Vertex>* getVertices(double radius, double density);
	std::vector<GLuint>* getIndices(double density);

public:
	SphereMesh(double radius, Matrix34 transformMatrix = Matrix34(), double density = 10);
	void Draw(Shader& shader, Camera& camera);
};

#endif