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

	// Enables the Depth Buffer
	glEnable(GL_DEPTH_TEST);

	// Generates Shader object using shaders default.vert and default.frag
	shaderProgram = Shader("resources/default.vert", "resources/default.frag");

	// Tell OpenGL which Shader Program we want to use
	shaderProgram.Activate();

	// Floor
	// Vertices coordinates
	Vertex verticesFloor[] =
	{ //			COORDINATES					/				COLORS				//
		Vertex{glm::vec3(-10.0f, -5.0f,  10.0f),	glm::vec4(0.13f, 0.13f, 0.13f, 0.8f)},
		Vertex{glm::vec3(-10.0f, -5.0f, -10.0f),	glm::vec4(0.13f, 0.13f, 0.13f, 0.8f)},
		Vertex{glm::vec3(10.0f, -5.0f, -10.0f),		glm::vec4(0.13f, 0.13f, 0.13f, 0.8f)},
		Vertex{glm::vec3(10.0f, -5.0f,  10.0f),		glm::vec4(0.13f, 0.13f, 0.13f, 0.8f)}
	};

	// Indices for vertices order
	GLuint indicesFloor[] =
	{
		0, 1, 2,
		0, 2, 3
	};

	// Store mesh data in vectors for the mesh
	std::vector <Vertex> vertsFloor(verticesFloor, verticesFloor + sizeof(verticesFloor) / sizeof(Vertex));
	std::vector <GLuint> indFloor(indicesFloor, indicesFloor + sizeof(indicesFloor) / sizeof(GLuint));
	// Create floor mesh
	floor = new Mesh(vertsFloor, indFloor);

	// Maker
	// Vertices coordinates
	Vertex verticesMaker[] =
	{ //			COORDINATES					/				COLORS				//
		Vertex{glm::vec3(0.0f, 0.0f, 0.0f),			glm::vec4(1.0f, 1.0f, 1.0f, 1.0f)},
		Vertex{glm::vec3(1.0f, 0.0f, 0.0f),			glm::vec4(1.0f, 0.0f, 0.0f, 1.0f)},
		Vertex{glm::vec3(0.0f, 1.0f, 0.0f),			glm::vec4(0.0f, 1.0f, 0.0f, 1.0f)},
		Vertex{glm::vec3(0.0f, 0.0f, 1.0f),			glm::vec4(0.0f, 0.0f, 1.0f, 1.0f)}
	};

	// Indices for vertices order
	GLuint indicesMaker[] =
	{
		0, 1,
		0, 2,
		0, 3
	};

	// Store mesh data in vectors for the mesh
	std::vector <Vertex> vertsMaker(verticesMaker, verticesMaker + sizeof(verticesMaker) / sizeof(Vertex));
	std::vector <GLuint> indMaker(indicesMaker, indicesMaker + sizeof(indicesMaker) / sizeof(GLuint));
	// Create maker mesh
	maker = new LineMesh(vertsMaker, indMaker);
	
	// Gets ID of uniform called "scale"
	glUniform1f(glGetUniformLocation(shaderProgram.ID, "scale"), 0.5f);

	// Creates camera object
	camera = Camera(width, height, glm::vec3(0.0f, 0.0f, 10.0f));

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

void Graphic::updateInput(float deltaFrameTime)
{
	// Handles camera inputs
	camera.Inputs(window, deltaFrameTime);

	// Take care of all GLFW events
	glfwPollEvents();
}

