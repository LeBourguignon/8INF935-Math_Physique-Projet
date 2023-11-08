#ifndef __CUBOIDE_MESH_H__
#define __CUBOIDE_MESH_H__

#include "Mesh.h"
#include "../engine/corps-rigide/forme/Cuboide.h"

class CuboideMesh : public Mesh
{
private:
	Cuboide cuboide;

	std::vector<Vertex>* getVertices(const Cuboide& cuboide);
	std::vector<GLuint>* getIndices();

public:
	CuboideMesh(const Cuboide& cuboide);

	void Draw(Shader& shader, Camera& camera);
};

#endif