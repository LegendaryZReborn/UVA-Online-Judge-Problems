//10079PizzaCutting
#include<iostream>


using namespace std;

#define endl '\n'
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	long long int N, pieces;

	cin >> N;
	while (N >= 0)
	{
		pieces = (((N*N) + N) / 2) + 1;

		cout << pieces << endl;
		cin >> N;
	}
	return 0;
}