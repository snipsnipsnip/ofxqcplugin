//
//  QC_Plugin_TestPlugIn.h
//  QC Plugin Test
//
//  Created by vade on 10/10/09.
//  Copyright (c) 2009 __MyCompanyName__. All rights reserved.
//


// Open Frame Works headers
#import "testApp.h"
#import "ofMain.h"
#import "ofxQCPlugin.h" // this is our OF Addon  bridge to QC

#import <Quartz/Quartz.h>

// this is our Open Frameworks ofBaseApp implementation
// it should be a unique class name for all potential plugins.
class soundPlayerFFTTestApp;


@interface soundPlayerFFTPlugin : QCPlugIn
{
	// our faux window
	ofxQCBaseWindowProxy* windowProxy;

	// an instance of our ofBaseApp for our plugin
	soundPlayerFFTTestApp* pluginTestApp;
}

// we need these!
@property (assign) double inputMousePositionX;
@property (assign) double inputMousePositionY;
@property (assign) BOOL inputMousePressedLeft;
@property (assign) BOOL inputMousePressedRight;

@property (assign) double inputWindowSizeX;
@property (assign) double inputWindowSizeY;

@end
