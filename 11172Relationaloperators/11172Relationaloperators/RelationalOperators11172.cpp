//11172RelationalOperators
#include <iostream>
#include <stdio.h>

using namespace std;
#define endl '\n'



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, n1, n2;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> n1 >> n2;

		if (n1 > n2)
		{
			cout << ">" << endl;
		}
		else if (n1 < n2)
		{
			cout << "<" << endl;
		}
		else
		{
			cout << "=" << endl;
		}
	}

	return 0;
}