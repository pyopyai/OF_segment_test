#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//�w�i�F������
	ofBackground(0, 0, 0);
	//�t���[�����[�g��60fps��
	ofSetFrameRate(60);
	//�p�x��������
	angle = 0;
	testBeam.set_start(ofVec2f(13, 167));
	testBeam.set_end(ofVec2f(83, 267));

	ofSetWindowTitle("segment_test");
	
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	//���݂̍��W�n��ۑ�
	ofPushMatrix();
	//���W�n�̌��_(0,0)���A��ʂ̒��S��
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2, 0);
	//��ʂ�X����40����]
	ofRotateX(40);
	//��ʂ�Z�����Aangle�̊p�x��]������
	ofRotateZ(angle);
	//�A���t�@�`�����l��(�����x)���g�p�\��
	ofEnableAlphaBlending();
	//���F���A���Z���F��
	glBlendFunc(GL_ONE, GL_ONE);
	//�h��̐F��Ԃ�
	ofSetColor(255, 0, 0, 63);

	ofDrawLine(testBeam.get_start(),testBeam.get_end());
	//�~��`��
	ofEllipse(40, 40, 150, 150);
	//���W�n�𕜌�
	ofPopMatrix();
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

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
