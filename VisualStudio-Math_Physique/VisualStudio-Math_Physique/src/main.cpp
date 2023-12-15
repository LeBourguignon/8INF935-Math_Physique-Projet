#include "engine/Model.h"
#include "graphic/Graphic.h"

// Timing
float lastUpdate = 0.0f;
float lastFrame = 0.0f;

const float frameDelay = 0.005f; // Correspond à 200 FPS

//int main()
//{
//	// Initialisation du model physique
//	Model* model = new Model();
//	// Initialisation du moteur graphique
//	Graphic graphic = Graphic(model);
//
//	// Main loop
//	while (!glfwWindowShouldClose(graphic.getWindow())) {
//
//		// per-frame time logic
//		float currentTime = static_cast<float>(glfwGetTime());
//		float deltaUpdateTime = currentTime - lastUpdate;
//		float deltaFrameTime = currentTime - lastFrame;
//		
//		// Actualisation des entrées
//		graphic.updateInput(deltaUpdateTime);
//		// Actualisation logique
//		model->actualiser(deltaUpdateTime);
//
//		lastUpdate = currentTime;
//
//		if (deltaFrameTime >= frameDelay) {
//			// Actualisation de la fenètre
//			graphic.updateWindow(deltaFrameTime, deltaUpdateTime);
//
//			lastFrame = currentTime;
//		}
//	}
//
//	// Desctruction du moteur graphique
//	graphic.~Graphic();
//	// Desctruction du model physique
//	model->~Model();
//
//	exit(0);
//}

#include "engine/corps-rigide/contact/GenerateurContactCorpsRigide.h"

int main()
{
	
}