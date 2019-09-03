#pragma once

#include <string>
#include <GL/glew.h>

class Texture
{
public:
	Texture(const std::string& fileName);

	void Bind(unsigned int unit);
	
	virtual ~Texture();
protected:
private:
	Texture(const Texture& rhs);
	Texture operator=(const Texture& rhs);

	GLuint m_texture;
};

