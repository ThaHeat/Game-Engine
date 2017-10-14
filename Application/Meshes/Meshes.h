#pragma once

#include <iostream>
#include <GL\glew.h>

class Meshes
{
	public:
		Meshes();
		~Meshes();

		void initMesh();
		void drawMesh();

	private:

		void createMesh();

		GLuint _VBO, _VAO;
};
