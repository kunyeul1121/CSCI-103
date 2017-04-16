#include <iostream>
#include <fstream>
#include <sstream>
#include "network.h"

using namespace std;

	Network::Network()
	{

	}

	Network::~Network()
	{

	}

	int Network::read_friends(const char *file)
	{
		ifstream in_file(file);

		if(!in_file.is_open())
		{
			return -1;
		}

		else
		{
			int n;
			int id, year, zip;
			string first, last, name;
			

			string friends_string;

			in_file >> n;

			for(int i = 0; i < n; i++)
			{
				vector<int> friend_list;

				in_file >> id >> first >> last >> year >> zip;

				in_file.ignore();
				getline(in_file, friends_string);
				stringstream ss(friends_string);

				int x;

				while(ss >> x)
				{
					friend_list.push_back(x);
				}

				name = first + " " + last;

				add_user(name, year, zip, friend_list);
			}

			in_file.close();

			return 0;
		}
	}

	int Network::write_friends(const char *file)
	{
		ofstream out_file(file);

		if(!out_file.is_open())
		{
			return -1;
		}

		else
		{
			out_file << network.size() << endl;

			for(int i = 0; i < network.size(); i++)
			{
				out_file << i << endl;
				out_file << '\t' << network[i].get_name() << endl;
				out_file << '\t' << network[i].get_year() << endl;
				out_file << '\t' << network[i].get_zip() << endl;
				out_file << '\t';

				vector <int>* temp_friends_list = network[i].get_friends();

				for(int j = 0; j < temp_friends_list->size(); j++)
				{
					int k = (*temp_friends_list)[j];
					out_file << k << " ";
				}
				out_file << endl;
			}
			return 0;
		}
	}

	void Network::add_user(string username, int yr, int zipcode, 
		vector <int> friend_list)
	{
		network.push_back(User(network.size(), username, yr, zipcode,
			friend_list));
	}

	int Network::add_connection(string name1, string name2)
	{

		int id1, id2;

		id1 = get_id(name1);
		id2 = get_id(name2);

		if(id1 == -1 || id2 == -1)
		{
			return -1;
		}

		for(int i = 0; i < network[id1].get_friends()->size(); i++)
		{
			vector <int>* temp = network[id1].get_friends();

			if((*temp)[i] == id2)
			{
				return -2;
			}
		}

		network[id1].add_friend(id2);
		network[id2].add_friend(id1);

		return 0;
	}

	int Network::remove_connection(string name1, string name2)
	{

		int id1, id2;

		id1 = get_id(name1);
		id2 = get_id(name2);

		if(id1 == -1 || id2 == -1)
		{
			cout << "User was not found!" << endl;
			return -1;
		}

		else if(network[id1].get_name() == name1 && network[id2].get_name()
			== name2)
		{
			network[id1].delete_friend(id2);
			network[id2].delete_friend(id1);
			return 0;
		}

		else
		{
			cout << "Failed to remove connection!" << endl;
			return -1;
		}
	}

	int Network::get_id(string name)
	{
		for(int i = 0; i < network.size(); i++)
		{
			if(network[i].get_name() == name)
			{
				return i;
			}
		}
		return -1;
	}

	int Network::get_size()
	{
		return network.size();
	}

	User Network::get_user(int index)
	{
		return network[index];
	}

	vector<int> Network::shortest_path(int from, int to)
	{
		vector<int> path;
		bfs(from);
		if(network[to].get_depth() == -1)
		{
			return path;
		}
		else
		{
			int x = to;

			if(network[to].get_pred() == to)
			{
				path.push_back(to);
				return path;
			}

			else
			{
				path.push_back(x);

				while(network[x].get_pred() != from)
				{
					int p = network[x].get_pred();

					path.push_back(p);

					x = p;
				}

				return path;
			}
		}
	}

	vector< vector<int> > Network::groups()
	{
		vector< vector<int> > groups;

		for(int i = 0; i < network.size(); i++)
		{
			if(network[i].get_depth() == -1)
			{
				groups.push_back(bfs(i));
			}
		}
		return groups;
	}

	vector<int> Network::suggest_friends(int who, int& score)
	{
		bfs(who);

		vector <int> friends_2;

		for(int i = 0; i < network.size(); i++)
		{
			if(network[i].get_depth() == 2)
			{
				friends_2.push_back(i);
			}
		}

		vector <int> counts;

		
		int max = 0;

		for(int k = 0; k < friends_2.size(); k++)
		{
			int count = 0;
			for(int i = 0; i < network[who].get_friends()->size(); i++)
			{
				vector <int> temp_friends_2 = *(network[friends_2[k]].get_friends());
				vector <int> temp_friends_1 = *(network[who].get_friends());

				for(int j = 0; j < network[friends_2[k]].get_friends()->size(); j++)
				{
					if(temp_friends_1[i] == temp_friends_2[j])
					{
						count++;
					}
					if(count > max)
					{
						max = count;
					}
				}
			}
			counts.push_back(count);
		}

		vector <int> suggested_friends;

		for(int i = 0; i < counts.size(); i++)
		{
			if(counts[i] == max)
			{
				suggested_friends.push_back(friends_2[i]);
			}
		}

		score = max;

		return suggested_friends;
	}


	vector<int> Network::bfs(int id)
	{
		vector<int> q;

		vector<int> visited;

		q.push_back(id);

		visited.push_back(id);

		network[id].set_depth(0);

		while(!q.empty())
		{
			int x = q.front();
			q.erase(q.begin());

			vector <int>* temp_friends = network[x].get_friends();

			for(int i = 0; i < temp_friends->size(); i++)
			{
				int friend_id = (*temp_friends)[i];

				if(network[friend_id].get_depth() == -1)
				{
					q.push_back(friend_id);
					visited.push_back(friend_id);
					network[friend_id].set_pred(x);
					network[friend_id].set_depth(network[x].get_depth() + 1);
				}
			}
		}

		return visited;
	}

	void Network::reinit_depth()
	{
		for(int i = 0; i < network.size(); i++)
		{
			network[i].set_depth(-1);
		}
	}