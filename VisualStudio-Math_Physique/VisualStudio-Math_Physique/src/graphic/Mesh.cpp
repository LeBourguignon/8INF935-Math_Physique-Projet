#include "Mesh.h"

Mesh::Mesh(std::vector <Vertex>& vertices, std::vector <GLuint>& indices)
	: vertices(vertices), indices(indices), vao(), vbo(vertices), ebo(indices)
{
	// Links VBO attributes such as coordinates and colors to VAO
	vao.LinkAttrib(vbo, 0, 3, GL_FLOAT, sizeof(Vertex), (void*)0);
	vao.LinkAttrib(vbo, 1, 3, GL_FLOAT, sizeof(Vertex), (void*)(3 * sizeof(float)));

	// Unbind all to prevent accidentally modifying them
	vao.Unbind();
	vbo.Unbind();
	ebo.Unbind();
}

Mesh::Mesh(std::vector<Vertex>* vertices, std::vector<GLuint>* indices)
	: Mesh(*vertices, *indices)
{
	delete vertices;
	delete indices;
}

void Mesh::Draw(Shader& shader, Camera& camera)
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
	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);

	// Unbind all to prevent accidentally modifying them
	vao.Unbind();
}

Mesh::~Mesh()
{
	vertices.~vector();
	indices.~vector();
	vao.Delete();
	vbo.Delete();
	ebo.Delete();
}
