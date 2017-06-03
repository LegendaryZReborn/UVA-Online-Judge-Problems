#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
	int N;
	double C, grade, sum, average, count, percentageAA;
	vector<double> grades;
	
	cin >> C;
	for (int i = 0; i < C; i++)
	{
		cin >> N;
		sum = 0;
		grades.resize(N);
		for (int n = 0; n < N; n++)
		{
			cin >> grade;
			grades[n] = grade;
			sum += grade;

		}

		average = sum / N;

		//go through vector and count how many grades are > average
		count = 0;
		for (int a = 0; a < N; a++)
		{
			if (grades[a] > average)
			{
				count++;
			}
		}

		percentageAA = (count / N) * 100;

		cout << fixed;
		cout << setprecision(3) << percentageAA << "%" << endl;

	}
	return 0;
}