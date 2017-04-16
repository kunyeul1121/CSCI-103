#include <string>
#include <vector>
#include <iostream>

using namespace std;

#ifndef USER_H
#define USER_H

class User
{
	public:
		User(int num, string user, int b_year, int zip_code,
			vector <int> friends_list);

		~User();

		void add_friend(int num);

		void delete_friend(int num);

		string get_name();

		int get_id();

		int get_year();

		int get_zip();

		int get_depth();

		int get_pred();

		vector <int>* get_friends();

		void set_depth(int num);

		void set_pred(int num);

	private:
		int id;
		string name;
		int year;
		int zip;
		vector<int> friends;		
		int depth, predecessor;
};


#endif
