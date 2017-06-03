//4147JollyBeeTournament
#include <iostream>
#include <bitset>
#include <cmath>

using namespace std;
#define endl '\n'


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	bitset<1024> contestants;
	int t, n, numDrops, dropped, ored, nI, limit, wo, ji;
	bool done;

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		contestants.set();

		nI = 0;
		done = false;
		wo = 0;
		cin >> n >> numDrops;

		for (int j = 0; j < numDrops; j++)
		{
			cin >> dropped;
			contestants[dropped - 1] = 0;
		}

		if (!(numDrops == 0) && numDrops < pow(2, n))
		{
			ji = 0;
			limit = pow(2, n) - 1;
			while (ji < limit && !done)
			{
				if ((contestants[ji] == 0 && contestants[ji + 1] == 1) || (contestants[ji] == 1 && contestants[ji + 1] == 0))
					wo++;

				ored = contestants[ji] | contestants[ji + 1];
				contestants[nI] = ored;

				nI++;
				ji += 2;

				if (ji >= limit)
				{
					n = n - 1;
					limit = pow(2, n) - 1;
					ji = 0;
					nI = 0;
				}

				if (n < 1)
					done = true;


			}
			cout << wo << endl;
		}
		else
		{
			cout << 0 << endl;
		}
		
	}
	return 0;
}

