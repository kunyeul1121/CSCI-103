#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <fstream>

using namespace std;

void permute(char items[], int len);

int main(int argc, char* argv[])
{
    srand(time(0));
    char guess[80];
    char buffer[41];

    if (argc < 2)
    {
        cout << "Please enter the file name of the wordbank." << endl;
        return 1;
    }

    ifstream in_file(argv[1]);

    if (!in_file.is_open())
    {
        cout << "File could not be opened. :(" << endl;
        return 1;
    }

    int numWords;

    in_file >> numWords;

    if (in_file.fail())
    {
        cout << "Integer could not be read. :(" << endl;
        return 1;
    }

    char** wordBank = new char* [numWords];
    
    int i = 0;
    while (in_file >> buffer)
    {
        int length = strlen(buffer);
        wordBank[i] = new char [length + 1];
        strncpy(wordBank[i], buffer, length + 1);
        i++;
    }

    bool wordGuessed = false;
    int numTurns = 10;

    int target = rand() % numWords;
    int targetLen = strlen(wordBank[target]);

    char* word = new char[targetLen+1];
    strcpy(word, wordBank[target]);
    permute(word, targetLen);

    while (!wordGuessed && numTurns > 0)
    {
        cout << "Scrambled word: " << word << endl;
        cout << "What do you guess the original word is? ";
        cin >> guess;
        wordGuessed = (strcmp(guess, wordBank[target]) == 0);
        numTurns--;
    }
        if (wordGuessed) {
        cout << "You win!" << endl;
    }
    else
    {
        cout << "Too many turns...You lose!" << endl;
    }
    delete [] word;

    for (i = 0; i < numWords; i++)
    {
        delete [] wordBank[i];
    }
    delete [] wordBank;
    return 0;
}

void permute(char items[], int len)
{
    for (int i = len-1; i > 0; --i)
    {
        int r = rand() % i;
        char temp = items[i];
        items[i] = items[r];
        items[r] = temp;
    }
}

