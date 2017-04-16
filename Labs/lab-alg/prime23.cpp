#include <iostream>
#include <cmath>

using namespace std;

/*
    Written by: Stanley Kim
    Email: stanlejk@usc.edu
    
    Lab 3: Prime23, checks to see if the number input has only 2 and
    or 3 as prime factors, and outputs how many of each factor it has
*/

int main(){

    int num;
    int count_2 = 0;
    int count_3 = 0;
    
    cout << "Enter a positive integer: ";
    cin >> num;
    
    while (num > 1)
    {
        if (num % 2 == 0)
        {
            num = num / 2;
            count_2++;
        }
        else if (num % 3 == 0)
        {
            num = num / 3;
            count_3++;
        }
        else if (num % 2 != 0 && num % 3 != 0)
        {
            cout << "No" << endl;
            break;
        }
    }
    
    if (num == 1)
    {
        cout << "Yes" << endl;
        cout << "Twos=" << count_2 << " ";
        cout << "Threes= " << count_3 << endl;
    }

    return 0;

}
