#include <iostream>
#include <cmath>

using namespace std;


int main()
{
	int angle_deg;
	int x, y;
	double angle_rad, base;

	cout << "Enter the angle, Θ, in degrees: ";
	cin >> angle_deg;

	angle_rad = angle_deg * (M_PI / 180);

	for (y = 0; y < 31; y++)
	{
		base = floor(y * tan(angle_rad));

		for (x = 0; x < base; x++)
		{
			if (base >= 20 && base <= 30)
			{
				for (int a = 0; a < 20; a++)
				{
					cout << "*";
				}
				break;
			}
			else
			{
				cout << "*";
			}
		}
		cout << endl;
	}
	
	cout << x << " " << y;
	system("pause");
	return 0;
}
