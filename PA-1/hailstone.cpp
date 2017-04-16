#include <iostream>
#include <cmath>

using namespace std;

/*
  Written by: Stanley Kim
  Email: stanlejk@usc.edu
  
  Hailstone.cpp: Takes an integer from the user and follows the hailstone
  conjecture until the integer is 1. Then outputs the length of the process.
*/

int main(){

  int num;
  int count = 0;
  cout << "Enter an integer: ";
  cin >> num;
  
  while(num != 1){ //Loop will reiterate until number == 1

    if(num % 2 == 0){ //If number is even, number/2
    
    num = num / 2;
    count++;
    cout << num << " ";
    
    }

    else if(num % 2 == 1){ //If number is odd, (number*3) + 1
    
    num = (num * 3) + 1;
    count++;
    cout << num << " ";
    
    }

  }
  
  cout << endl;
  cout << "Length: " << count << endl;
  
  return 0;

}
