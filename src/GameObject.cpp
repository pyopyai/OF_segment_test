#include "GameObject.h"

Beam::Beam()
{

}

Beam::Beam(ofVec2f start, ofVec2f end)
{
	this->start_pos.set(50,100);
	this->end_pos.set(40,60);
}

ofVec2f Beam::get_start()
{
	return this->start_pos;
}

ofVec2f Beam::get_end()
{
	return this->end_pos;
}

void Beam::set_start(ofVec2f start)
{
	this->start_pos = start;
}

void Beam::set_end(ofVec2f end)
{
	this->end_pos = end;
}
