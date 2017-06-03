#include <iostream>
#include <string>
#include <bitset>
#include <vector>

using namespace std;

int main()
{
	string zeroesOnes;
	vector <int> pre;
	int caseNum, i, j, max, min, count = 1, begin;
	bool same = true;
	
	

	while (cin >> zeroesOnes)
	{
			cin >> caseNum;
			cout << "Case " << count << ":" << endl;

			//preprocessing
			pre.resize(zeroesOnes.length());
			begin = 0;

			for (int s = 0; s < zeroesOnes.length(); s++)
			{
				if (zeroesOnes[s] == zeroesOnes[begin])
				{
					pre[s] = begin;
				}
				else
				{
					begin = s;
					pre[s] = s;
				}
			}

			for (int c = 0; c < caseNum; c++)
			{
				same = true;
				cin >> i >> j;
				if (i >= j)
				{
					max = i;
					min = j;
				}
				else
				{
					max = j;
					min = i;
				}

				if (pre[min] != pre[max])
				{
					same = false;
				}

				if (same == true)
				{
					cout << "Yes" << endl;
				}
				else
				{
					cout << "No" << endl;
				}
			}

			
			count++;
	}

	return 0;

}