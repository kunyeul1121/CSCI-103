#include <string>
#include <vector>

// importing a whole namespace in a header is frowned upon
// this will at least let us write 'string'/'vector' below
using std::string;
using std::vector;

class BigInt {
    public:
		BigInt(string s);   // convert string to BigInt
		string to_string(); // get string representation
		void add(BigInt b); // add another BigInt to this one
    private:
      	vector<int> number;
     	int digit;
     	int length;
     	int size;
		string string_number;
		int sum, carry_on;
};
