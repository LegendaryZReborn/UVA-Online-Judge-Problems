#include <iostream>

using namespace std;

#define endl '\n'

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	long long int N, sum, ln, termNum;

	while (cin >> ln)
	{
		//finds which line N has ln odd numbers;
		N = (ln + 1) / 2;

		//sums the number of terms in the lines before N and the number of terms in N
		termNum = ((N - 1) * (N - 1)) + (2 * N - 1);

		//sum of last three numbers in line N
		sum = ((1 + (termNum - 1) * 2) * 3) - 6;
		cout << sum << endl;
	}
}