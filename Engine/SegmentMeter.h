#pragma once
#ifndef SEGMENTMETER_H
#define SEGMENTMETER_H
#include "Colors.h"
#include "Location.h"
#include <vector>


class SegmentMeter 
{

public:
	SegmentMeter(const int x, const int y)
	{
		this->loc.x = x;
		this->loc.y = y;
	}
	std::vector <Segment> _meter;

private:
	
	Location loc;
};

class Segment
{
public:
	Segment(int x, int y)
	{
		this->loc.x = x;
		this->loc.y = y;
	}
private:
	static constexpr int size = 10;
	Location loc;
	Color c;
};

#endif