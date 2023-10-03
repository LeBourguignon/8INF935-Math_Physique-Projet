#include "engine/Model.h"
#include "graphic/Graphic.h"

void main()
{
	Model* model = new Model();
	Graphic graphic = Graphic(model);

	while (!glfwWindowShouldClose(graphic.getWindow())) {
		model->actualiser(graphic.getIo().DeltaTime);
		graphic.process();
	}

	graphic.~Graphic();
	model->~Model();

	exit(0);
}