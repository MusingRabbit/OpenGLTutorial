#pragma once

#include <glm/glm.hpp>
#include <GL/glew.h>
#include <string>
#include "ObjLoader.h"


class Vertex
{
public:
	Vertex(const glm::vec3& pos, const glm::vec2& txrCoord, const glm::vec3& normal = glm::vec3())
	{
		this->pos = pos;
		this->txrCoord = txrCoord;
		this->normal = normal;
	}

	glm::vec3 GetPos()
	{
		return pos;
	}

	glm::vec2 GetTxrCoord()
	{
		return txrCoord;
	}

	glm::vec3 GetNormal()
	{
		return normal;
	}

protected:
private:
	glm::vec3 pos;
	glm::vec2 txrCoord;
	glm::vec3 normal;
};

class Mesh
{
public:
	Mesh(Vertex* vertices, unsigned int numVertices, unsigned int* indices, unsigned int numIndices);
	Mesh(const std::string& fileName);
	
	void Draw();
	
	virtual ~Mesh();
protected:
private:
	Mesh(const Mesh& rhs);
	void operator = (const Mesh& rhs);

	void InitMesh(const IndexedModel& model);
	
	enum
	{
		POSITION_VB,
		TXRCOORD_VB,
		NORMAL_VB,
		INDEX_VB,
		NUM_BUFFERS
	};
	
	GLuint m_vertexArrayObject;
	GLuint m_vertexArrayBuffers[NUM_BUFFERS];
	unsigned int m_drawCount;
};

