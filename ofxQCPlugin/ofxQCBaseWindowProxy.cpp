/*
 *  ofxQCBaseWindowProxy.cpp
 *  QC Plugin Test
 *
 *  Created by vade on 10/11/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#import "ofxQCBaseWindowProxy.h"
#import "ofMain.h"

#pragma mark Constructor

ofxQCBaseWindowProxy::ofxQCBaseWindowProxy() 
{	
	windowPos.set(0, 0);
	windowSize.set(0, 0);
	screenSize.set(0, 0);
	
	nFrameCount				= 0;
	windowMode				= 0;
	timeNow, timeThen, fps	= 0.0f;
	
	frameRate				= 0;
}

#pragma mark Initialization methods

void ofxQCBaseWindowProxy::setupOpenGL(int w, int h, int screenMode)
{	
	ofSetupGraphicDefaults();

	windowMode = screenMode;
	windowSize.set(w, h);
}

void ofxQCBaseWindowProxy::initializeWindow()
{	
}

void  ofxQCBaseWindowProxy::runAppViaInfiniteLoop(ofBaseApp * appPtr)
{
}


#pragma mark Per Frame methods

void ofxQCBaseWindowProxy::update()
{	
	ofGetAppPtr()->update();
}

void ofxQCBaseWindowProxy::draw()
{
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	
	// save projection state
	GLint matrixMode;
	glGetIntegerv(GL_MATRIX_MODE, &matrixMode);
	
	glMatrixMode(GL_TEXTURE);
	glPushMatrix();
	glLoadIdentity();
	
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();

	// set up coordinate system based on our proxy window.
	glOrtho(0.0, windowSize.x, windowSize.y, 0.0, -1.0, 1.0);
		
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
		
	ofGetAppPtr()->draw();
		
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	
	glMatrixMode(GL_TEXTURE);
	glPopMatrix();

	glMatrixMode(matrixMode);

	glPopAttrib();
	
	// FPS calculation stolen from Memos code. Thanks Memo :)
	timeNow = ofGetElapsedTimef();
	if( (timeNow - timeThen) > 0)
	{
		fps = 1.0 / (timeNow-timeThen);
		frameRate *= 0.9f;
		frameRate += 0.1f*fps;
	}
	timeThen = timeNow;
	
	// increase the overall frame count
	nFrameCount++;			
}

#pragma mark Proxy placeholder methods

void ofxQCBaseWindowProxy::setWindowPosition(int x, int y)
{
	windowPos.set(x, y);
}

ofPoint	ofxQCBaseWindowProxy::getWindowPosition() 
{
	return windowPos;
}

int	ofxQCBaseWindowProxy::getWindowMode()
{
	return windowMode;
}

float ofxQCBaseWindowProxy::getFrameRate()
{
	return frameRate;
}

int	ofxQCBaseWindowProxy::getFrameNum()
{
	return nFrameCount;
}

void ofxQCBaseWindowProxy::setFrameRate(float targetRate)
{	
}

void ofxQCBaseWindowProxy::setWindowShape(int w, int h)
{
	windowSize.set(w, h);
}

ofPoint	ofxQCBaseWindowProxy::getWindowSize()
{
	return windowSize;
}

ofPoint	ofxQCBaseWindowProxy::getScreenSize()
{
	return screenSize;
}

