#include "network.h"
#include "user.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <cstring>
#include <iomanip>

using namespace std;

int main(int argc, char *argv[])
{
	Network facebook;

	ifstream in_file(argv[1]);

	if(in_file.fail())
	{
		cout << "Error reading file!" << endl;
		return -1;
	}

	facebook.read_friends(argv[1]);

	string response;

	bool valid_response = true;

	while(valid_response)
	{
		cout << endl;
		cout << "Welcome to facebook! Select an option below." << endl;
		cout << "1) Add a user." << endl;
		cout << "2) Add a friend connection." << endl;
		cout << "3) Remove a friend connection." << endl;
		cout << "4) Print users." << endl;
		cout << "5) List friends." << endl;
		cout << "6) Write to file." << endl;
		cout << "7) Shortest path between two people." << endl;
		cout << "8) Print disjoint sets." << endl;
		cout << "9) Show suggested friends." << endl;
		cout << "Enter any other key to exit." << endl;

		cin >> response;

		if(response[0] == '1')
		{
			string line;
			int year, zip;
			string first, last;
			string name;
			vector <int> friends;

			getline(cin, line);
			stringstream ss(line);

			ss >> first >> last >> year >> zip;

			name = first + " " + last;

			facebook.add_user(name, year, zip, friends);
			cout << endl;
			response = "";
			ss.str("");
		}
		else if(response[0] == '2')
		{
			string line;
			string first1, last1, first2, last2;
			string name1, name2;
			int id1, id2;
			getline(cin, line);

			stringstream ss(line);

			ss >> first1 >> last1 >> first2 >> last2;

			name1 = first1 + " " + last1;
			name2 = first2 + " " + last2;

			id1 = facebook.get_id(name1);
			id2 = facebook.get_id(name2);

			if(id1 == -1 || id2 == -1)
			{
				cout << "Error occurred!" << endl;
			}

			if(facebook.add_connection(name1, name2) == -2)
			{
				cout << "Connection already exists!" << endl;
			}
			cout << endl;
			response = "";
			ss.str("");
		}
		else if(response[0] == '3')
		{
			int n;
			string line;
			string first1, last1, first2, last2;
			string name1, name2;

			getline(cin, line);
			stringstream ss(line);

			ss >> first1 >> last1 >> first2 >> last2;

			name1 = first1 + " " + last1;
			name2 = first2 + " " + last2;

			n = facebook.remove_connection(name1, name2);

			if(n == -1)
			{
				cout << "Error occurred!" << endl;
			}
			cout << endl;
			response = "";
			ss.str("");
		}
		else if(response == "4")
		{
			if(facebook.get_size() < 1)
			{
				cout << "No users added!" << endl;
			}

			else
			{
				cout << setw(8) << left << "ID";
				cout << setw(16) << left << "Name";
				cout << setw(8) << left << "Year";
				cout << setw(28) << left << "Zip" << endl;
				cout << "====================================================";
				cout << endl;

				for(int i = 0; i < facebook.get_size(); i++)
				{
					User buffer = facebook.get_user(i);

					cout << left << i;
					cout << setw(7) << left << ".";
					cout << setw(16) << left << buffer.get_name();
					cout << setw(8) << left << buffer.get_year();
					cout << setw(28) << left << buffer.get_zip() << endl;
				}
			}
			cout << endl;
		}
		else if(response[0] == '5')
		{
			string first, last, name;
			string line;

			getline(cin, line);
			stringstream ss(line);

			ss >> first >> last;

			name = first + " " + last;

			if(facebook.get_size() < 1)
			{
				cout << "No users added!" << endl;
			}
			else if(facebook.get_id(name) == -1)
			{
				cout << "Invalid user name!" << endl;
			}
			else
			{
				cout << setw(8) << left << "ID";
				cout << setw(16) << left << "Name";
				cout << setw(8) << left << "Year";
				cout << setw(28) << left << "Zip" << endl;
				cout << "====================================================";
				cout << endl;

				int id = facebook.get_id(name);
				User user = facebook.get_user(id);
				vector <int> friends_list = *(user.get_friends());

				for(int i = 0; i < friends_list.size(); i++)
				{
					int friend_id = friends_list[i];

					cout << left << friend_id;
					cout << setw(7) << left << ".";
					cout << setw(16) << facebook.get_user(friend_id).get_name();
					cout << setw(8) << facebook.get_user(friend_id).get_year();
					cout << setw(28) << facebook.get_user(friend_id).get_zip() << endl;
				}
			}
			cout << endl;
			response = "";
			ss.str("");
		}
		else if(response[0] == '6')
		{
			string file;

			getline(cin, file);
			stringstream ss(file);

			ss >> file;

			char* file_c = new char[file.length() + 1];
			strcpy(file_c, file.c_str());

			int n = facebook.write_friends(file_c);

			if(n == -1)
			{
				cout << "ERROR: Could not open file!" << endl;
			}

			delete [] file_c;
			response = "";
			ss.str("");
			cout << endl;
		}

		else if(response[0] == '7')
		{
			string first1, first2, last1, last2;
			string name1, name2;
			string line;
			int id1, id2;

			getline(cin, line);
			stringstream ss(line);

			ss >> first1 >> last1 >> first2 >> last2;

			name1 = first1 + " " + last1;
			name2 = first2 + " " + last2;

			id1 = facebook.get_id(name1);
			id2 = facebook.get_id(name2);

			if(facebook.shortest_path(id1, id2).empty())
			{
				cout << "None" << endl;
			}
			else if(name1 == name2)
			{
				cout << "Distance: 0" << endl;
				cout << name1 << endl;
			}
			else
			{
				vector <int> path = facebook.shortest_path(id1, id2);

				cout << "Distance: " << path.size() << endl;
				cout << name1 << " ->";

				while(!path.empty())
				{
					int x = path.back();
					cout << " " << facebook.get_user(x).get_name() << " ";

					if(path.size() != 1)
					{
						cout << "->";
					}
					path.pop_back();
				}
				cout << endl;
			}

			for(int i = 0; i < facebook.get_size(); i++)
			{
				facebook.get_user(i).set_depth(-1);
			}

		}

		else if(response[0] == '8')
		{
			vector< vector<int> > groups = facebook.groups();
			for(int i = 0; i < groups.size(); i++)
			{
				cout << "Set " << i + 1 << " = > ";
				for(int j = 0; j < groups[i].size(); j++)
				{
					cout << facebook.get_user(groups[i][j]).get_name();

					if(j != groups[i].size() - 1)
					{
						cout << ", ";
					}
				}
				cout << endl;
			}
			facebook.reinit_depth();
		}

		else if(response[0] == '9')
		{
			string first, last, name;
			string line;
			int score;

			getline(cin, line);
			stringstream ss(line);

			ss >> first >> last;

			name = first + " " + last;

			int who = facebook.get_id(name);

			vector<int> suggestion = facebook.suggest_friends(who, score);

			if(suggestion.size() < 1)
			{
				cout << "None" << endl << endl;
			}
			
			else
			{
				for(int i = 0; i < suggestion.size(); i++)
				{
					cout << left << setw(15) << facebook.get_user(suggestion[i]).get_name();
					cout << "Score:" << score << endl;
				}
			}

		}

		else
		{
			cout << "Exiting program." << endl << endl;
			valid_response = false;
		}
		response = "";
	}

	if(valid_response == false)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}
