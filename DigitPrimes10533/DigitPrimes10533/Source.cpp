#include <iostream>
#include <string>
#include <bitset>
#include <vector>

using namespace std;

#define endl '\n'

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, r1 = -1, r2 = -1, j, pos, numD = 0, sum;
	string num;
	bool prime;
	bitset<1000001> sieve;
	vector <int> digitPrimes;
	
	digitPrimes.resize(1000001);

	//Sieve of Era
	sieve.set();
	sieve[0] = 0;
	sieve[1] = 0;

	for (int i = 2; i < 1000; i++)
	{
		if (sieve[i] == 1)
		{
			for (int j = i * i; j < 1000001; j += i)
			{
				sieve[j] = 0;
			}
		}
	}

	for (int i = 0; i < 1000001; i++)
	{
		prime = true;
		if (sieve[i] == 0)
		{
			prime = false;
		}

		if (prime)
		{
			num = to_string(i);
			//sums the digits of the current number
			sum = 0;
			for (int s = 0; s < num.length(); s++)
			{
				sum += (num[s] - '0');
			}

			if (sieve[sum] == 0)
			{
				prime = false;
			}
			else
			{
				numD++; 
				
			}

		}
		digitPrimes[i] = numD;

	}
	
	//start finding gjhthe digitPrimes
	while (cin >> N)
	{
		for (int inputs = 0; inputs < N; inputs++)
		{
			cin >> r1 >> r2;

			
			
			cout << digitPrimes[r2] - digitPrimes[r1 -1]<< endl;
		}
		
	}

	return 0;
}