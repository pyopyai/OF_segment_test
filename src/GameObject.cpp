#include "GameObject.h"

Segment::Segment()
{

}

Segment::Segment(ofVec2f start, ofVec2f end)
{
	this->start_pos.set(start);
	this->end_pos.set(end);
}

int Segment::squared_length()
{
	return start_pos.distanceSquared(end_pos);
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
	long  ta = (x3 - x4)*(y1 - y3) + (y3 - y4)*(x3 - x1);
	long  tb = (x3 - x4)*(y2 - y3) + (y3 - y4)*(x3 - x2);
	long  tc = (x1 - x2)*(y3 - y1) + (y1 - y2)*(x1 - x3);
	long  td = (x1 - x2)*(y4 - y1) + (y1 - y2)*(x1 - x4);
	printf("%d\t%d\t%d\t%d\n%d\t%d\t%d\t%d\n", x1, y1, x2, y2, x3, y3, x4, y4);
	//そのままta*tbすると値が大きくなりすぎるため
	ta = ta > 0 ? 1 : -1;
	tb = tb > 0 ? 1 : -1;
	tc = tc > 0 ? 1 : -1;
	td = td > 0 ? 1 : -1;


	bool is_cross = ta * tb < 0 && tc * td < 0;
	printf("%d\n", is_cross);
	return is_cross;
}

Beam::Beam(int owner,int battery)
{
	this->owner = owner;
	this->battery = battery;

	ofVec2f start;

	//4砲台の位置関係
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
	// 末尾線分の色を灰色から変更
	auto last_segment = this->segments.rbegin();
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


}

void Beam::draw() 
{
	for (Segment segment : this->segments)
	{
		segment.draw();
	}
}

void Beam::mouseDragged(int x, int y,bool is_dragging) {
	ofVec2f mouse_pos(x, y);
	auto last_segment = this->segments.rbegin();


	//ドラッグ中のビームがなければ作る、あれば座標を更新
	if (is_dragging) {
		last_segment->end_pos = mouse_pos;
	}
	else {
		this->segments.emplace_back(last_segment->end_pos, mouse_pos);
		last_segment = this->segments.rbegin();
		last_segment->color = ofColor(50, 50, 50);
	}
	while (last_segment->squared_length() > 250*250)
	{
		last_segment->end_pos = 0.99*(last_segment->end_pos - last_segment->start_pos) + last_segment->start_pos;
	}
}

bool Beam::is_crossing(Segment s,bool is_cutting) {
	for (auto iter = segments.begin(); iter != segments.end(); ++iter)
	{
		if (iter->is_crossing(s)) {
			if (is_cutting)
			{
				segments.erase(iter + 1, segments.end());

				//既存のビームを交差地点まで縮める
				float r = 1.00;
				Segment copyed_segment = *iter;
				ofVec2f old_end_pos;
				do
				{
					old_end_pos = copyed_segment.end_pos;
					r -= 0.01;
					copyed_segment.end_pos = r * (iter->end_pos - iter->start_pos) + iter->start_pos;
				} while (copyed_segment.is_crossing(s) && r > 0);

				iter->end_pos = copyed_segment.end_pos;
				this->extended_end_pos = old_end_pos;

				//segments.clear();
				printf("clear%d\n", this->segments.size());
			}

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
	//4砲台のビームを作っておく
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
	beams[active_beam].mouseDragged(x, y,is_dragging);
	is_dragging = TRUE;
}

void Beam_Bundle::mouseReleased()
{
	//砲台から直接ビームを伸ばした場合、砲台に新たなビームを補充する
	if (beams[active_beam].segments.size() == 2)
	{
		this->beams.emplace_back(beams[active_beam].owner, beams[active_beam].battery);
	}

	beams[active_beam].mouseReleased();

	//交差判定
	Segment s = *(beams[active_beam].segments.rbegin());
	for (auto &beam : beams) {
		if (&beam == &beams[active_beam]) {
			continue;
		}
		Beam* beamptr = &beam;
		beamptr->is_crossing(s,true);
	}


	is_dragging = FALSE;

	//プレイヤー交代
	now_playing++;
	Beam_Bundle::next_beam();
}

//伸ばすビームを選択
void Beam_Bundle::next_beam()
{	
	if (is_dragging) return;

	 active_beam+1 < size(beams) ? active_beam++ : active_beam = 0;

	//自分のビームか判定
	 if (now_playing % 2 != beams[active_beam].owner) Beam_Bundle::next_beam();

	//現在先端が止められているか否かを判定
	bool f_crossing = false;
	if (beams[active_beam].extended_end_pos != ofVec2f(-100,-100)) {
		Segment s(beams[active_beam].segments.rbegin()->end_pos, beams[active_beam].extended_end_pos);
		for (auto &beam : beams) {
			if (&beam == &beams[active_beam]) {
				continue;
			}
			Beam* beamptr = &beam;
			if (beamptr->is_crossing(s, false))
			{
				f_crossing = true;
				break;
			}
		}
	}
	if (f_crossing) Beam_Bundle::next_beam();
	
}

void Beam_Bundle::previous_beam()
{
	if (is_dragging) return;

	active_beam-1 >= 0 ? active_beam-- : active_beam = size(beams)-1;

	//自分のビームか判定
	if (now_playing % 2 != beams[active_beam].owner) Beam_Bundle::previous_beam();

	//現在先端が止められているか否かを判定
	bool f_crossing = false;
	if (beams[active_beam].extended_end_pos != ofVec2f(-100, -100)) {
		Segment s(beams[active_beam].segments.rbegin()->end_pos, beams[active_beam].extended_end_pos);
		for (auto &beam : beams) {
			if (&beam == &beams[active_beam]) {
				continue;
			}
			Beam* beamptr = &beam;
			if (beamptr->is_crossing(s, false))
			{
				f_crossing = true;
				break;
			}
		}
	}
	if (f_crossing) Beam_Bundle::previous_beam();
}

void Beam_Bundle::erase_beam()
{
	this->beams[active_beam].segments.clear();

}