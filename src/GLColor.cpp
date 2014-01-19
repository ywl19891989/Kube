/*
 * GLColor.cpp
 *
 *  Created on: 2013-12-29
 *      Author: Hali
 */

#include "GLColor.h"

GLColor::GLColor(float red, float green, float blue, float alpha/* = 1*/) {
	this->red = red;
	this->green = green;
	this->blue = blue;
	this->alpha = alpha;
}

bool GLColor::equals(GLColor* color) {
	return (red == color->red && green == color->green && blue == color->blue && alpha == color->alpha);
}

