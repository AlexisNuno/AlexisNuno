#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <glm/glm.hpp>
#include <vector>
#include "Camera.h"
#include "Mesh.h"
#include "ShaderProgram.h"
#include "Transform.h"
#include <IL/il.h>
#include "texture2d.h"


Camera _camera;
Mesh _mesh;
Transform _transform;
Transform _transform2;
Transform _transform3;
Transform _transform4;
Transform _transform5;
Transform _transform6;
Transform _transform7;
Transform _joint1;
Transform _joint2;
Transform _joint3;
Transform _joint4;
Transform _joint5;
ShaderProgram _shaderProgram;
texture2d myTexture;
texture2d myTexture2;
float rotacion = 0;
float delta = -0.03;

// Función que va a inicializar toda la memoria del programa.
void Initialize()
{
	std::vector<glm::vec2> textureid;
	// Cara frontal

	textureid.push_back(glm::vec2(0.0f, 1.0f));
	textureid.push_back(glm::vec2(0.0f, 0.0f));
	textureid.push_back(glm::vec2(1.0f, 0.0f));
	textureid.push_back(glm::vec2(1.0f, 1.0f));
	// Cara lateral derecha
	textureid.push_back(glm::vec2(0.0f, 1.0f));
	textureid.push_back(glm::vec2(0.0f, 0.0f));
	textureid.push_back(glm::vec2(1.0f, 0.0f));
	textureid.push_back(glm::vec2(1.0f, 1.0f));
	//Cara Trasera
	textureid.push_back(glm::vec2(0.0f, 1.0f));
	textureid.push_back(glm::vec2(0.0f, 0.0f));
	textureid.push_back(glm::vec2(1.0f, 0.0f));
	textureid.push_back(glm::vec2(1.0f, 1.0f));
	//Cara lateral izquierda
	textureid.push_back(glm::vec2(0.0f, 1.0f));
	textureid.push_back(glm::vec2(0.0f, 0.0f));
	textureid.push_back(glm::vec2(1.0f, 0.0f));
	textureid.push_back(glm::vec2(1.0f, 1.0f));
	//Cara Superior
	textureid.push_back(glm::vec2(0.0f, 1.0f));
	textureid.push_back(glm::vec2(0.0f, 0.0f));
	textureid.push_back(glm::vec2(1.0f, 0.0f));
	textureid.push_back(glm::vec2(1.0f, 1.0f));
	//Cara Inferior
	textureid.push_back(glm::vec2(0.0f, 1.0f));
	textureid.push_back(glm::vec2(0.0f, 0.0f));
	textureid.push_back(glm::vec2(1.0f, 0.0f));
	textureid.push_back(glm::vec2(1.0f, 1.0f));


	// Vamos a crear una lista que va a almacenar las posiciones
	// en 2 dimensiones de un triángulo.
	// Esto es en CPU y RAM.
	std::vector<glm::vec3> positions;
	// Cara frontal
	positions.push_back(glm::vec3(-10.0f, -0.4f, 10.0f));
	positions.push_back(glm::vec3(10.0f, -0.4f, 10.0f));
	positions.push_back(glm::vec3(10.0f, 0.4f, 10.0f));
	positions.push_back(glm::vec3(-10.0f, 0.4f, 10.0f));
	// Cara lateral derecha
	positions.push_back(glm::vec3(10.0f, -0.4f, 10.0f));
	positions.push_back(glm::vec3(10.0f, -0.4f, -10.0f));
	positions.push_back(glm::vec3(10.0f, 0.4f, -10.0f));
	positions.push_back(glm::vec3(10.0f, 0.4f, 10.0f));
	//Cara Trasera
	positions.push_back(glm::vec3(10.0f, -0.4f, -10.0f));
	positions.push_back(glm::vec3(-10.0f, -0.4f, -10.0f));
	positions.push_back(glm::vec3(-10.0f, 0.4f, -10.0f));
	positions.push_back(glm::vec3(10.0f, 0.4f, -10.0f));
	//Cara lateral izquierda
	positions.push_back(glm::vec3(-10.0f, -0.4f, -10.0f));
	positions.push_back(glm::vec3(-10.0f, -0.4f, 10.0f));
	positions.push_back(glm::vec3(-10.0f, 0.4f, 10.0f));
	positions.push_back(glm::vec3(-10.0f, 0.4f, -10.0f));
	//Cara Superior
	positions.push_back(glm::vec3(-10.0f, 0.4f, 10.0f));
	positions.push_back(glm::vec3(10.0f, 0.4f, 10.0f));
	positions.push_back(glm::vec3(10.0f, 0.4f, -10.0f));
	positions.push_back(glm::vec3(-10.0f, 0.4f, -10.0f));

	//Cara Inferior 
	positions.push_back(glm::vec3(-10.0f, -0.4f, -10.0f));
	positions.push_back(glm::vec3(10.0f, -0.4f, -10.0f));
	positions.push_back(glm::vec3(10.0f, -0.4f, 10.0f));
	positions.push_back(glm::vec3(-10.0f, -0.4f, 10.0f));


	// Vamos a crear una lista para almacenar colores RGB
	// Esta lista está en CPU y RAM
	std::vector<glm::vec3> colors;
	// Cara frontal
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	// Cara lateral derecha
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	//Cara trasera
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	//Cara lateral izquierda
	colors.push_back(glm::vec3(1.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 1.0f));
	//Cara superior
	colors.push_back(glm::vec3(0.0f, 0.50f, 0.50f));
	colors.push_back(glm::vec3(0.0f, 0.50f, 0.50f));
	colors.push_back(glm::vec3(0.0f, 0.50f, 0.50f));
	colors.push_back(glm::vec3(0.0f, 0.50f, 0.50f));
	//Cara inferior
	colors.push_back(glm::vec3(0.5f, 0.5f, 1.0f));
	colors.push_back(glm::vec3(0.5f, 0.5f, 1.0f));
	colors.push_back(glm::vec3(0.4f, 0.5f, 1.0f));
	colors.push_back(glm::vec3(0.5f, 0.5f, 1.0f));

	//Normales

	std::vector<glm::vec3> normals;
	// Cara frontal
	normals.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	normals.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	normals.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	normals.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	// Cara lateral derecha
	normals.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	normals.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	normals.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	normals.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	//Cara Trasera
	normals.push_back(glm::vec3(0.0f, 0.0f, -1.0f));
	normals.push_back(glm::vec3(0.0f, 0.0f, -1.0f));
	normals.push_back(glm::vec3(0.0f, 0.0f, -1.0f));
	normals.push_back(glm::vec3(0.0f, 0.0f, -1.0f));
	//Cara lateral izquierda
	normals.push_back(glm::vec3(-1.0f, 0.0f, 0.0f));
	normals.push_back(glm::vec3(-1.0f, 0.0f, 0.0f));
	normals.push_back(glm::vec3(-1.0f, 0.0f, 0.0f));
	normals.push_back(glm::vec3(-1.0f, 0.0f, 0.0f));
	//Cara Superior
	normals.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	normals.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	normals.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	normals.push_back(glm::vec3(0.0f, 1.0f, 0.0f));

	//Cara Inferior 
	normals.push_back(glm::vec3(0.0f, -1.0f, 0.0f));
	normals.push_back(glm::vec3(0.0f, -1.0f, 0.0f));
	normals.push_back(glm::vec3(0.0f, -1.0f, 0.0f));
	normals.push_back(glm::vec3(0.0f, -1.0f, 0.0f));


	std::vector<unsigned int> indices = { 0, 1, 2, 0, 2, 3, 4, 5, 6, 4, 6, 7,8,9,10,8,10,11,12,14,15,12,13,14,16,18,19,16,17,18,20,22,23,20,21,22 };

	_mesh.CreateMesh(24);
	_mesh.SetIndices(indices, GL_STATIC_DRAW);
	_mesh.SetPositionAttribute(positions, GL_STATIC_DRAW, 0);
	_mesh.SetColorAttribute(colors, GL_STATIC_DRAW, 1);
	_mesh.SetNormalAttribute(normals, GL_STATIC_DRAW, 2);
	_mesh.SetTexCoordAttribute(textureid, GL_STATIC_DRAW, 3);

	_shaderProgram.CreateProgram();
	_shaderProgram.AttachShader("Default.vert", GL_VERTEX_SHADER);
	_shaderProgram.AttachShader("Default.frag", GL_FRAGMENT_SHADER);
	_shaderProgram.SetAttribute(0, "VertexPosition");
	_shaderProgram.SetAttribute(1, "VertexColor");
	_shaderProgram.SetAttribute(2, "VertexNormal");
	_shaderProgram.SetAttribute(3, "VertexTexCoord");

	_shaderProgram.LinkProgram();






	Transform GetModelMatrix;

	myTexture.LoadTexture("metal.jpg");
	myTexture2.LoadTexture("planta.jpg");


}



