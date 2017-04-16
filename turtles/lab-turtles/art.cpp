#include "turtle.h"
#include "draw.h"

int main() {
   draw::show(750);
   draw::setpenwidth(6);
   draw::setrange(-100, 100);

   Turtle squirt(-50, 50, 30);
   Turtle squirtle(49, -38, -150);
   Turtle wartortle(-50, 50, -90);
   Turtle blastoise(0, 50, -90);

   squirt.setColor(draw::BLUE);
   squirt.move(58);
   squirtle.setColor(draw::GREEN);
   squirtle.move(58);
   wartortle.setColor(draw::RED);
   wartortle.move(30);
   blastoise.setColor(draw::ORANGE);
   blastoise.move(30);

   draw::show(750);

   squirt.turn(-60);
   squirt.move(58);

   draw::show(750);

   squirt.turn(-60);
   squirt.move(30);

   draw::show(750);

   squirt.turn(-60);
   squirt.move(29);

   draw::show(750);

   squirtle.turn(-60);
   squirtle.move(58);

   draw::show(750);

   squirtle.turn(-60);
   squirtle.move(30);

   draw::show(750);

   squirtle.turn(-60);
   squirtle.move(29);

   draw::show(750);

   wartortle.turn(60);
   wartortle.move(57);

   draw::show(750);

   wartortle.turn(-60);
   wartortle.move(30);

   draw::show(750);

   blastoise.turn(60);
   blastoise.move(57);

   draw::show(750);

   blastoise.turn(-60);
   blastoise.move(30);

   draw::show(750);

   	for (int i = 0; i < 5; i++)
   	{
   		blastoise.turn(i*5);
   		blastoise.move(i*3);
   		draw::show(750);
    }



   return 0;
}