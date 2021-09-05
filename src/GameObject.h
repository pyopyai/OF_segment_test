#pragma once

#include "ofMain.h"


class GameObject
{
public:
	enum ObjTypeIdx{beam = 0};
protected:
	ObjTypeIdx object_type;
};




class Segment :public GameObject
{
private:
	




public:
	Segment();
	Segment(ofVec2f start,ofVec2f end);

	ofVec2f start_pos;
	ofVec2f end_pos;
	ofColor color;
	bool is_active;
	void draw();
	bool is_crossing(Segment s);
};


class Beam :public GameObject
{
private:


public:
	std::vector<Segment> segments;
	Beam(int owner, int battery);
	int owner;
	int battery;
	ofVec2f start_pos;
	void mouseReleased();
	void draw();
	void mouseDragged(int x, int y,bool is_dragging);
	bool is_crossing(Segment s);
};

class Beam_Bundle :public GameObject
{
private:


public:
	Beam_Bundle();
	std::vector<Beam> beams;
	int now_playing;
	int active_beam;
	void mouseReleased();
	void draw();
	void mouseDragged(int x, int y);
	void next_beam();
	void previous_beam();
	bool is_dragging;
	void erase_beam();
};