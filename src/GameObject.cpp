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

//線分の交差判定　詳細：http://www5d.biglobe.ne.jp/~tomoya03/shtml/algorithm/Intersection.htm
bool Segment::is_crossing(Segment s) {
	int x1 = this->start_pos.x, x2 = this->end_pos.x ,x3 = s.start_pos.x, x4 = s.end_pos.x;
	int y1 = this->start_pos.y, y2 = this->end_pos.y, y3 = s.start_pos.y, y4 = s.end_pos.y;
	int ta = (x3 - x4)*(y1 - y3) + (y3 - y4)*(x3 - x1);
	int tb = (x3 - x4)*(y2 - y3) + (y3 - y4)*(x3 - x2);
	int tc = (x1 - x2)*(y3 - y1) + (y1 - y2)*(x1 - x3);
	int td = (x1 - x2)*(y4 - y1) + (y1 - y2)*(x1 - x4);
	return ta * tb < 0 && tc*td < 0;
}

Beam::Beam(int owner,int battery)
{
	this->owner = owner;
	this->battery = battery;

	ofVec2f start;
	switch (this->battery)
	{
	case 0:
		start.set(0, 0);
		break;
	case 1:
		start.set(0, 500);
		break;
	case 2:
		start.set(500, 0);
		break;
	case 3:
		start.set(500, 500);
		break;
	default:
		break;
	}

	this->segments.emplace_back(start,start);
}

void Beam::mouseReleased()
{
	// 末尾のたね線分を有効化しアクティブに
	auto last_segment = this->segments.rbegin();
	last_segment->is_active = TRUE;
	switch (this->owner)
	{
	case 0:
		last_segment->color = ofColor(255, 0, 0);
		break;

	case 1:
		last_segment->color = ofColor(0, 255, 0);
		break;

	default:
		last_segment->color = ofColor(0, 0, 255);
		break;
	}



	//末尾に新たね線分追加
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
	auto last_segment = this->segments.rbegin();
	last_segment->color = ofColor(50, 50, 50);
	last_segment->end_pos.set(x, y);
}

bool Beam::is_crossing(Segment s) {
	for (auto iter = segments.begin(); iter != segments.end(); ++iter)
	{
		if (iter->is_crossing(s)) {
			segments.erase(iter, segments.end());
			return TRUE;
		}
	}
	return FALSE;
}
Beam_Bundle::Beam_Bundle() {
	Beam b0(0, 0);
	Beam b1(0, 1);
	Beam b2(1, 2);
	Beam b3(1, 3);

	beams = { b0, b1, b2, b3 };

	active_beam = 0;
	now_playing = 0;
	is_dragging = FALSE;
	
}

void Beam_Bundle::draw()
{
	for (Beam beam : this->beams)
	{
		beam.draw();
	}
	//アクティブなビームの先端を示すマーカー
	if (is_dragging) {
		return;
	}
	ofSetColor(0, 50, 200);
	ofVec2f marker_pos=beams[active_beam].segments.rbegin()->end_pos;
	ofDrawCircle(marker_pos, 10);
}

void Beam_Bundle::mouseDragged(int x, int y) {
	beams[active_beam].mouseDragged(x, y);
	is_dragging = TRUE;
}

void Beam_Bundle::mouseReleased()
{
	if (beams[active_beam].segments.size() == 1)
	{
		this->beams.emplace_back(beams[active_beam].owner, beams[active_beam].battery);
	}
	beams[active_beam].mouseReleased();

	Segment s = *beams[active_beam].segments.rbegin();
	for (Beam beam : beams) {
		beam.is_crossing(s);
	}
	is_dragging = FALSE;

	//プレイヤー交代
	now_playing++;
}


void Beam_Bundle::next_beam()
{	
	if (is_dragging) {
		return;
	}
	 active_beam+1 < size(beams) ? active_beam++ : active_beam = 0;

}

void Beam_Bundle::previous_beam()
{
	if (is_dragging) {
		return;
	}
	active_beam-1 >= 0 ? active_beam-- : active_beam = size(beams)-1;

}

void Beam_Bundle::erase_beam()
{
	this->beams[active_beam].segments.clear();

}