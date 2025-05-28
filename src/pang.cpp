#include "freeglut.h"
//#include "raton.h"
#include"Mundo.h"
#include<iostream>
//los callback, funciones que seran llamadas automaticamente por la glut
//cuando sucedan eventos
// 
Mundo mundo;
//NO HACE FALTA LLAMARLAS EXPLICITAMENTE
void OnDraw(void);		 //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	
void OnMouseDown(int button, int state, int x, int y);//cuando se pulse el raton, reconoce el click derecho e izquierdo, mantenido o no, eje x y

int main(int argc, char* argv[])
{
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana//cambio
	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("MiJuego");

	//habilitar luces y definir perspectiva

	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(40.0, 800 / 600.0f, 0.1, 150);


	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25, OnTimer, 0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(OnKeyboardDown);//para usar teclado
	glutMouseFunc(OnMouseDown); //para usar raton

	//pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop();

	return 0;
}
void OnDraw(void)
{
	//Borrado de la pantalla	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//aqui dibujamos la pantalla de inicio, el tablero de ajedrez, o quizas se dibuja en otra clase llamada tablero.
	//la idea es una maquina de estado, el tablero es fijo, se los que se mueven son las piezas.
	mundo.dibuja();



	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}
void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	//m.teclado(key);
}
void OnMouseDown(int button, int state, int x, int y) {
	//comprobar la posicion de raton
	//este codigo es para ver como funciona el raton
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		std::cout << "Clic izquierdo en: (" << x << ", " << y << ")" << std::endl;
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		std::cout << "Clic derecho en: (" << x << ", " << y << ")" << std::endl;
	}
	//para utilizar las posiciones x e y de raton y jugar
	mundo.raton(button, state, x, y);
}

void OnTimer(int value)
{

}

