#include "ofApp.h"

ofPoint circlePos;
ofColor circleColor;

//--------------------------------------------------------------
void ofApp::setup(){
	//�w�i�F������
	ofBackground(0, 0, 0);
	//�t���[�����[�g��60fps��
	ofSetFrameRate(60);
	//�p�x��������
	angle = 0;
	ofSetCircleResolution(64); //�~�̉𑜓x�ݒ�



	testBeam.start_pos.set(13, 167);
	testBeam.end_pos.set(53, 167);


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

	ofSetColor(testBeam.color);
	ofDrawLine(testBeam.start_pos,testBeam.end_pos);


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
	testBeam.color = ofColor(50,50,50);
	testBeam.end_pos.set(x, y);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	//�h���Ԃ�
	testBeam.color = ofColor(255, 0, 0);

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
