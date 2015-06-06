#include "ofApp.h"

//--------------------------------------------------------------
void ofToQCImageDemoApp::setup(){
	
	// force the use of a texture to make sure our
	// image has an internal texture representation
	// load the image and then we know QC can get the contents.
	
	testOfImage.setUseTexture(true);
	testOfImage.loadImage("tdf_1972_poster.jpg");
}

//--------------------------------------------------------------
void ofToQCImageDemoApp::update(){

}

//--------------------------------------------------------------
void ofToQCImageDemoApp::draw(){

}

//--------------------------------------------------------------
void ofToQCImageDemoApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofToQCImageDemoApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofToQCImageDemoApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofToQCImageDemoApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofToQCImageDemoApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofToQCImageDemoApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofToQCImageDemoApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofToQCImageDemoApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofToQCImageDemoApp::dragEvent(ofDragInfo dragInfo){ 

}