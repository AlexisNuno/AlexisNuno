
#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <vector>

GLuint vao;

void Initialize();
{
	glBegin(GL_TRIANGLE_STRIP);
	std::vector<glm::vec12> positions;
	float n1 = glm::radians(18);
	float n2 = glm::radians(90);
	float n3 = glm::radians(162);
	float n4 = glm::radians(234);
	float n5 = glm::radians(306);

	float v11 = glm::cos(n1);
	float v12 = glm::sin(n1);
	float v21 = glm::cos(n2);
	float v22 = glm::sin(n2);
	float v31 = glm::cos(n3);
	float v32 = glm::sin(n3);
	float v41 = glm::cos(n4);
	float v42 = glm::cos(n4);
	float v51 = glm::cos(n5);
	float v52 = glm::sin(n5);

	float rv11 = (0.5)*glm::cos(n1);
	float rv12 = (0.5)*glm::sin(n1);
	float rv21 = (0.5)*glm::cos(n2);
	float rv22 = (0.5)*glm::sin(n2);
	float rv31 = (0.5)*glm::cos(n3);
	float rv32 = (0.5)*glm::sin(n3);
	float rv41 = (0.5)*glm::cos(n4);
	float rv42 = (0.5)*glm::cos(n4);
	float rv51 = (0.5)*glm::cos(n5);
	float rv52 = (0.5)*glm::sin(n5);

	positions.push_back(glm::vec2(v11, v12));
	positions.push_back(glm::vec2(rv11 rv12));
	positions.push_back(glm::vec2(v21, v22));
	positions.push_back(glm::vec2(rv21, rv22));
	positions.push_back(glm::vec2(v31, v32));
	positions.push_back(glm::vec2(rv31, rv32));
	positions.push_back(glm::vec2(v41, v42));
	positions.push_back(glm::vec2(rv41 rv42));
	positions.push_back(glm::vec2(v51, v52));
	positions.push_back(glm::vec2(rv51, rv52));
	
	glBindVertexArray(vao);
	glGenVertexArrays(1, &vao);
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * positions.size(),
		positions.data(), GL_STATIC_DRAW);


glGenVertexArrays(1, &vao);

glBindVertexArray(vao);


GLuint positionsVBO;

glGenBuffers(1, &positionsVBO);

glBindBuffer(GL_ARRAY_BUFFER, positionsVBO);

glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec2) * positions.size(),
	positions.data(), GL_STATIC_DRAW);

glEnableVertexAttribArray(0);

glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, nullptr);

glBindBuffer(GL_ARRAY_BUFFER, 0);

GLuint colorsVBO;
glGenBuffers(1, &colorsVBO);
glBindBuffer(GL_ARRAY_BUFFER, colorsVBO);
glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * colors.size(),
	colors.data(), GL_STATIC_DRAW);
glEnableVertexAttribArray(1);
glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
glBindBuffer(GL_ARRAY_BUFFER, 0);


glBindVertexArray(0);
}

void MainLoop()
{
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



	glBindVertexArray(vao);

	glDrawArrays(GL_TRIANGLES, 0, 3);

	glBindVertexArray(0);
	
	glutSwapBuffers();
}

int main(int argc, char* argv[])
{

	glutInit(&argc, argv);

	glutInitContextProfile(GLUT_CORE_PROFILE);
	
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);

	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	
	glutInitWindowSize(400, 400);
	glutCreateWindow("Hello World OpenGL");
	
	glutDisplayFunc(MainLoop);

	glewInit();


	glClearColor(1.0f, 1.0f, 0.5f, 1.0f);

	
	Initialize();


	glutMainLoop();

	return 0;
}

