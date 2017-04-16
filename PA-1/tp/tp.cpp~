/*********************************************************
 * File name : tp.cpp
 * Author    : Stanley Kim
 * Date      : 9/19/2016
 * Purpose   : Simulates the toilet-paper problem
 *********************************************************/

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

double rand_uniform();

int single_sim(int N, double p);

int main(int argc, char *argv[])
{
    srand(time(0)); // Seeding time to 0
    
    int N; // Initial number of squares on each roll
    double p; // Probability of a big-chooser
    int sims; // Number of trials for our simulation
    int total = 0; // Total of our simulations added up
    double avg; // Total divided by sims
    
    cout << "Enter values for N, p, and sims: " << endl;
    cin >> N >> p >> sims;
    
    for (int i = sims; i > 0; i--) // Repeats sims times
    {
        total = total + single_sim(N, p); // Total of all remaining rolls
    }
    
    avg = ((double)total / sims); // Divides total by # of simulations
    
    cout << "Average: " << avg << endl;
    
    return 0;
}

int single_sim(int N, double p)
{
    int roll1, roll2;
    roll1 = N; roll2 = N; // Initializes rolls to N
    
    while(roll1 > 0 && roll2 > 0) // Continues until one roll is 0
    {
        double r = rand_uniform(); // Random number btwn [0,1] is generated
    
        if(r > p) // If user is a small-roll chooser
        {
            if(roll2 >= roll1)
            {
                roll1--;
            }
            else if(roll1 > roll2)
            {
                roll2--;
            }
        }
        else if(r <= p) // If user is a big-roll chooser
        {
            if(roll1 >= roll2)
            {
                roll1--;
            }
            else if(roll2 > roll1)
            {
                roll2--;
            }
        }
    }
    return roll1 + roll2; // Returns 0 + value of remaining roll
}

double rand_uniform()
{
    return ((double)rand() / RAND_MAX); // Produces random number [0-1]
}
