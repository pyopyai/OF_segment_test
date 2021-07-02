#pragma once
#include "ofMain.h"
#include <memory>

class Scene {
public:

	enum SceneIdx { quit_game_scene = 0, title_scene,play_game_scene, setting_scene };

	virtual ~Scene() {};

	virtual void draw() {};
	virtual void feadout(int mun) {};
	virtual void keyPressed(int key) {};
	virtual void keyReleased(int key) {};
	virtual void mouseDragged(int x, int y, int button) {};
	virtual void mouseMoved(int x, int y) {};
	virtual void mousePressed(int x, int y, int button) {};
	virtual void mouseReleased(int x, int y, int button) {};
	virtual void update() {};
	virtual void windowResized(int w, int h) {};
};