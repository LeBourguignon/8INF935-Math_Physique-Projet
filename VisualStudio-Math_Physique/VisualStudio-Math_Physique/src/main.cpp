#include "engine/Model.h"
#include "graphic/Graphic.h"

void main()
{
	// Initialisation du model physique
	Model* model = new Model();
	// Initialisation du moteur graphique
	Graphic graphic = Graphic(model);

	// Main loop
	while (!glfwWindowShouldClose(graphic.getWindow())) {
		// Actualisation logique
		model->actualiser(graphic.getIo().DeltaTime);
		// Calcule et affichage de la fenêtre
		graphic.process();
	}

	// Desctruction du moteur graphique
	graphic.~Graphic();
	// Desctruction du model physique
	model->~Model();

	exit(0);
}