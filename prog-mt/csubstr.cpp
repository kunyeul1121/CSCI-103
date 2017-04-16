#include <iostream>
#include <algorithm> 
//********************
// You may NOT add other #includes
// You have to write other desired
//  functionality yourself
//********************
using namespace std;


// Complete the following function
//
// Given the input string, str, this function should return a **new**, 
//  correctly-formatted C-String with size "length" (given by the 
//  input argument) and containing the substring from str[startPos] 
//  to str[startPos+length-1].
//
//  str         is a valid C-string. It should not be altered
//  startPos    starting index/position of the desired substring
//  length      is the desired length of the substring
//
// Return the pointer (start address) of the new array containing
//  the substring. 
//
// ** You may NOT use any library functions in your implementation **
//
// Example 1:  new_csubstr("Hello world", 3, 4) should return "lo w"
// Example 2:  new_csubstr("USC", 0, 2) should return "US"
// Example 3:  csubstr("USC", 1, 10) should return just "SC"
//                  since the length is beyond the end of "USC"
//
//

char* new_csubstr(const char* str, unsigned int pos, unsigned int length)
{
  char new_str[length - 1];

  for(int i = 0; i < length; i++)
  {
    new_str[i] = str[pos + i];
  }
  return new_str;
}


//**************************************
// Do not change these 2 lines and don't
// add any lines between them and main()
//**************************************
#ifndef AUTO_TEST
#define AUTO_TEST
int main(int argc, char* argv[])
{
  char* result;
  result = new_csubstr("Hello world", 3, 4);
  cout << result << endl;
  delete [] result;

  result = new_csubstr("USC", 0, 2);
  cout << result << endl;
  delete [] result;

  //************************************************
  // You may add test calls to your function here.
  //  Though you don't need to.
  //************************************************


  return 0;  
}
//****************************************
// Do not change the following line
//****************************************
#endif

