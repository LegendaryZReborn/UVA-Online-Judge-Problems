#include <iostream>

using namespace std;
#define endl '\n'

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	long n1, n2, d;

	while (cin >> n1 >> n2)
	{
		d = n1 - n2;

		if (d < 0)
			d *= -1;

		cout << d << endl;
	}
	return 0;
}
