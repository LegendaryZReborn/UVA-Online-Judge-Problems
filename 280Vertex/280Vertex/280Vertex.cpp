//280Vertex
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <bitset>

using namespace std;
#define endl '\n'

void breadthFirstS(vector<vector<int>>&, bitset<102>&, bitset<102>&, int start);
void breadthFirstSearch(vector<vector<int>> & graph, bitset<102>& visited, bitset<102>& visitedR, int startIndex); 
int startIndexS(vector<vector<int>> & graph, int start);



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	vector<vector<int>> adjList;
	vector<int> vList;
	int numVertices, vertex, start, inCount;
	int search;
	bitset<102> visited, visitedReal;


	//read all of graph definition
	cin >> numVertices;
	while (numVertices != 0)
	{
		cin >> vertex;
		while (vertex != 0)
		{
			vList.push_back(vertex);
			cin >> vertex;
			while (vertex != 0)
			{
				vList.push_back(vertex);

				cin >> vertex;
			}

			if (!vList.empty())
			{
				adjList.push_back(vList);
				vList.clear();
			}
			cin >> vertex;
		}

		
		cin >> search;
		for (int ins = 0; ins < search; ins++)
		{
			cin >> start;
			visitedReal.reset();
			visited.reset();
			breadthFirstS(adjList, visited, visitedReal, start);

			//loop through visted and print out all the inaccessible vertices
			inCount = 0;
			for (int v = 1; v <= numVertices; v++)
			{
				if (visited[v] == 0)
				{
					inCount++;
				}
			}

			cout << inCount;
			for (int v = 1; v <= numVertices; v++)
			{
				if (visited[v] == 0)
				{
					cout << " " << v;
				}
			}
			cout << endl;
		}

		cin >> numVertices;
		adjList.clear();
	}
	return 0;
}

void breadthFirstS(vector<vector<int>> & graph, bitset<102>& visited, bitset<102>& visitedR, int start)
{
	int startIndex;
	startIndex = startIndexS(graph, start);
	if (startIndex == -1)
		visitedR[start] = 1;
	//search adjacent non visited nodes
	breadthFirstSearch(graph, visited, visitedR, startIndex);

}

void breadthFirstSearch(vector<vector<int>> & graph, bitset<102>& visited, bitset<102>& visitedR, int startIndex)
{
	int s;

	if (startIndex != -1)
	{
		visitedR[graph[startIndex][0]] = 1;
		//mark the adjacents you can get to
		for (int i = 1; i < graph[startIndex].size(); i++)
		{
			visited[graph[startIndex][i]] = 1;
		}

		//do the same for all adjacents
		if (graph[startIndex].size() != 1)
		{
			for (int i = 1; i < graph[startIndex].size(); i++)
			{
				//searched for the index of start node in the graph
				s = startIndexS(graph, graph[startIndex][i]);
				if (s == -1)
					visitedR[graph[startIndex][i]] = 1;

				if (visitedR[graph[startIndex][i]] != 1)
					breadthFirstSearch(graph, visited, visitedR, s);
			}
		}
	}
}

//searched for the index of start node in the graph
int startIndexS(vector<vector<int>> & graph, int start)
{
	int startIndex;
	bool found = false;
	//search for the starting node
	for (int i = 0; i < graph.size() && !found; i++)
	{
		if (graph[i][0] == start)
		{
			found = true;
			startIndex = i;
		}
	}

	if (found)
		return startIndex;
	else
		return -1;
}
