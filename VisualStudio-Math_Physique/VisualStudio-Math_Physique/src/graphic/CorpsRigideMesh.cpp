#include "CorpsRigideMesh.h"

std::vector<Vertex>* CorpsRigideMesh::getVertices(const CorpsRigide& corpsRigide)
{
	std::vector<Vertex>* vertex = new std::vector<Vertex>();

	for (auto& vertice : corpsRigide.forme.vertices)
	{
		vertex->push_back(Vertex{ glm::vec3(vertice.x,vertice.y, vertice.z), glm::vec4(1.0 / (1.0 + std::exp(-vertice.x)), 1.0 / (1.0 + std::exp(-vertice.y)), 1.0 / (1.0 + std::exp(-vertice.z)), 1.0f) });
	}

	return vertex;
}

std::vector<GLuint>* CorpsRigideMesh::getIndices(const CorpsRigide& corpsRigide)
{
	std::vector<GLuint>* index = new std::vector<GLuint>();

	for (auto& indice : corpsRigide.forme.indices) {
		for (auto& i : indice)
		{
			index->push_back(i);
		}
	}

	return index;
}

CorpsRigideMesh::CorpsRigideMesh(const CorpsRigide& corpsRigide)
	: Mesh(getVertices(corpsRigide), getIndices(corpsRigide)), corpsRigide(corpsRigide)
{
}

void CorpsRigideMesh::Draw(Shader& shader, Camera& camera)
{
	// Bind shader to be able to access uniforms
	shader.Activate();
	vao.Bind();

	// Take care of the camera Matrix
	glUniform3f(glGetUniformLocation(shader.ID, "camPos"), camera.Position.x, camera.Position.y, camera.Position.z);
	camera.Matrix(shader, "camMatrix");

	// Transfer the transformation matrix to the shader
	glUniformMatrix4fv(glGetUniformLocation(shader.ID, "transformMatrix"), 1, GL_FALSE, glm::value_ptr(corpsRigide.transformMatrix.toGlmMat4()));

	// Draw the actual mesh
	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);

	// Unbind all to prevent accidentally modifying them
	vao.Unbind();
}
