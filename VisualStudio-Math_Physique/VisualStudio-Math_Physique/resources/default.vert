#version 330 core

// Positions
layout (location = 0) in vec3 aPos;
// Colors
layout (location = 1) in vec4 aColor;

// Outputs the color for the Fragment Shader
out vec4 color;

// Imports the camera matrix from the main function
uniform mat4 camMatrix;
// Imports the transformation matrix from the main function
uniform mat4 transformMatrix;


void main()
{
	// Apply matrix transformation
	vec4 modelSpacePosition = transformMatrix * vec4(aPos, 1.0);

	// Apply matrix camera
	gl_Position = camMatrix * vec4(aPos, 1.0);

	// Assigns the colors from the Vertex Data to "color"
	color = aColor;
}