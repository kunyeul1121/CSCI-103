#include <iostream>
#include <fstream>

using namespace std;

void sort(int *, int);
int binsearch(int, int *, int, int);

int main(int argc, char *argv[]){
  int target;
  if(argc < 2){
    cout << "Provide a filename of the data to be searched" << endl;
    return 1;
  }
  ifstream datfile(argv[1], ios::in);
  if( datfile.fail() ){
    cout << "Unable to open file: " << argv[1] << endl;
    return 1;
  }
  int count = 0;
  // Count how many integers are in the file
  while(! datfile.fail()){
    int temp;
    datfile >> temp;
    if(!datfile.fail()){
      count++;
    }
  }
  // When we reach the end of the file, the EOF flag is set
  // To be able to read through the file again we need to clear that flag
  datfile.clear();
  //  We also need to set our internal position in the file back to 0
  datfile.seekg(0,ios::beg);

  // Now allocate an array to store the file data and read in the data
  int *data = new int[count];
  for(int i=0; i < count; i++){
    datfile >> data[i];
  }

  datfile.close();

  cout << "Read " << count << " integers from the data file.\n" << endl;
  cout << "Enter the target positive integer to search for: ";
  cin >> target;

  // Uncomment the line below for part 2
  sort(data, count);

  // Call binary search
  int retval = binsearch(target,data,0,count);

  // Interpret and print the results
  if(retval == -1){
    cout << target << " does not appear in the data." << endl;
  }
  else {
    cout << target << " appears at index " << retval << " in the data." << endl;
  }

  // Deallocate the data array
  delete [] data;
  return 0;
}


// Returns the index in the data array where target is located
//  or -1 if the target value is not in the list
int binsearch(int target, int *data, int start, int end)
{
	if (data[start] == target)
	{
		return start;
	}
	if (data[end] == target)
	{
		return end;
	}
	if (start >= end || (end - start) < 2)
	{
		return -1;
	}
	int i = ((end - start) / 2) + start;
	if (data[i] == target)
	{
		return i;
	}
	else if(data[i] < target)
	{
		return binsearch(target, data, i + 1, end);
	}
	else if(data[i] > target)
	{
		return binsearch(target, data, start, i);
	}
	else
	{
		return -1;
	}
}


// implements a selection sort algorithm to sort
//  the integer values in the 'data' array of size 'len'
// You aren't allowed to change the prototype of this function
void sort(int *data, int len)
{
	/*
	int min;
	int min_index;
	for (int i = 0; i < len; i++)
	{
		min = data[i];
		min_index = i;

		for(int j = i + 1; j < len; j++)
		{
			if (data[j] < data[min_index])
			{
				min_index = j;
			}
		}
		data[i] = data[min_index];
		data[min_index] = min;
	}
	*/

	int max;
	int index;
	int placeholder;
	int i = len;
	max = data[i];

	for (i = len; i > 0; i--)
	{
		if (data[i] > max)
		{
			index = i;
		}
	}
	data[len] = data[i];
	sort(data, len -1);

}