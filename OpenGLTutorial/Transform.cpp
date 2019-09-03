#include "Transform.h"

Transform::Transform()
{
	m_pos = glm::vec3();
	m_rot = glm::vec3();
	m_scale = glm::vec3(1, 1, 1);
}

Transform::Transform(const glm::vec3& pos = glm::vec3(), const glm::vec3& rot = glm::vec3(), const glm::vec3& scale = glm::vec3(1.0, 1.0, 1.0)) :
	m_pos(pos),
	m_rot(rot),
	m_scale(scale)
{
}

Transform::~Transform()
{
}

glm::vec3& Transform::GetPos() { return m_pos; }
glm::vec3& Transform::GetRot() { return m_rot; }
glm::vec3& Transform::GetScale() { return m_scale; }

void Transform::SetPos(const glm::vec3& pos) { m_pos = pos; }
void Transform::SetRot(const glm::vec3& rot) { m_rot = rot; }
void Transform::SetScale(const glm::vec3& scale) { m_scale = scale; }

glm::mat4 Transform::GetModel() const
{
	glm::mat4 mtxPos = glm::translate(m_pos);
	glm::mat4 mtxRotX = glm::rotate(m_rot.x, glm::vec3(1, 0, 0));
	glm::mat4 mtxRotY = glm::rotate(m_rot.y, glm::vec3(0, 1, 0));
	glm::mat4 mtxRotZ = glm::rotate(m_rot.z, glm::vec3(0, 0, 1));
	glm::mat4 mtxScale = glm::scale(m_scale);

	//Order matters when multiplying matrices.
	glm::mat4 mtxRot = mtxRotZ * mtxRotY * mtxRotX;

	return mtxPos * mtxRot * mtxScale;
}