void Graphic::updateWindow(float deltaFrameTime, float deltaUpdateTime)
{
	// Specify the color of the background
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	// Clean the back buffer and depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Updates and exports the camera matrix to the Vertex Shader
	camera.updateMatrix(45.0f, 0.1f, 100.0f);

	// Draws different meshes
	if (show_floor)	floor->Draw(shaderProgram, camera);
	if (show_maker)	maker->Draw(shaderProgram, camera);
	for (auto particule : model->getParticules())
	{
		SphereMesh particuleMesh(0.1f, Matrix34(particule->position, Quaternion()));
		particuleMesh.Draw(shaderProgram, camera);
		particuleMesh.~SphereMesh();
	}
	for (auto corpsRigide : model->getCorpsRigides())
	{
		CorpsRigideMesh corpsRigideMesh(*corpsRigide);
		corpsRigideMesh.Draw(shaderProgram, camera);
		corpsRigideMesh.~CorpsRigideMesh();
	}

	// Tell OpenGL a new frame is about to begin
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();

	// Main Window
	ImGui::Begin("Menu Principal");

	ImGui::Text("%.1f FPS", 1 / deltaFrameTime);
	ImGui::Text("%.1f UPS", 1 / deltaUpdateTime);

	ImGui::SeparatorText("Window");
	ImGui::Checkbox("Particule Window", &show_particule_window);
	ImGui::Checkbox("Demo Particule Window", &show_demo_particule_window);
	ImGui::Checkbox("Cuboide Window", &show_cuboide_window);
	ImGui::Checkbox("Demo Cuboide Window", &show_demo_cuboide_window);

	ImGui::SeparatorText("Mesh");
	ImGui::Checkbox("Maker", &show_maker);
	ImGui::Checkbox("Floor", &show_floor);

	ImGui::End();

	// Particule Window
	if (show_particule_window)
	{
		ImGui::Begin("Particule Window", &show_particule_window);

		ImGui::InputFloat3("Position", ppos);
		ImGui::InputFloat3("Velocite", pvel);
		ImGui::InputFloat3("Champ gravitationnel", pgra);
		ImGui::InputDouble("Masse (0 -> masse infinie)", &pmasse);

		ImGui::Spacing();

		if (ImGui::Button("Generation particule")) {
			model->ajouterParticule(new Particule(Vecteur3D(ppos[0], ppos[1], ppos[2]), Vecteur3D(pvel[0], pvel[1], pvel[2]), Vecteur3D(0.0f, 0.0f, 0.0f), pmasse), Vecteur3D(pgra[0], pgra[1], pgra[2]));
		}
		ImGui::SameLine();
		if (ImGui::Button("Nettoyage du model")) {
			model->reinitialisation();
		}

		ImGui::End();
	}

	// Demo Particule Window
	if (show_demo_particule_window)
	{
		ImGui::Begin("Demo Particule Window", &show_demo_particule_window);

		ImGui::SeparatorText("Demo 1");
		ImGui::Text("Deux particules avec deux gravites opposee\nsur le meme axe");
		if (ImGui::Button("Lancer demo 1"))
		{
			model->startDemoParticule1();
		}

		ImGui::SeparatorText("Demo 2");
		ImGui::Text("Deux particules avec gravite opposee (les\neloignant) reliees par un ressort\nde type bungee");
		if (ImGui::Button("Lancer demo 2"))
		{
			model->startDemoParticule2();
		}

		ImGui::SeparatorText("Demo 3");
		ImGui::Text("Deux particules de meme gravite reliees a\nl'axe y par des ressorts identiques\nla particule du haut est deux fois plus\nmassive que celle du bas");
		if (ImGui::Button("Lancer demo 3"))
		{
			model->startDemoParticule3();
		}

		ImGui::SeparatorText("Demo 4");
		ImGui::Text("Trois particules de meme masse (sans\ngravite). Celle de droite a une vitesse\ninitiale non nulle, celle du milieu est\nreliee aux autres par un cable");
		if (ImGui::Button("Lancer demo 4"))
		{
			model->startDemoParticule4();
		}

		ImGui::SeparatorText("Demo 5");
		ImGui::Text("Modelisation d'un pendule simple :\nparticule de masse finie soumise a la\ngravite et fixee a une particule de masse\ninfinie par une tige");
		if (ImGui::Button("Lancer demo 5"))
		{
			model->startDemoParticule5();
		}

		ImGui::SeparatorText("Demo 6");
		ImGui::Text("Une particule de masse infinie\net de vitesse non nulle reliee a deux\nautres particules de masse finie");
		if (ImGui::Button("Lancer demo 6"))
		{
			model->startDemoParticule6();
		}

		ImGui::SeparatorText("Demo 7");
		ImGui::Text("Deux particules au meme poids\nsoumis a la meme gravite mais celle du\ndessus a des frottements");
		if (ImGui::Button("Lancer demo 7"))
		{
			model->startDemoParticule7();
		}

		ImGui::SeparatorText("Demo 8");
		ImGui::Text("Trois particules qui tombe dans un\nliquide lui permettant de flotter\navec des frottements");
		if (ImGui::Button("Lancer demo 8"))
		{
			model->startDemoParticule8();
		}

		ImGui::End();
	}

	// Cuboide Window
	if (show_cuboide_window)
	{
		ImGui::Begin("Cuboide Window", &show_cuboide_window);

		ImGui::InputFloat3("Position", cpos);
		ImGui::InputFloat4("Orientation", cori);
		ImGui::InputFloat3("Velocite", cvel);
		ImGui::InputFloat3("Rotation", crot);
		ImGui::InputFloat3("Champ gravitationnel", cgra);
		ImGui::InputDouble("Masse (0 -> masse infinie)", &cmasse);
		ImGui::InputFloat3("Taille", ctaille);

		ImGui::Spacing();

		if (ImGui::Button("Generation particule")) {
			model->ajouterCuboide(new Cuboide(Vecteur3D(ctaille[0], ctaille[1], ctaille[2]), cmasse, Vecteur3D(cpos[0], cpos[1], cpos[2]), Quaternion(cori[0], cori[1], cori[2], cori[3]), Vecteur3D(cvel[0], cvel[1], cvel[2]), Vecteur3D(crot[0], crot[1], crot[2])), Vecteur3D(cgra[0], cgra[1], cgra[2]));
		}
		ImGui::SameLine();
		if (ImGui::Button("Nettoyage du model")) {
			model->reinitialisation();
		}

		ImGui::End();
	}

	// Demo Particule Window
	if (show_demo_cuboide_window)
	{
		ImGui::Begin("Demo Cuboide Window", &show_demo_cuboide_window);

		ImGui::SeparatorText("Demo 1");
		ImGui::Text("Amas de Cuboides relies par des ressorts");
		if (ImGui::Button("Lancer demo 1"))
		{
			model->startDemoCuboide1();
		}

		//ImGui::SeparatorText("Demo 2");
		//ImGui::Text("Marteau");
		//if (ImGui::Button("Lancer demo 2"))
		//{
		//	model->startDemoCuboide2();
		//}

		ImGui::End();
	}

	// Renders the ImGUI elements
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

	// Swap the back buffer with the front buffer
	glfwSwapBuffers(window);
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

