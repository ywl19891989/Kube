/*
 * m4.cpp
 *
 *  Created on: 2013-1-12
 *      Author: Hali
 */

#include "m4.h"
#include "GLVertex.h"

M4::M4() {
	for (int i = 0; i < 4; i++) {
		m[i] = new float[4];
		for (int j = 0; j < 4; j++) {
			m[i][j] = 0;
		}
	}
}

M4::M4(M4* other) {
	for (int i = 0; i < 4; i++) {
		m[i] = new float[4];
		for (int j = 0; j < 4; j++) {
			m[i][j] = other->m[i][j];
		}
	}
}

void M4::multiply(GLVertex* src, GLVertex* dest) {
	dest->x = src->x * m[0][0] + src->y * m[1][0] + src->z * m[2][0] + m[3][0];
	dest->y = src->x * m[0][1] + src->y * m[1][1] + src->z * m[2][1] + m[3][1];
	dest->z = src->x * m[0][2] + src->y * m[1][2] + src->z * m[2][2] + m[3][2];
}

M4* M4::multiply(M4* other) {
	M4* result = new M4();

	float** m1 = m;
	float** m2 = other->m;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			result->m[i][j] = m1[i][0] * m2[0][j] + m1[i][1] * m2[1][j] + m1[i][2] * m2[2][j] + m1[i][3] * m2[3][j];
		}
	}

	return result;
}

void M4::setIdentity() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			m[i][j] = (i == j ? 1 : 0);
		}
	}
}
