#pragma once

#include "ofMain.h"
#include <iostream>
#include <memory>
#include "GameObject.h"
#include "Scene.h"


class ofApp : public ofBaseApp{
private:
	std::unique_ptr<Scene> current_scene;
public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
	
	int angle;
	
	Beam_Bundle beam_bundle;

};
