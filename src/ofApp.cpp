#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//背景色を黒に
	ofBackground(0, 0, 0);
	//フレームレートを60fpsに
	ofSetFrameRate(60);
	//角度を初期化
	angle = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
	//角度を10°増加させる
	angle += 10;
}

//--------------------------------------------------------------
void ofApp::draw(){
	//現在の座標系を保存
	ofPushMatrix();
	//座標系の原点(0,0)を、画面の中心に
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2, 0);
	//画面のX軸を40°回転
	ofRotateX(40);
	//画面のZ軸を、angleの角度回転させる
	ofRotateZ(angle);
	//アルファチャンネル(透明度)を使用可能に
	ofEnableAlphaBlending();
	//混色を、加算混色に
	glBlendFunc(GL_ONE, GL_ONE);
	//塗りの色を赤に
	ofSetColor(255, 0, 0, 63);
	//円を描く
	ofEllipse(0, -40, 150, 150);
	//塗りの色を青に
	ofSetColor(0, 0, 255, 63);
	//円を描く
	ofEllipse(-40, 40, 150, 150);
	//塗りの色を緑に
	ofSetColor(0, 255, 0, 63);
	//円を描く
	ofEllipse(40, 40, 150, 150);
	//座標系を復元
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
