//============================================================================
// Name        : Cube.cpp
// Author      : wenlong
// Version     :
// Copyright   : All copyrights reserved
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <windows.h>
#include <gl/gl.h>
#include <gl/glut.h>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include "Constants.h"
#include "Cube.h"
#include "Kube.h"
#include "GLWorld.h"
#include "Layer.h"
#include "GLColor.h"

using namespace std;
using namespace Constants;

Kube::Kube() :
		mAngle(0), mWorld(NULL), mPermutation(NULL), mCurrentLayer(NULL), mCurrentAngle(0), mEndAngle(0), mAngleIncrement(
				0), mCurrentLayerPermutation(NULL), _isFirstDraw(true) {

	for (int i = 0; i < CUBE_NUM; i++) {
		mCubes[i] = NULL;
	}

	for (int i = 0; i < LAYER_NUM; i++) {
		mLayers[i] = NULL;
	}
}

void Kube::start(int argc, char *argv[]) {
	printf("=======> start \n");
	makeGLWorld();
	printf("=======> end \n");
}

void Kube::myDisplay() {

	//animate();

	struct timeval curTime;
	gettimeofday(&curTime, NULL);
	if (_isFirstDraw) {
		gettimeofday(&_lastTime, NULL);
		_isFirstDraw = false;
	}

	printf("start draw()\n");

	glClearColor(0.5f, 0.5f, 0.5f, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	testGLError();

	glPushMatrix();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0, 0, -3.0f);
	glScalef(0.5f, 0.5f, 0.5f);
	glRotatef(mAngle, 0, 1, 0);
	glRotatef(mAngle * 0.25f, 1, 0, 0);

	testGLError();

	glColor4f(0.7f, 0.7f, 0.7f, 1.0f);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glEnable(GL_CULL_FACE);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);

	testGLError();

	mWorld->draw();

	float secDelta = curTime.tv_sec - _lastTime.tv_sec;

	float delta = secDelta * 1000 + (curTime.tv_usec - _lastTime.tv_usec) / 1000;

	printf("delta %f\n", delta);

	mAngle += (delta * 1.2f / 200);

	_lastTime = curTime;

	testGLError();
	printf("end draw()\n");

	glPopMatrix();
	glFlush();
}

void Kube::testGLError() {
	GLenum errorNum = glGetError();
	if (errorNum != 0) {
		printf("glerror %d\n", errorNum);
	}
}

void Kube::idle() {
	glutPostRedisplay();
}

void Kube::reshape(int w, int h) {

	glViewport(0, 0, w, h);

	float ratio = (float) w / h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-ratio, ratio, -1, 1, 2, 12);

	glDisable(GL_DITHER);

}

