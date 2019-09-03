#pragma once
#include "glm/glm.hpp"
#include "glm/gtx/transform.hpp"

class Transform
{
public:
	Transform();
	Transform(const glm::vec3& pos, const glm::vec3& rot, const glm::vec3& scale);

	glm::mat4 GetModel() const;
	glm::vec3& GetPos();
	glm::vec3& GetRot();
	glm::vec3& GetScale();

	void SetPos(const glm::vec3& pos);
	void SetRot(const glm::vec3& rot);
	void SetScale(const glm::vec3& scale);
	
	virtual ~Transform();
protected:
private:
	glm::vec3 m_pos;
	glm::vec3 m_rot;
	glm::vec3 m_scale;
};

