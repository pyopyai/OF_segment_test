#include "ofApp.h"

ofPoint circlePos;
ofColor circleColor;
Beam testBeam(0, 0);

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

	//アルファチャンネル(透明度)を使用可能に
	ofEnableAlphaBlending();
	//混色を、加算混色に
	glBlendFunc(GL_ONE, GL_ONE);

	//---- beam draw --
	testBeam.draw();


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	//塗りを灰色に
	testBeam.mouseDragged(x, y);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

	testBeam.mouseReleased();

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
