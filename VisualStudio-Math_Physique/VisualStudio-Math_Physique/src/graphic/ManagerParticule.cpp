#include "ManagerParticule.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"

ManagerParticule::ManagerParticule()
{

}

void ManagerParticule::add(Particule particule, double ttl)
{
	particules.push_back(particule);
	ttls.push_back(ttl);
}

void ManagerParticule::draw(double deltaTime)
{
	for (int i = particules.size() - 1; i >= 0; i--)
	{
		ttls[i] -= deltaTime;
		if (ttls[i] < 0.0f)
		{
			ttls.erase(ttls.begin() + i);
			particules.erase(particules.begin() + i);
		}
		else
		{
			particules[i].integration(deltaTime);

			// Vertices coordinates
			GLfloat vertices[] =
			{	//								COORDINATES															/      COLORS       //
				0.5f + particules[i].position.x, -0.5f + particules[i].position.y, 0.0f + particules[i].position.z,		0.0f, 1.0f, 1.0f,
				-0.5f + particules[i].position.x, -0.5f + particules[i].position.y, 0.5f + particules[i].position.z,	1.0f, 0.0f, 1.0f,
				-0.5f + particules[i].position.x, -0.5f + particules[i].position.y, -0.5f + particules[i].position.z,	1.0f, 1.0f, 0.0f,
				0.0f + particules[i].position.x, 0.5f + particules[i].position.y, 0.0f + particules[i].position.z,		1.0f, 1.0f, 1.0f,
			};

			// Indices for vertices order
			GLuint indices[] =
			{
				0, 1, 2,
				0, 1, 3,
				1, 2, 3,
				0, 2, 3
			};

			// Generates Vertex Array Object and binds it
			VAO VAO2;
			VAO2.Bind();

			// Generates Vertex Buffer Object and links it to vertices
			VBO VBO2(vertices, sizeof(vertices));
			// Generates Element Buffer Object and links it to indices
			EBO EBO2(indices, sizeof(indices));

			// Links VBO attributes such as coordinates and colors to VAO
			VAO2.LinkAttrib(VBO2, 0, 3, GL_FLOAT, 6 * sizeof(float), (void*)0);
			VAO2.LinkAttrib(VBO2, 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float)));

			// Draw primitives, number of indices, datatype of indices, index of indices
			glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(int), GL_UNSIGNED_INT, 0);
			
			// Unbind all to prevent accidentally modifying them
			VAO2.Unbind();
			VBO2.Unbind();
			EBO2.Unbind();

			// Delete all the objects we've created
			VAO2.Delete();
			VBO2.Delete();
			EBO2.Delete();
		}
	}
}