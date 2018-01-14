#pragma once
#ifndef SEGMENTMETER_H
#define SEGMENTMETER_H
#include "Colors.h"
#include "Location.h"
#include "Graphics.h"
#include <vector>


class SegmentMeter 
{
	//Add one to metersegment (given posx,posy, Color)
	//Remove one meter segment
public:
	SegmentMeter(const int x, const int y, const int gap, const int squaresize)	//place
	{
		this->_loc.x = x;
		this->_loc.y = y;
		this->_segmentgap = gap;
		this->_squaresize = squaresize;
	}
	void Draw(Graphics &gfx)
	{
		int size = this->_meter.size();
		Location dloc;//draw location

		for (int i = 0; i < size; i++)
		{

			dloc = this->_meter[i].getLoc();
			gfx.DrawRect(dloc.x, dloc.y, _squaresize, _squaresize, _c);
		}


	}
	void addone()
	{
		int x = this->_loc.x;
		int y = this->_loc.y;

		int size = this->_meter.size();
		if (size > 0)//calculate x offset
		{
			x = x + size*_squaresize + _segmentgap*size;
		}

		Segment newSeg(x, y, this->_c);
		this->_meter.push_back(newSeg);
	}

private:
	std::vector <Segment> _meter;	//quantity
	int _squaresize = 10;
	int _segmentgap = 1;
	static constexpr Color _c = Colors::Red;
	Location _loc;
};

class Segment
{
public:
	Segment(int x, int y, Color c)
	{
		this->loc.x = x;
		this->loc.y = y;
		this->c = c;
	}
	Location getLoc() { return this->loc; }
private:
	Location loc;
	Color c;


};

#endif