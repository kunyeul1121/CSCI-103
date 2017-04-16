#include "draw.h"

class Turtle
{	
	public:
		Turtle(double x0, double y0, double dir0);

		void move(double dist);

		void turn(double deg);

		void setColor(Color c);

		void on();

		void off();

	private:
		double x_co;
		double y_co;
		double direction;
		Color color;
		int transp;
};