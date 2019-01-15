#include "OpenGL.h"
#include "glObject.h"
#include <cmath>

void glObject::set_texID(unsigned int tex_id) { this->tex_id = tex_id; }
float glObject::getX() { return x; }
float glObject::getY() { return y; }
float glObject::getZ() { return z; }
void glObject::setX(float x) { this->x = x; }
void glObject::setY(float y) { this->y = y; }
void glObject::set(float z) { this->z = z; }

void glObject::glObject_create_plane(float size[3]) {
	glPushMatrix(); {
		glTranslatef(x, y, z);
		glScalef(size[0], size[1], size[2]);
		glBindTexture(GL_TEXTURE_2D, tex_id);
		for (int i = 0; i < 4; i++) {
			glTexCoord2fv(tex[i]);
			glNormal3fv(plane[i]);
			glVertex3fv(plane[i]);
		}
	}
	glPopMatrix();
}

void glObject::glObject_create_cube(float size[3]) {
	glPushMatrix(); {
		glTranslatef(x, y, z);
		glScalef(size[0], size[1], size[2]);
		glBindTexture(GL_TEXTURE_2D, tex_id);
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 4; j++) {
				glTexCoord2fv(tex[j]);
				glNormal3fv(cube[i][j]);
				glVertex3fv(cube[i][j]);
			}
		}
	}
	glPopMatrix();
}

void glObject::glObject_create_sphere(float size[3]) {
	GLUquadric* sphere = gluNewQuadric();
	glPushMatrix(); {
		glTranslatef(x, y, z);
		glScalef(size[0], size[1], size[2]);
		gluSphere(sphere, 1, 30, 100);
	}
	glPopMatrix();
	gluDeleteQuadric(sphere);
}

void glObject::glObject_create_cylinder(float size[3]) {
	float v = sqrt(2);
	float ax = 57.2957795*acos(1 / v);
	GLUquadric *quadric = gluNewQuadric();
	glPushMatrix(); {
		glTranslatef(x, y, z);
		glScalef(size[0], size[1], size[2]);
		glBindTexture(GL_TEXTURE_2D, tex_id);
		gluQuadricTexture(quadric, GL_TRUE);
		gluQuadricNormals(quadric, GLU_SMOOTH);
		glPushMatrix(); {
			//draw the cylinder body
			gluQuadricOrientation(quadric, GLU_OUTSIDE);
			gluCylinder(quadric, 1, 1, v, 100, 1);
			//draw the first cap
			gluQuadricOrientation(quadric, GLU_INSIDE);
			gluDisk(quadric, 0, 1, 100, 1);
			glTranslatef(0, 0, v);
			//draw the second cap
			gluQuadricOrientation(quadric, GLU_OUTSIDE);
			gluDisk(quadric, 0, 1, 100, 1);
		}
		glPopMatrix();
	}
	glPopMatrix();
	gluDeleteQuadric(quadric);
}