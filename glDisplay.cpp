#include "OpenGL.h"
#include "glDisplay.h"

void glDisplay::glDis_display() {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(cam_pos[0], cam_pos[1], cam_pos[2], 0, 0, 0, 0, 1, 0);
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_TEXTURE_2D);
	light.glLight_init();
	light.glLight_create_light(light_pos);
	//glDisable(GL_TEXTURE_GEN_S);
	//glDisable(GL_TEXTURE_GEN_T);
	glutPostRedisplay();
	glFlush();
}

void glDisplay::glDis_create_object() {

}

void glDisplay::glDis_create_background() {

}

void glDisplay::glDis_get_texID(unsigned int* tex_id) {

}

void glDisplay::glDis_press_norKey(unsigned char key) {

}

void glDisplay::glDis_press_specKey(int key) {

}