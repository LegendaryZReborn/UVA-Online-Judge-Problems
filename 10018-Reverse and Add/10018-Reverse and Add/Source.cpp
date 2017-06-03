//10018 Reverse and Add
#include <iostream>
#include <string>

using namespace std;
#define endl '\n'

bool palindromCheck(long long int num);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	long long int pal, n, n2, n3;
	int incr;
	string num, rnums;
	string c;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		//read number and then process it
		cin >> n2;
		incr = 0;

		do
		{
			//initialize
			num = "";
			rnums = "";
			

			//change it to a string and then reverse it; store in rnums
			num = to_string(n2);

			for (int j = num.length(); j > 0; j--)
			{
				c = num[j - 1];
				rnums.append(c);
			}

			//change rnums to an int and add it to original
			n3 = stoll(rnums);
			n2 += n3;
			incr++;

			//check if its a palindrome
			if (palindromCheck(n2))
			{
				cout << incr << " " << n2 << endl;
			}
		
		} while (!palindromCheck(n2));
		
		
	}

	return 0;
}

	bool palindromCheck(long long int num)
	{
		string rnumss, numS, c;
		long long int rnumf;
		
		//change it to a string and then reverse it; store in rnums
		numS = to_string(num);

		for (int j = numS.length(); j > 0; j--)
		{
			c = numS[j - 1];
			rnumss.append(c);
		}

		//change rnumss to an int and add it to original
		rnumf = stoll(rnumss);

		if (rnumf == num)
			return true;
		else
			return false;
	}
