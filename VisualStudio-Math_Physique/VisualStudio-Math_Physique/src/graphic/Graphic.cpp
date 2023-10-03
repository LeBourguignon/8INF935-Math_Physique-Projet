#include "Graphic.h"

Graphic::Graphic(Model* model)
	: model(model), shaderProgram(), camera()
{
	// Initialize GLFW
	glfwInit();

	// Tell GLFW what version of OpenGL we are using 
	// In this case we are using OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Tell GLFW we are using the CORE profile
	// So that means we only have the modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create a GLFWwindow object of 720p, naming it "8INF935-Math_Physique-Projet"
	window = glfwCreateWindow(width, height, "8INF935-Math_Physique-Projet", NULL, NULL);
	// Error check if the window fails to create
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		exit(-1);
	}
	// Introduce the window into the current context
	glfwMakeContextCurrent(window);

	//Load GLAD so it configures OpenGL
	gladLoadGL();
	// Specify the viewport of OpenGL in the Window
	// In this case the viewport goes from x = 0, y = 0, to x = 1280, y = 720
	glViewport(0, 0, width, height);

	// Floor
	// Vertices coordinates
	Vertex vertices[] =
	{ //			COORDINATES					/				COLORS				//
		Vertex{glm::vec3(-10.0f, -1.0f,  10.0f),	glm::vec3(0.13f, 0.13f, 0.13f)},
		Vertex{glm::vec3(-10.0f, -1.0f, -10.0f),	glm::vec3(0.13f, 0.13f, 0.13f)},
		Vertex{glm::vec3(10.0f, -1.0f, -10.0f),		glm::vec3(0.13f, 0.13f, 0.13f)},
		Vertex{glm::vec3(10.0f, -1.0f,  10.0f),		glm::vec3(0.13f, 0.13f, 0.13f)}
	};

	// Indices for vertices order
	GLuint indices[] =
	{
		0, 1, 2,
		0, 2, 3
	};

	// Generates Shader object using shaders default.vert and default.frag
	shaderProgram = Shader("resources/default.vert", "resources/default.frag");
	// Store mesh data in vectors for the mesh
	std::vector <Vertex> verts(vertices, vertices + sizeof(vertices) / sizeof(Vertex));
	std::vector <GLuint> ind(indices, indices + sizeof(indices) / sizeof(GLuint));
	// Create floor mesh
	floor = new Mesh(verts, ind);

	// Tell OpenGL which Shader Program we want to use
	shaderProgram.Activate();
	// Gets ID of uniform called "scale"
	glUniform1f(glGetUniformLocation(shaderProgram.ID, "scale"), 0.5f);

	// Enables the Depth Buffer
	glEnable(GL_DEPTH_TEST);

	// Creates camera object
	camera = Camera(width, height, glm::vec3(0.0f, 0.0f, 2.0f));

	// Initialize ImGUI
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGui::StyleColorsDark();
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 330");
}

GLFWwindow* Graphic::getWindow()
{
	return window;
}

ImGuiIO& Graphic::getIo()
{
	ImGuiIO& io = ImGui::GetIO();
	(void)io;
	return io;
}

void Graphic::process()
{
	// Specify the color of the background
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	// Clean the back buffer and depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Handles camera inputs
	camera.Inputs(window, getIo().DeltaTime);
	// Updates and exports the camera matrix to the Vertex Shader
	camera.updateMatrix(45.0f, 0.1f, 100.0f);

	// Draws different meshes
	floor->Draw(shaderProgram, camera);
	for(Particule* particule : model->getParticules())
	{
		ParticuleMesh particuleMesh(particule->position.x, particule->position.y, particule->position.z);
		particuleMesh.Draw(shaderProgram, camera);
		particuleMesh.~ParticuleMesh();
	}

	// Tell OpenGL a new frame is about to begin
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();

	// Main Window
	ImGui::Begin("Menu Principal");
	ImGui::Text("%.1f FPS", getIo().Framerate);
	ImGui::Checkbox("Particule Window", &show_particule_window);
	ImGui::End();

	// Particule Window
	if (show_particule_window)
	{
		ImGui::Begin("Particule Window", &show_particule_window);

		ImGui::InputFloat3("Position", pos);
		ImGui::InputFloat3("Velocite", vel);
		ImGui::InputFloat3("Acceleration", acc);
		ImGui::InputDouble("Temps de vie (en seconde)", &ttl);

		if (ImGui::Button("Generation particule")) {
			model->addParticule(new Particule(Vecteur3D(pos[0], pos[1], pos[2]), Vecteur3D(vel[0], vel[1], vel[2]), Vecteur3D(acc[0], acc[1], acc[2])), ttl);
		}

		ImGui::End();
	}

	// Renders the ImGUI elements
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

	// Swap the back buffer with the front buffer
	glfwSwapBuffers(window);
	// Take care of all GLFW events
	glfwPollEvents();
}

Graphic::~Graphic()
{
	// Deletes all ImGUI instances
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	// Delete all the objects we've created
	shaderProgram.Delete();

	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
}
