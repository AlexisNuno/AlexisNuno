#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>

void MainLoop() {
	//bORRAMOS EL BUFFER DE COLOR Y PROFUNDIDAD SIEMPRE AL INICIO DE UN NUEVO FRAME
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//WARNING ESTO ES OPENGL clasico y no lo vamos a volver a usar ent todo el semestre
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0, 0.0f);

	glVertex2f(-1.0f, -1.0f);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(1.0, -1.0f);
	glColor3f(0.0f, 0.0f, 0.1f);
	glVertex2f(0.0f, 1.0f);

	glEnd();

	//INTERCAMBIAR LOS BUFFERS (EL QUE SE ESTABA RENDEREANDO CON EL QUE SE ESTABA MOSTRANDO 
	glutSwapBuffers();
}

int main(int argc, char* argv[]) {
	//Inicializamos freeglut
	//Freeglut se encarga de generar ventanas y manejar ventanas
	//Utilizamos freeglut para crear una ventana donde vamos a dibujar 
	glutInit(&argc, argv);
	//Tenemos que informar que queremos trabajar con el pipeline clasico, o sea Opengl viejito)
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
	//Freeglut nos permite configurar eventos que ocurren en la ventana, un evento que nos interesa es cuando
	//alguien cierra la ventana, en este caso simplemente dejamos de renderear y terminamos el programa.
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	//ESTAMOS CONfigurando el framebuffer. En este caso estamos solicitando un buffer de color true color RGBA
	//un buffer de profundidad y un segundo buffer para renderear (evitamos parpadeos al renderear)
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	//Solicitamos una ventana de 400 x 400 pixeles 
	glutInitWindowSize(400, 400);
	glutCreateWindow("Hellow World OpenGL");
	//Asociar una funcion de render, esta funcion se mandara a llamar para dibujar un frame
	glutDisplayFunc(MainLoop);
	//Inicializamos GLEW, esta libreria se encarga de obtener el API de OpenGl de nuestra tarjeta de video.
	glewInit();
	//Configurar OpenGL. Este es el olor por default del buffer de color en el framebuffer
	glClearColor(1.0f, 1.0f, 0.5f, 1.0f);
	//Iniciamos la aplicacion grafica, el main se pausará en esta linea hasta que se cierre la ventana de OpenGL
	glutMainLoop();
	return 0;
}