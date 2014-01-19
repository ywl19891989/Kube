/*
 * GLColor.h
 *
 *  Created on: 2013-1-12
 *      Author: Hali
 */

#ifndef GLCOLOR_H_
#define GLCOLOR_H_

#include <GL/gl.h>

class GLColor {

public:

	GLfloat red;
	GLfloat green;
	GLfloat blue;
	GLfloat alpha;

	GLColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha = 1);

	bool equals(GLColor* color);
};

#endif /* GLCOLOR_H_ */
