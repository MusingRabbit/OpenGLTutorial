#pragma once
#include <fstream>
#include <iostream>
#include <GL/glew.h>
#include <string>

class Camera;
class Transform;

class Shader
{
public:
	Shader(const std::string& shaderPath);
	void Bind();
	void Update(const Transform& transform, const Camera& camera);
	virtual ~Shader();

protected:
private:
	enum
	{
		TRANSFORM_U,
		NUM_UNIFORMS
	};
	
	static const unsigned int NUM_SHADERS = 2;
	static std::string LoadShader(const std::string& shaderPath);
	static void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
	GLuint CreateShader(const std::string& text, GLenum shaderType);

	Shader(const Shader& rhs) {}
	void operator=(const Shader& rhs) {}

	GLuint m_program;
	GLuint m_shader[NUM_SHADERS];
	GLuint m_uniforms[NUM_UNIFORMS];
};

