#include "OpenGL.h"



void press_specKey(int key, int x, int y) {

}

void press_norKey(unsigned char key, int x, int y) {

}

void idle() {

}

void display() {

}

void reshape(int w, int h) {
	float ratio = w / (float)h;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, ratio, 1, 1000);
}

void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(680, 420);
	glutCreateWindow("Test(19.01.05)");

	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(press_norKey);
	glutSpecialFunc(press_specKey);
	glutMainLoop();
}