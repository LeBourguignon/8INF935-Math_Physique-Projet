#ifndef __CORPS_RIGIDE_MESH_H__
#define __CORPS_RIGIDE_MESH_H__

#include "Mesh.h"
#include "../engine/corps-rigide/CorpsRigide.h"

class CorpsRigideMesh : public Mesh
{
private:
	CorpsRigide corpsRigide;

	std::vector<Vertex>* getVertices(const CorpsRigide& corpsRigide);
	std::vector<GLuint>* getIndices(const CorpsRigide& corpsRigide);

public:
	CorpsRigideMesh(const CorpsRigide& corpsRigide);

	void Draw(Shader& shader, Camera& camera);
};

#endif