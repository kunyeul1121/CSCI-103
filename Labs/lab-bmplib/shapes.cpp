#include <iostream>
#include <cmath>
#include "bmplib.h"
using namespace std;

// Written by: Stanley Kim
// Email: stanlejk@usc.edu
// Shapes.cpp: Draws rectangles and ellipses

unsigned char image[SIZE][SIZE];

void draw_rectangle(int top, int left, int height, int width)
{
    for (int i = top; i <= top + height; i++) //Controls rows
    {
        if (i >= 0)
        {
            for (int j = left; j <= left + width; j++) //Controls columns
            {
                if (j >= 0)
                {
                    if (i == top || i == top + height) //Top + bottom borders
                    {
                        image[i][j] = 0;
                    }
                    else if (j == left || j == left + width) //Left + right borders
                    {
                        image[i][j] = 0;
                    }
                    else //Hollow inside
                    {
                        image[i][j] = 255;
                    }
                }
            }
        }
    }
}

void draw_ellipse(int cy, int cx, int height, int width)
{
    double rx = width / 2.0;
    double ry = height / 2.0;

    //Runs through every possible angle between [0, 2 * PI]
    for (double angle = 0; angle <= (2 * M_PI); angle += 0.01)
    {
        int r = cy - (int)(ry * sin(angle));
        int c = cx + (int)(rx * cos(angle));
        
        if (r >= 0 && r <= 255 && c <= 255 && c >= 0){
            image[cy - (int)(ry * sin(angle))][cx + (int)(rx * cos(angle))] = 0;
        }
    }
}

int main()
{
    int user_input = 0;
    int x, y, a, b;
    
    for (int i=0; i < SIZE; i++) //Initialize the image to all white pixels
    {
        for (int j=0; j < SIZE; j++)
        {
            image[i][j] = 255;
        }
    }

    cout << "To draw a rectangle, enter: 0 top left height width" << endl;
    cout << "To draw an ellipse, enter: 1 cy cx height width" << endl;
    cout << "To save your drawing as \"output.bmp\" and quit, enter: 2" << endl;


    while (user_input != 2)
    {
        cin >> user_input;
        switch (user_input)
        {
            case 0:
                cin >> x >> y >> a >> b;
                draw_rectangle (x, y, a, b);
                break;
            case 1:
                cin >> x >> y >> a >> b;
                draw_ellipse (x, y, a, b);
                break;
            case 2:
                writeGSBMP("output.bmp", image); //Writes the image to .bmp
                break;
        }
    }
    return 0;
}
