#include <iostream>
#include <cstdlib>
using namespace std;

/*
    Written by: Stanley Kim
    Email: stanlejk@usc.edu
   
    Diceplot: Takes an integer, n, from the user, and plots out a histogram
    showing the results of n experiments. Each experiment records the sum of 
    4 dice rolls.
*/


int roll();
void printHistogram(int []);

/*
int main()
{
    srand(time(0));
    
    cout << roll() << endl;
    return 0;
}

int main()
{
    srand(time(0));
    
    int testCounts[21];
    for (int i = 0; i < 21; i++)
    {
        testCounts[i] = i / 2;
    }
    printHistogram(testCounts);
    return 0;
}
*/

int main()
{
    srand(time(0));
    
    int n;
    int sum = 0;
    int results[21] = {0};
    
    cout << "Enter a number, n: "; //Prompts user
    cin >> n;
    
    for (int x = n; x > 0; x--) //Runs through the experiments n times
    {
        for (int y = 4; y > 0; y--) //Each exp. rolls 4 dice
        {
        sum = sum + roll(); //Adds each roll to previous sum
        }
        
        results[sum - 4]++; //Records result into array
        
        sum = 0; //Reinitializes sum to 0
    }
    
    printHistogram(results);
    
    return 0;
}

int roll()
{
    int r = (rand() % 6) + 1;
    return r;
}

void printHistogram(int counts[])
{
    for (int i = 0; i < 21; i++)
    {
        cout << i + 4 << ":";
        
        for (int j = counts[i]; j > 0; j--)
        {
            cout << 'X';
        }
        
        cout << endl;
    }
}

