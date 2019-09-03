// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "Display.h"
#include "Shader.h"
#include "Mesh.h"
#include "Texture.h"
#include "Transform.h"
#include "Camera.h"

int main(int argc, char **argv)
{
	Display display(800, 600, "Hello World!");
	Shader shader("./res/basicShader");
	Texture texture("./res/bricks.jpg");
	Camera camera(glm::vec3(0.0,0.0,-5), 70.0f, display.GetAspectRatio(), 0.01f, 1000.0f);
	Transform transform;

	float ticker = 0;
	
	//Vertex vertices[] = {
	//	Vertex(glm::vec3(-0.5,-0.5,0), glm::vec2(0,0)),
	//	Vertex(glm::vec3(0,0.5,0),glm::vec2(0.5,1.0)),
	//	Vertex(glm::vec3(0.5,-0.5,0),glm::vec2(1.0,0)),
	//};

	//unsigned int indices[] = { 0, 1, 2 };
	//unsigned int indexCount = sizeof(indices) / sizeof(indices[0]);
	//unsigned int vertexCount = sizeof(vertices) / sizeof(vertices[0]);

	//Mesh mesh(vertices, vertexCount, indices, indexCount);
	Mesh mesh2("./res/monkey.obj");

	
	while (!display.IsClosed())
	{
		float sinCounter = sinf(ticker);
		float cosCounter = cosf(ticker);
		
		transform.GetPos().x = sinf(ticker);
		transform.GetRot().z = cosCounter;
		transform.GetRot().x = cosCounter;
		transform.GetRot().y = cosCounter + 3;
		
		//transform.SetScale(glm::vec3(cosCounter, cosCounter, cosCounter));
		
		display.Clear(0.0f, 0.15f, 0.3f, 1.0f);
		//mesh.Draw();
		mesh2.Draw();
		shader.Bind();
		shader.Update(transform, camera);
		texture.Bind(0);
		display.Update();

		ticker += 0.01f;
	}
	
	return 0;
}
