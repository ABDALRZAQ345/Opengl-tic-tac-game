#pragma once
#include <gl/glut.h>
#include <GL/glut.h>
class Texture
{
public:
	GLuint textureID;
	void loadTexture(const char* filename);

	void Use();
};
