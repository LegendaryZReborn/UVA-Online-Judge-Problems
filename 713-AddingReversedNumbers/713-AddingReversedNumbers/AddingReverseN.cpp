//713AddingReversedNumbers
#include <iostream>
#include <string>

using namespace std;
#define endl '\n'

string addIntStringsR(string num1, string num2);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	string N1, N2, rN1, rN2;
	string c, Ans;
	bool lZ;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		rN1 = "";
		rN2 = "";
		lZ = true;

		cin >> N1 >> N2;

		//reverse the numbers
		for (int f = N1.length(); f > 0; f--)
		{
			c = N1[f - 1];
			rN1.append(c);
		}

		for (int s = N2.length(); s > 0; s--)
		{
			c = N2[s - 1];
			rN2.append(c);
		}

		//add the reverse numbers to get the reversed sum
		Ans = addIntStringsR(rN1, rN2);

		for (int a = 0; a < Ans.length(); a++)
		{

			if (Ans[a] != '0')
			{
				lZ = false;
			}

			if(lZ != true)
			{
				cout << Ans[a];

			}
		}

		cout << endl;
	
	}
	return 0;

}

string addIntStringsR(string num1, string num2)
{
	int carry = 0;
	string sSum = "", dAns;
	string c;

	if (num1.length() > num2.length())
		num2 = string(num1.length() - num2.length(), '0') + num2;
	if (num1.length() < num2.length())
		num1 = string(num2.length() - num1.length(), '0') + num1;

	
	for (int j = num1.length(); j > 0; j--)
	{
		//add two digits
		dAns = to_string((num1[j - 1] - '0') + (num2[j - 1] - '0') + carry);
		carry = 0;

		if (dAns.length() > 1)
		{
			//then a carry is there
			carry = dAns[0] - '0';
			//append to sum
			c = dAns[1];
			
		}
		else
		{
			//append to sum
			c = dAns[0];
			
		}
		
		sSum.append(c);
	}

	if (carry != 0)
	{
		sSum.append(to_string(carry));
	}
		return sSum;
}