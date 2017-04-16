#include "turtle.h"
#include <iostream>
#include <cmath>

using namespace std;

Turtle::Turtle(double x0, double y0, double dir0)
{
	x_co = x0;
	y_co = y0;
	direction = dir0;
	color = draw::BLACK;
	transp = 0;
}

void Turtle::move(double dist)
{
	double x2 = x_co + (dist * cos(direction * (M_PI / 180)));
	double y2 = y_co + (dist * sin(direction * (M_PI / 180)));
	draw::setcolor(color);
	draw::settransparency(transp);
	draw::line(x_co, y_co, x2, y2);

	x_co = x2;
	y_co = y2;
}

void Turtle::turn(double deg)
{
	direction = direction + deg;
}

void Turtle::setColor(Color c)
{
	color = c;
}

void Turtle::on()
{
	transp = 0;
}

void Turtle::off()
{
	transp = 1;
}