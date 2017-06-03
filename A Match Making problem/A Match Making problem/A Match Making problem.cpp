// A Match Making problem.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int B, S, age, seniorB, closestS, closestDif, difference, youngestB, numB = 0, caseNum = 1, n = 0;
	vector <int> agesB, agesS;
	int bCount, sCount;


	while (cin >> B >> S)
	{
		agesB.resize(B);
		agesS.resize(S);
		if (B != 0 && S != 0)
		{
		
			sCount = S;
			bCount = B;
			// reads in ages
			for (int i = 0; i < B; i++)
			{
				cin >> age;
				agesB[i] = age;
			}

			for (int i = 0; i < S; i++)
			{
				cin >> age;
				agesS[i] = age;
				
			}

			while (bCount > 0 && sCount > 0)
			{
				closestS = 0;
				seniorB = 0;

				//finds the most senior
				for (int i = 0; i < B; i++)
				{
					if (agesB[i] > agesB[seniorB] && agesB[i] != -1)
					{
						seniorB = i;
					}
				}

				closestDif = -1;
				n = 0;
				while(closestDif ==-1 )
				{
					if (agesS[n] != -1)
					{
						closestDif = agesB[seniorB] - agesS[n];
					}
					n++;
				}

				if (closestDif < 0)
				{
					closestDif *= -1;
				}

				//finds the closest to the seniorB
				for (int i = 0; i < S; i++)
				{
					if (agesS[i] != -1)
					{

						difference = agesB[seniorB] - agesS[i];

						if (difference < 0)
						{
							difference *= -1;
						}

						if (closestDif > difference)
						{
							closestS = i;
							closestDif = difference;

						}
					}


				}

				agesB[seniorB] = -1;
				bCount -= 1;
				agesS[closestS] = -1;
				sCount -= 1;
			}

			numB = 0;
			youngestB = -1;
			for (int i = 0; i < B; i++)
			{
				
				if (bCount != 0)
				{

					if (agesB[i] != -1)
					{
						if (youngestB == -1)
						{
							youngestB = i;
						}
						numB++;
					}

					if (agesB[i] != -1 && agesB[i] < agesB[youngestB])
					{
						youngestB = i;
					}
				}
			}

			
			

			if (numB != 0)
			{
				cout << "Case " << caseNum << ": " << numB << " " << agesB[youngestB] << endl;
			}
			else
			{
				cout << "Case " << caseNum << ": " << numB << endl;
			}
			caseNum++;
		}


	}
	return 0;
}

