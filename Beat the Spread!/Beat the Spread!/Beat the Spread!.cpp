// Beat the Spread!.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>

using namespace std;


int main(int argc, char* argv[])
{
	int numCases, sum, diff, score1, score2;
	string verdict = "impossible";

	while (cin >> numCases)
	{
		for (int i = 0; i < numCases; i++)
		{
			cin >> sum >> diff;

			if (sum < diff)
			{
				cout << verdict << endl;

			}
			else
			{
				if ((sum + diff) % 2 == 0)
				{
					score1 = (sum + diff) / 2;
					score2 = sum - score1;

					cout << score1 << " " << score2 << endl;
				}
				else
				{
					cout << verdict << endl;
				}
			}
		}
	}
	return 0;
}

