#include "ofApp.h"

ofPoint circlePos;
ofColor circleColor;



//--------------------------------------------------------------
void ofApp::setup(){
	//背景色を黒に
	ofBackground(0, 0, 0);
	//フレームレートを60fpsに
	ofSetFrameRate(60);
	//角度を初期化
	angle = 0;
	
	ofSetCircleResolution(64); //円の解像度設定




	ofSetWindowTitle("segment_test");

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){



	beam_bundle.draw();



	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key) {
	case OF_KEY_LEFT:
		beam_bundle.previous_beam();
		break;
	case OF_KEY_RIGHT:
		beam_bundle.next_beam();
		break;

	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	beam_bundle.mouseDragged(x, y);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

	beam_bundle.mouseReleased();
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
