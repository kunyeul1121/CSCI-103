#include <iostream>
#include <cmath>

using namespace std;

/*

    Written by: Stanley Kim
    Email: stanlejk@usc.edu
    
    Hailstats: Takes a range of numbers and runs the hailstone conjecture 
    on each of those numbers in the range. Then outputs the minimum length, 
    maximum length, and the numbers that achieved those lengths.
*/

int main(){

    int range_min, range_max;
    int min_achieved_by, max_achieved_by;
    int count = 0;
    int i, num;
    int min_length = 10000; //Set initial value to very large number
    int max_length = 0; //Set initial value to very small number
    int temp_min, temp_max;
    
    cout << "Enter the range you want to search: ";
    cin >> range_min >> range_max;
    
    if (range_min > range_max){
  
        cout << "Invalid Range" << endl;
  
    }
    
    else{
    
        for (i = range_min ; i <= range_max; i++){ //Checks all values of range
            
            num = i; //Sets num = i, so i's value won't be affected by math
            
            while (num != 1){ //Same loop from hailstone.cpp
            
                if (num % 2 == 0){
                    num = num / 2;
                    count++;
                }
                
                else if (num % 2 == 1){
                    num = (num * 3) + 1;
                    count++;
                }
            
            }
       
            temp_min = count; //Temporary placeholder for min
            temp_max = count; //Temporary placeholder for max
       
            if (temp_min < min_length){ //Replaces the temporary holder
                min_length = temp_min;
                min_achieved_by = i;
            }
       
            if (temp_max > max_length){ //Replaces the temporary holder
                max_length = temp_max;
                max_achieved_by = i;
            }
       
            count = 0; //Resets the count
       
        }
  
        cout << "Minimum length: " << min_length << endl;
        cout << "Achieved by: " << min_achieved_by << endl;
        cout << "Maximum length: " << max_length << endl;
        cout << "Achieved by: " << max_achieved_by << endl;
    
    }
    
    return 0;
  
}
