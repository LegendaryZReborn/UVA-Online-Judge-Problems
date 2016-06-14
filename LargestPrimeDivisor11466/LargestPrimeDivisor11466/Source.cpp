#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	int N, M, S, maxPrime, length = 0, s, i;
	bool prime, found, maxFound;
	vector<int> primeNumbers;
 
	primeNumbers.resize(50);
	primeNumbers[length] = 2;
	length++;

	cin >> N;
	S = N;
	while (N != 0)
	{
		maxFound = false;
		maxPrime = 2;
		s = 0;
		while (!maxFound)
		{
			//check if N is prime
			
				prime = true;


				for (int j = 2; j <= sqrt(N) && N != 2 && prime; j++)
				{
					if(N % j == 0)
					{
						prime = false;
					}
				}

				if (prime == true)
				{
					if (N == S)
						cout << "-1" << endl;

					if (N > maxPrime)
					{
						maxPrime = N;
					}
					maxFound = true;
				}


				s = 0;
			found = false;
			while (s < length && found == false && !maxFound)
			{
				if (N % primeNumbers[s] == 0)
				{
					M = N / primeNumbers[s];
					s = 0;
					found = true;
					N = M;
					
					if (primeNumbers[s] > maxPrime)
					{
						maxPrime = primeNumbers[s];
					}
				}
				s++;
			}


			if (found == false && !maxFound)
			{
				

					//find smallest prime number to divide N
					i = primeNumbers[s - 1];
					if (i % 2 == 0)
					{
						i++;
					}
					while (i <= sqrt(N) && found == false)
					{
						prime = true;

						for (int j = 0; j < length && prime; j++)
						{
							if (i % primeNumbers[j] == 0)
							{
								prime = false;
							}
						}

						if (prime == true)
						{
							primeNumbers[length] = i;
							length++;

							if (N % i == 0)
							{
								found = true;
							}
						}


						i += 2;
					}



			}
		}

		if (N != S)
			cout << maxPrime << endl;

		cin >> N;
		S = N;
	}

	return 0;
}