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
	ofVec2f start_pos;
	ofVec2f end_pos;

	int owner;



public:
	Beam();
	Beam(ofVec2f start,ofVec2f end);
	ofVec2f get_start(void);
	ofVec2f get_end(void);
	void set_start(ofVec2f);
	void set_end(ofVec2f);


};
