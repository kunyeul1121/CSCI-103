#include "user.h"

	User::User(int num, string user, int b_year, int zip_code,
		vector <int> friends_list)
	{
		id = num;
		name = user;
		year = b_year;
		zip = zip_code;
		friends = friends_list;
		depth = -1;
		predecessor = -1;
	}

	User::~User()
	{

	}

	void User::add_friend(int num)
	{
		bool existing_friend = false;

		for(int i = 0; i < friends.size(); i++)
		{
			if(friends[i] == num)
			{
				existing_friend = true;
				break;
			}
		}
		if(!existing_friend)
		{
			friends.push_back(num);
		}
	}

	void User::delete_friend(int num)
	{
		for(int i = 0; i < friends.size(); i++)
		{
			if(friends[i] == num)
			{
				if(i == friends.size() - 1)
				{
					friends.pop_back();
				}

				else
				{
					friends.erase(friends.begin() + i);
				}
				break;
			}
		}
	}

	string User::get_name()
	{
		return name;
	}

	int User::get_id()
	{
		return id;
	}

	int User::get_year()
	{
		return year;
	}

	int User::get_zip()
	{
		return zip;
	}

	int User::get_depth()
	{
		return depth;
	}

	int User::get_pred()
	{
		return predecessor;
	}

	vector <int>* User::get_friends()
	{
		return &friends;
	}

	void User::set_depth(int num)
	{
		depth = num;
	}

	void User::set_pred(int num)
	{
		predecessor = num;
	}