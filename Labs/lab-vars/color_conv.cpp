#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
   // Declaring all necessary variables
   int red, green, blue;
   double white;
   double temp;
   double cyan, magenta, yellow, black;
   
   cout << "Enter the values for red, green, and blue: ";
   cin >> red >> green >> blue;
 
   temp = max((red/255.0), (green/255.0)); //Finding max of red/green
   white = max(temp, (blue/255.0)); //Comparing red/green to blue
   
   //Computing values for C,M,Y,K
   cyan = (white - red / 255.0) / white;
   magenta = (white - green / 255.0) / white;
   yellow = (white - blue / 255.0) / white;
   black = 1.0 - white;
   
   cout << "cyan: " << cyan << endl;
   cout << "magenta: " << magenta << endl;
   cout << "yellow: " << yellow << endl;
   cout << "black: " << black << endl;
   
   return 0;
}