void Kube::makeGLWorld() {
	mWorld = new GLWorld();

	float one = 1;
	float half = 0.5f;

	GLColor* red = new GLColor(one, 0, 0);
	GLColor* green = new GLColor(0, one, 0);
	GLColor* blue = new GLColor(0, 0, one);
	GLColor* yellow = new GLColor(one, one, 0);
	GLColor* orange = new GLColor(one, half, 0);
	GLColor* white = new GLColor(one, one, one);
	GLColor* black = new GLColor(0, 0, 0);

	// coordinates for our cubes
	float c0 = -1.0f;
	float c1 = -0.38f;
	float c2 = -0.32f;
	float c3 = 0.32f;
	float c4 = 0.38f;
	float c5 = 1.0f;

	// top back, left to right
	mCubes[0] = new Cube(mWorld, c0, c4, c0, c1, c5, c1);
	mCubes[1] = new Cube(mWorld, c2, c4, c0, c3, c5, c1);
	mCubes[2] = new Cube(mWorld, c4, c4, c0, c5, c5, c1);
	// top middle, left to right
	mCubes[3] = new Cube(mWorld, c0, c4, c2, c1, c5, c3);
	mCubes[4] = new Cube(mWorld, c2, c4, c2, c3, c5, c3);
	mCubes[5] = new Cube(mWorld, c4, c4, c2, c5, c5, c3);
	// top front, left to right
	mCubes[6] = new Cube(mWorld, c0, c4, c4, c1, c5, c5);
	mCubes[7] = new Cube(mWorld, c2, c4, c4, c3, c5, c5);
	mCubes[8] = new Cube(mWorld, c4, c4, c4, c5, c5, c5);
	// middle back, left to right
	mCubes[9] = new Cube(mWorld, c0, c2, c0, c1, c3, c1);
	mCubes[10] = new Cube(mWorld, c2, c2, c0, c3, c3, c1);
	mCubes[11] = new Cube(mWorld, c4, c2, c0, c5, c3, c1);
	// middle middle, left to right
	mCubes[12] = new Cube(mWorld, c0, c2, c2, c1, c3, c3);
	mCubes[13] = NULL;
	mCubes[14] = new Cube(mWorld, c4, c2, c2, c5, c3, c3);

	// middle front, left to right
	mCubes[15] = new Cube(mWorld, c0, c2, c4, c1, c3, c5);
	printf("-----------------------------\n");
	mCubes[16] = new Cube(mWorld, c2, c2, c4, c3, c3, c5);
	printf("-----------------------------\n");
	mCubes[17] = new Cube(mWorld, c4, c2, c4, c5, c3, c5);
	// bottom back, left to right
	mCubes[18] = new Cube(mWorld, c0, c0, c0, c1, c1, c1);
	mCubes[19] = new Cube(mWorld, c2, c0, c0, c3, c1, c1);
	printf("-----------------------------\n");
	mCubes[20] = new Cube(mWorld, c4, c0, c0, c5, c1, c1);
	printf("-----------------------------\n");
	// bottom middle, left to right
	mCubes[21] = new Cube(mWorld, c0, c0, c2, c1, c1, c3);
	mCubes[22] = new Cube(mWorld, c2, c0, c2, c3, c1, c3);
	mCubes[23] = new Cube(mWorld, c4, c0, c2, c5, c1, c3);
	// bottom front, left to right
	mCubes[24] = new Cube(mWorld, c0, c0, c4, c1, c1, c5);
	mCubes[25] = new Cube(mWorld, c2, c0, c4, c3, c1, c5);
	mCubes[26] = new Cube(mWorld, c4, c0, c4, c5, c1, c5);

	// paint the sides
	// set all faces black by default
	for (int i = 0; i < CUBE_NUM; i++) {
		Cube* cube = mCubes[i];
		for (int j = 0; j < 6; j++) {
			setCubeFaceColor(cube, j, black);
		}
	}

	// paint top
	for (int i = 0; i < 9; i++) {
		setCubeFaceColor(mCubes[i], Cube::kTop, orange);
	}
	// paint bottom
	for (int i = 18; i < CUBE_NUM; i++) {
		setCubeFaceColor(mCubes[i], Cube::kBottom, red);
	}
	// paint left
	for (int i = 0; i < CUBE_NUM; i += 3) {
		setCubeFaceColor(mCubes[i], Cube::kLeft, yellow);
	}
	// paint right
	for (int i = 2; i < CUBE_NUM; i += 3) {
		setCubeFaceColor(mCubes[i], Cube::kRight, white);
	}
	// paint back
	for (int i = 0; i < CUBE_NUM; i += 9) {
		for (int j = 0; j < 3; j++) {
			setCubeFaceColor(mCubes[i + j], Cube::kBack, blue);
		}
	}
	// paint front
	for (int i = 6; i < CUBE_NUM; i += 9) {
		for (int j = 0; j < 3; j++) {
			setCubeFaceColor(mCubes[i + j], Cube::kFront, green);
		}
	}

	for (int i = 0; i < CUBE_NUM; i++) {
		if (mCubes[i] != NULL) {
			mWorld->addShape(mCubes[i]);
		}
	}

	// initialize our permutation to solved position
	mPermutation = new int[CUBE_NUM];
	for (int i = 0; i < CUBE_NUM; i++) {
		mPermutation[i] = i;
	}

	createLayers();
	updateLayers();

	mWorld->generate();
}

void Kube::createLayers() {
	mLayers[kUp] = new Layer(Layer::kAxisY);
	mLayers[kDown] = new Layer(Layer::kAxisY);
	mLayers[kLeft] = new Layer(Layer::kAxisX);
	mLayers[kRight] = new Layer(Layer::kAxisX);
	mLayers[kFront] = new Layer(Layer::kAxisZ);
	mLayers[kBack] = new Layer(Layer::kAxisZ);
	mLayers[kMiddle] = new Layer(Layer::kAxisX);
	mLayers[kEquator] = new Layer(Layer::kAxisY);
	mLayers[kSide] = new Layer(Layer::kAxisZ);
}

