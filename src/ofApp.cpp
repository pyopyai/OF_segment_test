#include "ofApp.h"

ofPoint circlePos;
ofColor circleColor;
Beam testBeam(0, 0);

//--------------------------------------------------------------
void ofApp::setup(){
	//�w�i�F������
	ofBackground(0, 0, 0);
	//�t���[�����[�g��60fps��
	ofSetFrameRate(60);
	//�p�x��������
	angle = 0;
	
	ofSetCircleResolution(64); //�~�̉𑜓x�ݒ�






	ofSetWindowTitle("segment_test");
	
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	//�A���t�@�`�����l��(�����x)���g�p�\��
	ofEnableAlphaBlending();
	//���F���A���Z���F��
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
	//�h����D�F��
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
