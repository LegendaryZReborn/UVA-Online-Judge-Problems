//11547Automatic Answer
#include <iostream>
#include <string>

using namespace std;
#define endl '\n'


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t, n, ans;
	string ansS;

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> n;
		ans = (((((n * 567) / 9) + 7492) * 235) / 47) - 498;

		ansS = to_string(ans);
		cout << ansS[ansS.length() - 2] << endl;
	}

	return 0;
}

