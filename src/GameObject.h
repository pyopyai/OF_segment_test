#pragma once

#include "ofMain.h"

class GameObject
{
public:
	enum ObjTypeIdx{beam = 0};
protected:
	ObjTypeIdx object_type;
};

class Beam :public GameObject
{
private:
	

	int owner;


public:
	Beam();
	Beam(ofVec2f start,ofVec2f end);

	ofVec2f start_pos;
	ofVec2f end_pos;
	ofColor color;


};

