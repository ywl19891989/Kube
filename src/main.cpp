/*
 * main.cpp
 *
 *  Created on: 2013-12-29
 *      Author: Hali
 */

#include <GL/gl.h>
#include <GL/glut.h>
#include "Kube.h"
#include "Constants.h"
#include <stdio.h>

Kube* kube = NULL;

void idle();
void myDisplay();
void reshape(int w, int h);

int main(int argc, char *argv[]) {

	printf("main start\n");

	glutInit(&argc, argv);

//	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(Constants::sceneWidth, Constants::sceneHeight);
	glutCreateWindow("Cube");

	kube = new Kube;
	kube->start(argc, argv);

	glutReshapeFunc(reshape);
	glutIdleFunc(idle);
	glutDisplayFunc(myDisplay);
	glutMainLoop();

	return 0;
}

void myDisplay() {

//	glPushMatrix();
//	glTranslatef(-1.5f, 0.0f, 0.0f);						// Move Left 1.5 Units And Into The Screen 6.0
//	glBegin(GL_TRIANGLES);						// Drawing Using Triangles
//	{
//		glColor3f(1, 0, 0);
//		glVertex3f(0.0f, 1.0f, 0.0f);					// Top
//		glVertex3f(-1.0f, -1.0f, 0.0f);				// Bottom Left
//		glVertex3f(1.0f, -1.0f, 0.0f);					// Bottom Right
//	}
//	glEnd();											// Finished Drawing The Triangle
//	glTranslatef(3.0f, 0.0f, 0.0f);					// Move Right 3 Units
//	glBegin(GL_QUADS);									// Draw A Quad
//	{
//		glColor3f(1, 1, 0);
//		glVertex3f(-1.0f, 1.0f, 0.0f);					// Top Left
//		glVertex3f(1.0f, 1.0f, 0.0f);					// Top Right
//		glVertex3f(1.0f, -1.0f, 0.0f);					// Bottom Right
//		glVertex3f(-1.0f, -1.0f, 0.0f);				// Bottom Left
//	}
//	glEnd();											// Done Drawing The Quad
//	glPopMatrix();
//	glFlush();

	kube->myDisplay();
}

void idle() {
	kube->idle();
}

void reshape(int width, int height) {
	kube->reshape(width, height);
}

