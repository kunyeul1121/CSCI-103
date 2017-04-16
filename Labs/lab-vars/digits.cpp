#include <iostream>

using namespace std;

int main(){

   int x;
   int one_digit, ten_digit, hundred_digit;
   
   cout << "Enter an integer from 0 to 999: ";
   cin >> x;
   
   hundred_digit = x / 100;
   ten_digit = (x - (hundred_digit * 100)) / 10;
   one_digit = x - (hundred_digit * 100) - (ten_digit * 10);
   
   cout << "1's digit is: " << one_digit << endl;
   cout << "10's digit is: " << ten_digit << endl;
   cout << "100's digit is: " << hundred_digit << endl;


   return 0;
}
