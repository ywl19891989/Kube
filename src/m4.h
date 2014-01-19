/*
 * m4.h
 *
 *  Created on: 2013-1-12
 *      Author: Hali
 */

#ifndef M4_H_
#define M4_H_

class GLVertex;

/**
 *
 * A 4x4 float matrix
 *
 */
class M4 {

public:
	float* m[4];
	M4();

	M4(M4* other);

	void multiply(GLVertex* src, GLVertex* dest);

	M4* multiply(M4* other);

	void setIdentity();

};

#endif /* M4_H_ */
