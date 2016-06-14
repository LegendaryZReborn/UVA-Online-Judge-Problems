//Cavaughn Browne

#include<iostream>


using namespace std;

int main()
{

	int a, b, al, bl, ar, br, c, d, sum;
	while (cin >> a)
	{
		cin >> b;
		al = ~a;
		bl = b;

		c = al & bl;

		br = ~b;
		ar = a;
		d = ar & br;

		sum = c | d;

		cout << sum << endl;
	}


	return 0;
}