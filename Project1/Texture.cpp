#include<Gl/glut.h>
#include <cmath> 
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <deque>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cassert>
#include <iterator>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <cctype>
#include <list>
#include <tuple>
#include <random>
#include <array>
#include <unordered_map>
#include <unordered_set>
#include <chrono>
#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_STATIC
#include<stb_image.h>
#include "Texture.h"
void Texture::Use()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureID);
}
void Texture::loadTexture(const char* filename) {

	stbi_set_flip_vertically_on_load(true);
	int width, height, channels;


	unsigned char* image = stbi_load(filename, &width, &height, &channels, 0);

	if (image) {
		std::cout << "Image loaded successfully: " << width << "x" << height << ", Channels: " << channels << std::endl;


		glGenTextures(1, &textureID);
		glBindTexture(GL_TEXTURE_2D, textureID);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0,
			channels == 4 ? GL_RGBA : GL_RGB,
			GL_UNSIGNED_BYTE, image);

		stbi_image_free(image);
	}
	else {
		std::cout << "Failed to load texture" << std::endl;
	}
}
