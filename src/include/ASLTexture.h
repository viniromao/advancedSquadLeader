#pragma once

#include <GL/glew.h>


class ASLTexture
{
public:
	ASLTexture();
	ASLTexture(char* fileLoc);

	void LoadTexture();
	void UseTexture();
	void ClearTexture();

	~ASLTexture();

private:
	GLuint textureID;
	int width, height, bitDepth;

	char* fileLocation;
};

