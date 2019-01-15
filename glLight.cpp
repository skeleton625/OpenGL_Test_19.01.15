#include "glLight.h"
#include "OpenGL.h"

void glLight::glLight_init() {
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
}

void glLight::glLight_create_light(float light_pos[3]) {
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambi);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diff);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_spec);
}

void glLight::glLight_set_object_light(float ambi[4], float diff[4], float spec[4]) {
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambi);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diff);
	glMaterialfv(GL_FRONT, GL_SPECULAR, spec);
}

void glLight::glLight_set_light_format() {
	glMaterialfv(GL_FRONT, GL_AMBIENT, light_format);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, light_format);
	glMaterialfv(GL_FRONT, GL_SPECULAR, light_format);
}

void glLight::glLight_set_object_emi(float emi[4]) {
	glMaterialfv(GL_FRONT, GL_EMISSION, emi);
}
void glLight::glLight_set_emission_format() {
	glMaterialfv(GL_FRONT, GL_EMISSION, light_format);
}