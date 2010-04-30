//
//  QC_Plugin_TestPlugIn.h
//  QC Plugin Test
//
//  Created by vade on 10/10/09.
//  Copyright (c) 2009 __MyCompanyName__. All rights reserved.
//

// Open Frame Works headers
// IMPORT THESE FIRST SO YOU DONT MESS WITH GLEE ERRORS

#import "ofMain.h"
#import "ofxQCPlugin.h" // this is our OF Addon  bridge to QC

// NOW ITS SAFE TO IMPORT GLEE SINCE OFMAIN HAS IT.
// YES I AM YELLING

#import "testApp.h"


#import <Quartz/Quartz.h>

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