void MainLoop()
{


	//set rotation, deicirle hasta 90
	//llega a90 y se resta
	// Borramos el buffer de color y profundidad siempre al inicio de un nuevo frame.
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	//cuboPadre
	_transform.Rotate(0.0f, 0.05f, 0.0f, true);
	_transform.SetPosition(0.0f, 0.0f, -10.0f);
	_transform.SetScale(0.3f, 0.3f, 0.3f);


	_transform2.SetPosition(0.0f, 0.0f, -10.0f);
	_transform3.SetPosition(0.0f, 0.0f, 10.0f);
	_transform4.SetPosition(-10.0f, 0.0f, 0.0f);
	_transform5.SetPosition(10.0f, 0.0f, 0.0f);
	_transform6.SetPosition(10.0f, 0.0f, 0.0f);


	_shaderProgram.Activate();
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transform.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("ModelMatrix", _transform.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("NormalMatrix", glm::transpose(glm::inverse(glm::mat3(_transform.GetModelMatrix()))));
	_shaderProgram.SetUniformf("LightColor", 1.0f, 1.0f, 1.0f);
	_shaderProgram.SetUniformf("LightPosition", -5.0f, 5.0f, 5.0f);
	_shaderProgram.SetUniformf("CameraPosition", 0.0f, 0.0f, 0.0f);
	_shaderProgram.SetUniformi("DiffuseTexture", 0);
	glActiveTexture(GL_TEXTURE0);
	myTexture.Bind();
	_shaderProgram.SetUniformi("Mesher", 1);
	glActiveTexture(GL_TEXTURE1);
	myTexture2.Bind();
	_mesh.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	myTexture.Unbind();
	glActiveTexture(GL_TEXTURE1);
	myTexture2.Unbind();
	_shaderProgram.Deactivate();



	_shaderProgram.Deactivate();

	//joint1
	rotacion = rotacion + delta;
	if (rotacion <= -90.0f) {
		delta = 0.03;
	}
	if (rotacion >= 0) {
		delta = -0.03;
	}

	_joint1.SetRotation(-rotacion, 0.0f, 0.0f);
	_joint1.SetScale(1.0f, 1.0f, 1.0f);
	_joint1.SetPosition(0.0f, 0.0f, -10.0f);

	_shaderProgram.Activate();
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transform.GetModelMatrix()* _joint1.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("ModelMatrix", _joint1.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("NormalMatrix", glm::transpose(glm::inverse(glm::mat3(_transform.GetModelMatrix()))));
	_shaderProgram.SetUniformf("LightColor", 1.0f, 1.0f, 1.0f);
	_shaderProgram.SetUniformf("LightPosition", -5.0f, 5.0f, 5.0f);
	_shaderProgram.SetUniformi("DiffuseTexture", 0);

	_shaderProgram.Deactivate();
	//////////////////////////////cubo2
	_shaderProgram.Activate();
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transform.GetModelMatrix()* _joint1.GetModelMatrix()*_transform2.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("ModelMatrix", _transform2.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("NormalMatrix", glm::transpose(glm::inverse(glm::mat3(_transform2.GetModelMatrix()))));
	_shaderProgram.SetUniformf("LightColor", 1.0f, 1.0f, 1.0f);
	_shaderProgram.SetUniformf("LightPosition", -5.0f, 5.0f, 5.0f);
	_shaderProgram.SetUniformi("DiffuseTexture", 0);

	glActiveTexture(GL_TEXTURE0);
	myTexture.Bind();
	_shaderProgram.SetUniformi("Mesher", 1);
	glActiveTexture(GL_TEXTURE1);
	myTexture2.Bind();
	_mesh.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	myTexture.Unbind();
	glActiveTexture(GL_TEXTURE1);
	myTexture2.Unbind();
	_shaderProgram.Deactivate();

	glActiveTexture(GL_TEXTURE0);
	myTexture.Bind();
	_mesh.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	myTexture.Unbind();

	_shaderProgram.Deactivate();


	////////////////////// joint 2
	rotacion = rotacion + delta;
	if (rotacion <= -90.0f) {
		delta = 0.03;
	}
	if (rotacion >= 0) {
		delta = -0.03;
	}

	_joint2.SetRotation(rotacion, 0.0f, 0.0f);

	_joint2.SetPosition(0.0f, 0.0f, 10.0f);


	_shaderProgram.Activate();
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transform.GetModelMatrix()* _joint2.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("ModelMatrix", _joint2.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("NormalMatrix", glm::transpose(glm::inverse(glm::mat3(_transform2.GetModelMatrix()))));
	_shaderProgram.SetUniformf("LightColor", 1.0f, 1.0f, 1.0f);
	_shaderProgram.SetUniformf("LightPosition", -5.0f, 5.0f, 5.0f);
	_shaderProgram.SetUniformi("DiffuseTexture", 0);
	_shaderProgram.Deactivate();


	//////////////////////////////cubo3

	_shaderProgram.Activate();
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transform.GetModelMatrix()* _joint2.GetModelMatrix()*_transform3.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("ModelMatrix", _transform3.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("NormalMatrix", glm::transpose(glm::inverse(glm::mat3(_transform2.GetModelMatrix()))));
	_shaderProgram.SetUniformf("LightColor", 1.0f, 1.0f, 1.0f);
	_shaderProgram.SetUniformf("LightPosition", -5.0f, 5.0f, 5.0f);
	_shaderProgram.SetUniformi("DiffuseTexture", 0);
	glActiveTexture(GL_TEXTURE0);
	myTexture.Bind();
	_shaderProgram.SetUniformi("Mesher", 1);
	glActiveTexture(GL_TEXTURE1);
	myTexture2.Bind();
	_mesh.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	myTexture.Unbind();
	glActiveTexture(GL_TEXTURE1);
	myTexture2.Unbind();
	_shaderProgram.Deactivate();

	glActiveTexture(GL_TEXTURE0);
	myTexture.Bind();
	_mesh.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	myTexture.Unbind();

	_shaderProgram.Deactivate();

	////////////////////// joint 3

	rotacion = rotacion + delta;
	if (rotacion <= -90.0f) {
		delta = 0.03;
	}
	if (rotacion >= 0) {
		delta = -0.03;
	}

	_joint3.SetRotation(0.0f, 0.0f, rotacion);
	_joint3.SetPosition(-10.0f, 0.0f, 0.0f);

	_shaderProgram.Activate();
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transform.GetModelMatrix()* _joint3.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("ModelMatrix", _joint3.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("NormalMatrix", glm::transpose(glm::inverse(glm::mat3(_transform2.GetModelMatrix()))));
	_shaderProgram.SetUniformf("LightColor", 1.0f, 1.0f, 1.0f);
	_shaderProgram.SetUniformf("LightPosition", -5.0f, 5.0f, 5.0f);
	_shaderProgram.SetUniformf("CameraPosition", 0.0f, 0.0f, 0.0f);
	_shaderProgram.SetUniformi("DiffuseTexture", 0);



	_shaderProgram.Deactivate();

	//////////////////////////////cubo4


	_shaderProgram.Activate();
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transform.GetModelMatrix()* _joint3.GetModelMatrix()*_transform4.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("ModelMatrix", _transform4.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("NormalMatrix", glm::transpose(glm::inverse(glm::mat3(_transform2.GetModelMatrix()))));
	_shaderProgram.SetUniformi("DiffuseTexture", 0);
	glActiveTexture(GL_TEXTURE0);
	myTexture.Bind();
	_shaderProgram.SetUniformi("Mesher", 1);
	glActiveTexture(GL_TEXTURE1);
	myTexture2.Bind();
	_mesh.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	myTexture.Unbind();
	glActiveTexture(GL_TEXTURE1);
	myTexture2.Unbind();
	_shaderProgram.Deactivate();
	glActiveTexture(GL_TEXTURE0);
	myTexture.Bind();
	_mesh.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	myTexture.Unbind();

	_shaderProgram.Deactivate();


	////////////////////// joint 4


	rotacion = rotacion + delta;
	if (rotacion <= -90.0f) {
		delta = 0.03;
	}
	if (rotacion >= 0) {
		delta = -0.03;
	}

	_joint4.SetRotation(0.0f, 0.0f, -rotacion);
	_joint4.SetPosition(10.0f, 0.0f, 0.0f);


	_shaderProgram.Activate();
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transform.GetModelMatrix()* _joint4.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("ModelMatrix", _joint4.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("NormalMatrix", glm::transpose(glm::inverse(glm::mat3(_transform2.GetModelMatrix()))));
	_shaderProgram.SetUniformf("LightColor", 1.0f, 1.0f, 1.0f);
	_shaderProgram.SetUniformf("LightPosition", -5.0f, 5.0f, 5.0f);
	_shaderProgram.SetUniformi("DiffuseTexture", 0);



	_shaderProgram.Deactivate();

	//////////////////////////////cubo5


	_shaderProgram.Activate();
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transform.GetModelMatrix()* _joint4.GetModelMatrix()*_transform5.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("ModelMatrix", _transform5.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("NormalMatrix", glm::transpose(glm::inverse(glm::mat3(_transform2.GetModelMatrix()))));
	_shaderProgram.SetUniformf("LightColor", 1.0f, 1.0f, 1.0f);
	_shaderProgram.SetUniformf("LightPosition", -5.0f, 5.0f, 5.0f);
	_shaderProgram.SetUniformi("DiffuseTexture", 0);
	glActiveTexture(GL_TEXTURE0);
	myTexture.Bind();
	_shaderProgram.SetUniformi("Mesher", 1);
	glActiveTexture(GL_TEXTURE1);
	myTexture2.Bind();
	_mesh.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	myTexture.Unbind();
	glActiveTexture(GL_TEXTURE1);
	myTexture2.Unbind();
	_shaderProgram.Deactivate();

	glActiveTexture(GL_TEXTURE0);
	myTexture.Bind();
	_mesh.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	myTexture.Unbind();

	_shaderProgram.Deactivate();

	////////////////////// joint 5


	rotacion = rotacion + delta;
	if (rotacion <= -90.0f) {
		delta = 0.03;
	}
	if (rotacion >= 0) {
		delta = -0.03;
	}

	_joint5.SetRotation(0.0f, 0.0f, -rotacion);
	_joint5.SetPosition(10.0f, 0.0f, 0.0f);


	_shaderProgram.Activate();
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection()* _transform.GetModelMatrix()*_joint4.GetModelMatrix()*_transform5.GetModelMatrix()*_joint5.GetModelMatrix()*_transform6.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("ModelMatrix", _joint5.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("NormalMatrix", glm::transpose(glm::inverse(glm::mat3(_transform2.GetModelMatrix()))));
	_shaderProgram.SetUniformf("LightColor", 1.0f, 1.0f, 1.0f);
	_shaderProgram.SetUniformf("LightPosition", -5.0f, 5.0f, 5.0f);
	_shaderProgram.SetUniformi("DiffuseTexture", 0);



	_shaderProgram.Deactivate();

	//////////////////////////////cubo6

	_shaderProgram.Activate();
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection()* _transform.GetModelMatrix()*_joint4.GetModelMatrix()*_transform5.GetModelMatrix()*_joint5.GetModelMatrix()*_transform6.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("NormalMatrix", glm::transpose(glm::inverse(glm::mat3(_transform2.GetModelMatrix()))));
	_shaderProgram.SetUniformf("LightColor", 1.0f, 1.0f, 1.0f);
	_shaderProgram.SetUniformf("LightPosition", -5.0f, 5.0f, 5.0f);
	_shaderProgram.SetUniformi("DiffuseTexture", 0);
	glActiveTexture(GL_TEXTURE0);
	myTexture.Bind();
	_shaderProgram.SetUniformi("Mesher", 1);
	glActiveTexture(GL_TEXTURE1);
	myTexture2.Bind();
	_mesh.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	myTexture.Unbind();
	glActiveTexture(GL_TEXTURE1);
	myTexture2.Unbind();
	_shaderProgram.Deactivate();
	glActiveTexture(GL_TEXTURE0);
	myTexture.Bind();
	_mesh.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	myTexture.Unbind();

	_shaderProgram.Deactivate();

	_shaderProgram.Activate();

	_transform7.SetPosition(0.0f, -2.0f, 0.0f);
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transform7.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("ModelMatrix", _transform7.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("NormalMatrix", glm::transpose(glm::inverse(glm::mat3(_transform2.GetModelMatrix()))));
	_shaderProgram.SetUniformf("LightColor", 1.0f, 1.0f, 1.0f);
	_shaderProgram.SetUniformf("LightPosition", -5.0f, 5.0f, 5.0f);
	_shaderProgram.SetUniformi("DiffuseTexture", 0);
	glActiveTexture(GL_TEXTURE0);
	myTexture.Bind();
	_shaderProgram.SetUniformi("Mesher", 1);
	glActiveTexture(GL_TEXTURE1);
	myTexture2.Bind();
	_mesh.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	myTexture.Unbind();
	glActiveTexture(GL_TEXTURE1);
	myTexture2.Unbind();
	_shaderProgram.Deactivate();

	/*glActiveTexture(GL_TEXTURE0);
	myTexture.Bind();
	_mesh.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	myTexture.Unbind();*/

	//_shaderProgram.Deactivate();

	// Intercambiar los buffers (el que se estaba rendereando con el que se estaba
	// mostrando).


	glutSwapBuffers();
}



void Idle()
{

	// Cuando OpenGL entra en modo de reposo 
	// (para guardar bateria, por ejemplo)
	// le decimos que vuelva a dibujar ->
	// Vuelve a mandar a llamar GameLoop
	glutPostRedisplay();

}


void ReshapeWindow(int width, int height)
{
	glViewport(0, 0, width, height);
	_camera.SetPerspective(1.0f, 50.0f, 60.0f, (float)width / (float)height);
	_camera.SetPosition(0.0f, 4.0f, 10.0f);
}

int main(int argc, char* argv[])
{
	// Inicializamos freeglut. 
	// Freeglut se encarga de generar y manejar ventanas.
	// Utilizamos freeglut para crear una ventana donde vamos a dibujar.
	glutInit(&argc, argv);
	// Tenemos que informar que queremos trabajar con el pipeline
	// programable (OpenGL moderno).
	glutInitContextProfile(GLUT_CORE_PROFILE);
	// Freeglut nos permite configurar eventos que ocurren en la ventana.
	// Un evento que nos interesa es cuando alguien cierra la ventana.
	// En este caso, simplemente dejamos de renderear y terminamos el programa.
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	// Configuramos el framebuffer. En este caso estamos solicitando un buffer
	// de color true color RGBA, un buffer de profundidad y un segundo buffer 
	// para rendererar (evitamos parpadeos al renderear).
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	// Solicitamos una ventana de 400x400 pixeles.
	glutInitWindowSize(400, 400);
	// Creamos y abrimos la ventana con un título personalizado.
	glutCreateWindow("Hello World OpenGL");
	// Asociar una función de render. Esta función se mandará a llamar para 
	// dibujar un frame.
	glutDisplayFunc(MainLoop);
	// Asociamos una función para el cambio de resolución
	// de la ventana. Freeglut la va a mandar a llamar
	// cuando alguien cambie el tamaño de la venta.
	glutReshapeFunc(ReshapeWindow);
	// Asociamos la función que se mandará a llamar
	// cuando OpenGL entre en modo de reposo.
	glutIdleFunc(Idle);

	// Inicializar DevIL. Esto se debe hacer sólo una vez.
	ilInit();
	// Cambiar el punto de origen de las texturas. Por default, DevIL
	// pone un punto de origen en la esquina superior izquierda.
	// Esto es compatible con el sistema operativo, pero no con el
	// funcionamiento de OpenGL.
	ilEnable(IL_ORIGIN_SET);
	// Configurar el punto de origen de las texturas en la esquina
	// inferior izquierda
	ilOriginFunc(IL_ORIGIN_LOWER_LEFT);

	// Inicializamos GLEW. Esta librería se encarga de obtener el API
	// de OpenGL de nuestra tarjeta de video. SHAME ON YOU MICROSOFT.

	glewInit();

	// COnfigurar OpenGL. Este es el color por default del buffer de color
	// en el framebuffer.
	glClearColor(1.0f, 1.0f, 0.5f, 1.0f);
	// Ademas de solicitar el buffer de profundidad, tenemos
	// que decirle a OpenGL que lo queremos activo
	glEnable(GL_DEPTH_TEST);
	// Activamos el borrado de caras traseras.
	// Ahora todos los triangulos que dibujemos deben estar en CCW
	glEnable(GL_CULL_FACE);
	// No dibujar las caras traseras de las geometrías.
	glCullFace(GL_BACK);


	std::cout << glGetString(GL_VERSION) << std::endl;



	// Configurar la memoria que la aplicación va a necesitar.
	Initialize();
	//la poition de la luz
	//activar shader, ahacer uniforms y desactivar. 

	// Iniciamos la aplicacion gráfica. El main se pausará en estea línea
	// hasta que se cierre la ventana de OpenGL.
	glutMainLoop();
	//

	return 0;
}