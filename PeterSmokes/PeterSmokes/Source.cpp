//10346 Peter's Smokes
//Cavaughn Browne
#include <iostream>

using namespace std;

int main()
{
	int n, k, num, r, cn;

	while (cin >> n >> k)
	{
		num = n;
		r = num;

		while (n >= k)
		{
			cn = n;
			n = n / k;
			r = cn % k;
			num += n;
			n += r;
		}

		cout << num << endl;
	}

	return 0;
}