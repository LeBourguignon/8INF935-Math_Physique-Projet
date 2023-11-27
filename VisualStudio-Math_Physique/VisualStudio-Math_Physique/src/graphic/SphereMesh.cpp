#include "SphereMesh.h"

std::vector<Vertex>* SphereMesh::getVertices(double radius, double density)
{
    std::vector<Vertex>* vertices = new std::vector<Vertex>();

    for (int i = 0; i <= density; ++i) {
        float phi = glm::pi<float>() * static_cast<float>(i) / density;
        float cosPhi = std::cos(phi);
        float sinPhi = std::sin(phi);

        for (int j = 0; j <= density; ++j) {
            float theta = 2 * glm::pi<float>() * static_cast<float>(j) / density;
            float cosTheta = std::cos(theta);
            float sinTheta = std::sin(theta);

            Vertex vertex;
            vertex.position.x = radius * sinPhi * cosTheta;
            vertex.position.y = radius * cosPhi;
            vertex.position.z = radius * sinPhi * sinTheta;
            vertex.color = glm::vec4(std::abs(cosPhi), std::abs(cosTheta), sinPhi * sinTheta, 1.0f); // Change the color as needed
            vertices->push_back(vertex);
        }
    }

    return vertices;
}

std::vector<GLuint>* SphereMesh::getIndices(double density)
{
    std::vector<GLuint>* indices = new std::vector<GLuint>();

    for (int i = 0; i < density; ++i) {
        for (int j = 0; j < density; ++j) {
            int first = (i * (density + 1)) + j;
            int second = first + density + 1;

            indices->push_back(first);
            indices->push_back(second);
            indices->push_back(first + 1);

            indices->push_back(second);
            indices->push_back(second + 1);
            indices->push_back(first + 1);
        }
    }

    return indices;
}

SphereMesh::SphereMesh(double radius, Matrix34 transformMatrix, double density)
    : Mesh(getVertices(radius, density), getIndices(density)), transformMatrix(transformMatrix)
{
}

void SphereMesh::Draw(Shader& shader, Camera& camera)
{
    // Bind shader to be able to access uniforms
    shader.Activate();
    vao.Bind();

    // Take care of the camera Matrix
    glUniform3f(glGetUniformLocation(shader.ID, "camPos"), camera.Position.x, camera.Position.y, camera.Position.z);
    camera.Matrix(shader, "camMatrix");

    // Transfer the transformation matrix to the shader
    glUniformMatrix4fv(glGetUniformLocation(shader.ID, "transformMatrix"), 1, GL_FALSE, glm::value_ptr(transformMatrix.toGlmMat4()));

    // Draw the actual mesh
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);

    // Unbind all to prevent accidentally modifying them
    vao.Unbind();
}
