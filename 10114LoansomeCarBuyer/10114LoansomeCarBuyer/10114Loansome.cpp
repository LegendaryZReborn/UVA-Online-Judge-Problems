#include <iostream>

using namespace std;
#define endl '\n'


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int months, numRecords, monthNum, numMonths;
	double downP, loan, carValue, depr, newDepr, pay;
	bool done;

	while (cin >> months >> downP >> loan >> numRecords)
	{
		if (months > 0)
		{
			//calculate the car value
			carValue = downP + loan;
			pay = loan / (double)months;
			done = false;
			numMonths = 0;

			//for month 0
			cin >> monthNum >> depr;
			carValue -= (carValue * depr);
			numRecords--;
			
			if (loan < carValue)
				done = true;

			if (numRecords != 0)
			{
				cin >> monthNum >> newDepr;
				numRecords--;
			}
			//for each record until the loan < carValue
			for (int m = 1; m <= months && done == false; m++)
			{
				numMonths++;
				if (monthNum == m)
				{
					depr = newDepr;

					if (numRecords > 0)
					{
						cin >> monthNum >> newDepr;
						numRecords--;
					}
				}

				carValue -= (carValue * depr);
				loan -= pay;
				if (loan < carValue)
				{
					done = true;
					
					//read remaining records in
					for (int r = 0; r < numRecords; r++)
					{
						cin >> months >> depr;
					}
				}

			
				
			}
			
			if (numMonths == 1)
				cout << numMonths << " month" << endl;
			else
				cout << numMonths << " months" << endl;
		}
	}
	return 0;
}