void Kube::updateLayers() {
	Layer* layer;
	GLShape** shapes;
	int i, j, k;

	// up layer
	layer = mLayers[kUp];
	shapes = layer->mShapes;
	for (i = 0; i < 9; i++) {
		shapes[i] = mCubes[mPermutation[i]];
	}

	// down layer
	layer = mLayers[kDown];
	shapes = layer->mShapes;
	for (i = 18, k = 0; i < 27; i++) {
		shapes[k++] = mCubes[mPermutation[i]];
	}

	// left layer
	layer = mLayers[kLeft];
	shapes = layer->mShapes;
	for (i = 0, k = 0; i < 27; i += 9) {
		for (j = 0; j < 9; j += 3) {
			shapes[k++] = mCubes[mPermutation[i + j]];
		}
	}

	// right layer
	layer = mLayers[kRight];
	shapes = layer->mShapes;
	for (i = 2, k = 0; i < 27; i += 9) {
		for (j = 0; j < 9; j += 3) {
			shapes[k++] = mCubes[mPermutation[i + j]];
		}
	}

	// front layer
	layer = mLayers[kFront];
	shapes = layer->mShapes;
	for (i = 6, k = 0; i < 27; i += 9) {
		for (j = 0; j < 3; j++) {
			shapes[k++] = mCubes[mPermutation[i + j]];
		}
	}

	// back layer
	layer = mLayers[kBack];
	shapes = layer->mShapes;
	for (i = 0, k = 0; i < 27; i += 9) {
		for (j = 0; j < 3; j++) {
			shapes[k++] = mCubes[mPermutation[i + j]];
		}
	}

	// middle layer
	layer = mLayers[kMiddle];
	shapes = layer->mShapes;
	for (i = 1, k = 0; i < 27; i += 9) {
		for (j = 0; j < 9; j += 3) {
			shapes[k++] = mCubes[mPermutation[i + j]];
		}
	}

	// equator layer
	layer = mLayers[kEquator];
	shapes = layer->mShapes;
	for (i = 9, k = 0; i < 18; i++) {
		shapes[k++] = mCubes[mPermutation[i]];
	}

	// side layer
	layer = mLayers[kSide];
	shapes = layer->mShapes;
	for (i = 3, k = 0; i < 27; i += 9) {
		for (j = 0; j < 3; j++) {
			shapes[k++] = mCubes[mPermutation[i + j]];
		}
	}
}

void Kube::animate() {
	// change our angle of view

	if (mCurrentLayer == NULL) {
//		int layerID = mRandom.nextInt(9);
		int layerID = 0;
		mCurrentLayer = mLayers[layerID];
		mCurrentLayerPermutation = mLayerPermutations[layerID];
		mCurrentLayer->startAnimation();
//		bool direction = mRandom.nextBoolean();
		bool direction = false;
//		int count = mRandom.nextInt(3) + 1;
		int count = 1;

		count = 1;
		direction = false;
		mCurrentAngle = 0;
		if (direction) {
			mAngleIncrement = (float) PI / 50;
			mEndAngle = mCurrentAngle + ((float) PI * count) * 0.5f;
		} else {
			mAngleIncrement = -(float) PI / 50;
			mEndAngle = mCurrentAngle - ((float) PI * count) * 0.5f;
		}
	}

	mCurrentAngle += mAngleIncrement;

	if ((mAngleIncrement > 0 && mCurrentAngle >= mEndAngle) || (mAngleIncrement < 0 && mCurrentAngle <= mEndAngle)) {
		mCurrentLayer->setAngle(mEndAngle);
		mCurrentLayer->endAnimation();
		mCurrentLayer = NULL;

		// adjust mPermutation based on the completed layer rotation
		int* newPermutation = new int[27];
		for (int i = 0; i < 27; i++) {
			newPermutation[i] = mPermutation[mCurrentLayerPermutation[i]];
		}
		mPermutation = newPermutation;
		updateLayers();

	} else {
		mCurrentLayer->setAngle(mCurrentAngle);
	}
}

void Kube::setCubeFaceColor(Cube* cube, int face, GLColor* color) {
	if (cube != NULL) {
		cube->setFaceColor(face, color);
	}
}

Kube::~Kube() {
	// TODO Auto-generated destructor stub
}

