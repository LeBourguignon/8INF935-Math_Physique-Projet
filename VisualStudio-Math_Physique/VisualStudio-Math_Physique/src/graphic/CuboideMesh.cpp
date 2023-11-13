#include "CuboideMesh.h"

std::vector<Vertex>* CuboideMesh::getVertices(const Cuboide& cuboide)
{
	double dx = cuboide.dimension.x / 2;
	double dy = cuboide.dimension.y / 2;
	double dz = cuboide.dimension.z / 2;

	Vertex vertices[] =
	{//			COORDINATES			  /				COLORS RGBA				//
		Vertex{glm::vec3(-dx,-dy, dz),	glm::vec4(0.0f, 0.0f, 1.0f, 1.0f)},
		Vertex{glm::vec3(-dx,-dy,-dz),	glm::vec4(0.0f, 0.0f, 0.0f, 1.0f)},
		Vertex{glm::vec3( dx,-dy,-dz),	glm::vec4(1.0f, 0.0f, 0.0f, 1.0f)},
		Vertex{glm::vec3( dx,-dy, dz),	glm::vec4(1.0f, 0.0f, 1.0f, 1.0f)},
		Vertex{glm::vec3(-dx, dy, dz),	glm::vec4(0.0f, 1.0f, 1.0f, 1.0f)},
		Vertex{glm::vec3(-dx, dy,-dz),	glm::vec4(0.0f, 1.0f, 0.0f, 1.0f)},
		Vertex{glm::vec3( dx, dy,-dz),	glm::vec4(1.0f, 1.0f, 0.0f, 1.0f)},
		Vertex{glm::vec3( dx, dy, dz),	glm::vec4(1.0f, 1.0f, 1.0f, 1.0f)}
	};
	std::vector <Vertex>* verts = new std::vector <Vertex>(vertices, vertices + sizeof(vertices) / sizeof(Vertex));
	return verts;
}

std::vector<GLuint>* CuboideMesh::getIndices()
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

CuboideMesh::CuboideMesh(const Cuboide& cuboide)
	: Mesh(getVertices(cuboide), getIndices()), cuboide(cuboide)
{
}

void CuboideMesh::Draw(Shader& shader, Camera& camera)
{
	// Bind shader to be able to access uniforms
	shader.Activate();
	vao.Bind();

	// Take care of the camera Matrix
	glUniform3f(glGetUniformLocation(shader.ID, "camPos"), camera.Position.x, camera.Position.y, camera.Position.z);
	camera.Matrix(shader, "camMatrix");

	// Transfer the transformation matrix to the shader
	glUniformMatrix4fv(glGetUniformLocation(shader.ID, "transformMatrix"), 1, GL_FALSE, glm::value_ptr(cuboide.transformMatrix.toGlmMat4()));

	// Draw the actual mesh
	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);

	// Unbind all to prevent accidentally modifying them
	vao.Unbind();
}