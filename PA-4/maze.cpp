/* 
maze.cpp

Author:

Short description of this file:
*/

#include <iostream>
#include "mazeio.h"
#include "queue.h"

using namespace std;

// Prototype for maze_search, which you will fill in below.
int maze_search(char**, int, int);

// main function to read, solve maze, and print result
int main() {
   int rows, cols, result;
   char** mymaze;
   
   mymaze = read_maze(&rows, &cols); // FILL THIS IN
   
   if (mymaze == NULL) {
      cout << "Error, input format incorrect" << endl;
      return 1;
   }

   // when working on Checkpoint 3, you will call maze_search here.
   // here. but for Checkpoint 1, just assume we found the path.
   result = maze_search(mymaze, rows, cols);

   // examine value returned by maze_search and print appropriate output
   if (result == 1) { // path found!
      print_maze(mymaze, rows, cols);
   }
   else if (result == 0) { // no path :(
      cout << "No path could be found!" << endl;
   }
   else { // result == -1
      cout << "Invalid maze." << endl;
   }

   // ADD CODE HERE to delete all memory 
   // that read_maze allocated
	for (int i = 0; i < rows; i++)
	{
		delete [] mymaze[i];
	}
	delete [] mymaze;

   return 0;
}

/**************************************************
 * Attempt to find shortest path and return:
 *  1 if successful
 *  0 if no path exists
 * -1 if invalid maze (not exactly one S and one F)
 *
 * If path is found fill it in with '*' characters
 *  but don't overwrite the 'S' and 'F' cells
 *************************************************/
int maze_search(char** maze, int rows, int cols) {
    Location start;
    int count_start = 0;
    int count_finish = 0;
	bool path_found = false;

	// Counts how many starts and finishes found
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (maze[i][j] == 'S')
			{
				start.row = i;
				start.col = j;
				count_start++;
			}
    		else if (maze[i][j] == 'F')
    		{
    			count_finish++;
    		}
		}
	}

	// Returns -1 if not exactly one start and one finish
    if (count_start != 1 || count_finish != 1)
    {
    	return -1;
    }

    // Create a queue q and add start to the back
	Queue q(rows * cols);
	q.add_to_back(start);

	// Dyn. Alloc 2D array: visited
	int ** visited;
	visited = new int* [rows];

	for (int i = 0; i < rows; i++)
	{
		visited[i] = new int[cols];
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			visited[i][j] = 0;
		}
	}

    visited[start.row][start.col] = 1;

	Location start_pred;
	start_pred.row = -1;
	start_pred.col = -1;

	Location ** predecessor;
	predecessor = new Location* [rows];

	for (int i = 0; i < rows; i++)
	{
		predecessor[i] = new Location[cols];
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			predecessor[i][j] = start_pred;
		}
	}

	while(!q.is_empty())
	{
		Location curr = q.remove_from_front();

		Location one_above;
		one_above.row = curr.row - 1;
		one_above.col = curr.col;
		if(one_above.row >= 0 && one_above.row < rows &&
			one_above.col >= 0 && one_above.col < cols)
		{
			if (maze[one_above.row][one_above.col] == 'F')
			{
				while(maze[curr.row][curr.col] != 'S')
				{
					maze[curr.row][curr.col] = '*';
					curr = predecessor[curr.row][curr.col];
				}
				path_found = true;
				break;
			}

			else if (maze[one_above.row][one_above.col] == '.' &&
				visited[one_above.row][one_above.col] == 0)
			{
				visited[one_above.row][one_above.col] = 1;
				predecessor[one_above.row][one_above.col] = curr;
				q.add_to_back(one_above);
			}
		}

		Location one_left;
		one_left.row = curr.row;
		one_left.col = curr.col - 1;
		if(one_left.row >= 0 && one_left.row < rows &&
			one_left.col >= 0 && one_left.col < cols)
		{
			if (maze[one_left.row][one_left.col] == 'F')
			{
				while(maze[curr.row][curr.col] != 'S')
				{
					maze[curr.row][curr.col] = '*';
					curr = predecessor[curr.row][curr.col];
				}
				path_found = true;
				break;
			}

			else if (maze[one_left.row][one_left.col] == '.' &&
				visited[one_left.row][one_left.col] == 0)
			{
				visited[one_left.row][one_left.col] = 1;
				predecessor[one_left.row][one_left.col] = curr;
				q.add_to_back(one_left);
			}
		}

		Location one_below;
		one_below.row = curr.row + 1;
		one_below.col = curr.col;
		if(one_below.row >= 0 && one_below.row < rows &&
			one_below.col >= 0 && one_below.col < cols)
		{
			if (maze[one_below.row][one_below.col] == 'F')
			{
				while(maze[curr.row][curr.col] != 'S')
				{
					maze[curr.row][curr.col] = '*';
					curr = predecessor[curr.row][curr.col];
				}
				path_found = true;
				break;
			}

			else if (maze[one_below.row][one_below.col] == '.' &&
				visited[one_below.row][one_below.col] == 0)
			{
				visited[one_below.row][one_below.col] = 1;
				predecessor[one_below.row][one_below.col] = curr;
				q.add_to_back(one_below);
			}
		}

		Location one_right;
		one_right.row = curr.row;
		one_right.col = curr.col + 1;
		if(one_right.row >= 0 && one_right.row < rows &&
			one_right.col >= 0 && one_right.col < cols)
		{
			if (maze[one_right.row][one_right.col] == 'F')
			{
				while(maze[curr.row][curr.col] != 'S')
				{
					maze[curr.row][curr.col] = '*';
					curr = predecessor[curr.row][curr.col];
				}
				path_found = true;
				break;
			}

			else if(maze[one_right.row][one_right.col] == '.' &&
				visited[one_right.row][one_right.col] == 0)
			{
				visited[one_right.row][one_right.col] = 1;
				predecessor[one_right.row][one_right.col] = curr;
				q.add_to_back(one_right);
			}
		}
	}

	for (int i = 0; i < rows; i++)
	{
		delete [] predecessor[i];
		delete [] visited[i];
	}
	delete [] predecessor;
	delete [] visited;

	if (path_found == true)
	{
		return 1;
	}

	else
	{
		return 0;
	}
}
