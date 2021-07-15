#include "GameObject.h"

Segment::Segment()
{

}

Segment::Segment(ofVec2f start, ofVec2f end)
{
	this->start_pos.set(start);
	this->end_pos.set(end);
}

void Segment::draw()
{
	ofSetColor(this->color);

	ofDrawLine(this->start_pos, this->end_pos);
}


Beam::Beam(int owner,int battery)
{
	ofVec2f start;
	switch (battery)
	{
	case 0:
		start.set(0, 0);
	case 1:
		start.set(0, 255);
	case 2:
		start.set(255, 0);
	case 3:
		start.set(255, 255);
	default:
		break;
	}

	this->segments.emplace_back(start,start);
}

void Beam::mouseReleased()
{
	// ––”öü•ª‚ð—LŒø‰»‚µÔ‚É
	auto last_segment = this->segments.rbegin();
	last_segment->is_active = TRUE;
	last_segment->color = ofColor(255, 0, 0);



	//––”ö‚ÉVü•ª’Ç‰Á
	this->segments.emplace_back(last_segment->end_pos, last_segment->end_pos);
	auto new_segment = this->segments.rbegin();
	new_segment->is_active = FALSE;
	new_segment->color = ofColor(0, 255, 0);
}

void Beam::draw() 
{
	for (Segment segment : this->segments)
	{
		segment.draw();
	}
}

void Beam::mouseDragged(int x, int y) {
	//“h‚è‚ðŠDF‚É
	auto last_segment = this->segments.rbegin();
	last_segment->color = ofColor(50, 50, 50);
	last_segment->end_pos.set(x, y);
}