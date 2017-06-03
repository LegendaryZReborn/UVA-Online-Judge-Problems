//10110LightMoreLight
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	long long int n, m;

	cin >> n;
	while (n != 0)
	{
		m = sqrt(n);
		if ((m * m) == n)
		{
			cout << "yes" << endl;
		}
		else
		{
			cout << "no" << endl;
		}

		cin >> n;
	}

	return 0;
}