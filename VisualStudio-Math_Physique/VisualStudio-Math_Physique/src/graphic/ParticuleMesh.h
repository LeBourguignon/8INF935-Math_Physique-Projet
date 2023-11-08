#ifndef __PARTICULE_MESH_H__
#define __PARTICULE_MESH_H__

#include "Mesh.h"

class ParticuleMesh : public Mesh
{
private:
	std::vector<Vertex>* getVertices(float x, float y, float z);
	std::vector<GLuint>* getIndices();

public:
	
	ParticuleMesh(float x, float y, float z);
};

#endif