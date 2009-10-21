ofxQCPlugin Readme

Things to know for developers:

***************************************
Name Space Collisions:
***************************************

Since Quartz Composer plugins use ObjectiveC++ to load the Open Frameworks ofBaseApp (usually your 'testApp'), and more than one Open Frameworks powered Quartz Composer plugin may be loaded at a single time in a host app, we need to pay attention to name space collisions.

For example, if we have two Quartz Composer plugins that both have ofBaseApp implementations named 'testApp' that do different things (ie, one draws graphics the other does audio analysis), if both Quartz Composer plugins are loaded its undefined which testApp implementation is used. You will get one and only one of the testApp behaviors in instances of your different plugins, and things will break or behave in very odd ways and you will slowly go insane.

This means, basically, make sure to give each testApp class its own, as unique-as-possible class name. The same goes for Quartz Composer plugins, by the way, as documented in Apples Quartz Composer Custom Patch Programming guide, my advice is if you have a plugin called 'myAwesomeFooPlugin', call your ofBaseApp class 'myAwesomeFooTestApp', so you wont be confused later on.


***************************************
Header Paths 
***************************************

I probably messed something up in the initial release here of ofxQCPlugin, but I defined a new 'User Path' in the XCode target->build settings called 'OpenFrameworksPath'. Just enter the path to your Open Frameworks folder and the other paths should line up. I did this because I cant stand having things in the Open Frameworks folder. Sorry. 


***************************************
Example Plugins:  
***************************************

	OFtoQCImage: loads an image within Open Frameworks and outputs it to the Quartz Composer world. 
	
	QCtoOFImage: The opposite of above, sends any image from Quart Composer into Open Frameworks.
	
	SoundPlayerFFT: A port of the Sound Player FFT example with mp3 loading, playback, interactive mouse graphics and FFT analysis and visualization.