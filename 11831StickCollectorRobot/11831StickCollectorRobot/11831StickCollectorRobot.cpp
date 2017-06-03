//11831StickCollectorRobot
#include <iostream>
#include <vector>

using namespace std;
#define endl '\n'

struct location
{
	int i;
	int j;
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	vector< vector<char>> map;
	int N, M, S, numStickers;
	char instruction, mapI, junk, direction;
	location robL, front;

	cin >> N >> M >> S;
	while (N != 0 && M != 0 && S != 0)
	{
		numStickers = 0;
		map.resize(N);
		for (int i = 0; i < N; i++)
		{
			map[i].resize(M);
		}

		for (int i = 0; i < N; i++)
		{
			cin.get(junk);
			for (int j = 0; j < M; j++)
			{
				cin.get(mapI);
				map[i][j] = mapI;

				if (mapI == 'N' || mapI == 'S' || mapI == 'L' || mapI == 'O')
				{
					direction = mapI;
					robL.i = i;
					robL.j = j;
				}
			}
		}

		cin.get(junk);
		for (int s = 0; s < S; s++)
		{
			cin >> instruction;
			if (instruction == 'D') //turn 90 degrees to the right
			{
				if (direction == 'N')
					direction = 'L';
				else if (direction == 'L')
					direction = 'S';
				else if (direction == 'S')
					direction = 'O';
				else
					direction = 'N';
			}
			else if (instruction == 'E') //Turn 90 degrees to the left
			{
				if (direction == 'N')
					direction = 'O';
				else if (direction == 'O')
					direction = 'S';
				else if (direction == 'S')
					direction = 'L';
				else
					direction = 'N';
			}
			else //move forward
			{
				if (direction == 'N')
				{
					front.i = robL.i - 1;
					front.j = robL.j;
				}
				else if(direction == 'S')
				{
					front.i = robL.i + 1;
					front.j = robL.j;
				}
				else if (direction == 'L')
				{
					front.i = robL.i;
					front.j = robL.j + 1;
				}
				else
				{
					front.i = robL.i;
					front.j = robL.j - 1;
				}
				
				//If theres no problem move to sqaure and collect if possible
				if (front.i >= 0 && front.i < N && front.j >= 0 && front.j < M && map[front.i][front.j] != '#')
				{
					if (map[front.i][front.j] == '*')
					{
						numStickers++;
					}

					//move robot 
					map[robL.i][robL.j] = '.';
					map[front.i][front.j] = direction;
					robL.i = front.i;
					robL.j = front.j;

				}
			}
		}

		cout << numStickers << endl;
		cin >> N >> M >> S;
	}
	

	


	return 0;
}

