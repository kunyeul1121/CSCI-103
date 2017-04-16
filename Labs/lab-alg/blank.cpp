#include <iostream>
#include <cmath>

using namespace std;


int main()
{
    int angle_deg;
    double angle_rad;
    
    cout << "Enter the angle, Θ, in degrees: ";
    cin >> angle_deg;
    
    angle_rad = angle_deg * (M_PI / 180);
    
    for(int y = 0; y < 31; y++)
    {
        for(int x = 0; x < floor(y * tan(angle_rad)) && x < 20; x++)
        {
            if(x < 20 || x > 30)
            {
                cout << "*";
            }
            else if(x <= 30)
            {
                for(int z = 0; z < 20; z++)
                {
                    cout << "*";
                }
            }
        }
        cout << endl;
    }

    return 0;

}
