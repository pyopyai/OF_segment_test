#include "GameObject.h"

Beam::Beam()
{

}

Beam::Beam(ofVec2f start, ofVec2f end)
{
	this->start_pos.set(start);
	this->end_pos.set(end);
}


