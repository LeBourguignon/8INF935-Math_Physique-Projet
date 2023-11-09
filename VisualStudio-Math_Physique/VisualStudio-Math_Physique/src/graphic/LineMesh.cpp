#include "LineMesh.h"

LineMesh::LineMesh(std::vector<Vertex>& vertices, std::vector<GLuint>& indices)
	: Mesh(vertices, indices)
{
}

LineMesh::LineMesh(std::vector<Vertex>* vertices, std::vector<GLuint>* indices)
	: Mesh(vertices, indices)
{
}

void LineMesh::Draw(Shader& shader, Camera& camera)
{
	// Bind shader to be able to access uniforms
	shader.Activate();
	vao.Bind();

	// Take care of the camera Matrix
	glUniform3f(glGetUniformLocation(shader.ID, "camPos"), camera.Position.x, camera.Position.y, camera.Position.z);
	camera.Matrix(shader, "camMatrix");

	// Transfer the transformation matrix to the shader
	glUniformMatrix4fv(glGetUniformLocation(shader.ID, "transformMatrix"), 1, GL_FALSE, glm::value_ptr(glm::mat4(1.0f)));

	// Draw the actual mesh
	glDrawElements(GL_LINES, indices.size(), GL_UNSIGNED_INT, 0);

	// Unbind all to prevent accidentally modifying them
	vao.Unbind();
}
