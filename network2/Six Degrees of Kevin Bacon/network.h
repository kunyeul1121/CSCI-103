#ifndef NETWORK_H
#define NETWORK_H
#include <string>
#include "user.h"

using std::vector;

class Network {
	public:

		Network();

		~Network();

		int read_friends(const char *filename);

		int write_friends(const char *filename);

		void add_user(std::string username, int yr, int zipcode,
			vector <int> friend_list);

		int add_connection(std::string name1, std::string name2);

		int remove_connection(std::string name1, std::string name2);

		int get_id(std::string username);

		int get_size();

		User get_user(int index);

		vector<int> shortest_path(int from, int to);

		vector< vector<int> > groups();

		vector<int> suggest_friends(int who, int& score);

		vector<int> bfs(int id);

		void reinit_depth();

	private:
		vector<User> network;

};


#endif
