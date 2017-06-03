#include <iostream>
#include <vector>

using namespace std;

int main()
{
	bool isJolly;
	vector<int> numbers;
	vector <bool> diffs;
	int diffint, size, val;

	while (cin >> size)
	{
		numbers.resize(size);
		diffs.resize(size);
		diffs.assign(diffs.size(), 0);
		isJolly = true;

		for (int i = 0; i < size; i++)
		{
			cin >> val;
			numbers[i] = val;
		}
		
		for (int i = 0; i < size - 1; i++)
		{
			diffint =numbers[i] - numbers[i + 1];
			
			if (diffint < 0)
			{
				diffint *= -1;
			}

			if (diffint < size)
			{
				diffs[diffint] = true;
			}
		}

		for (int i = 1; i < size && isJolly == true; i++)
		{
			if (diffs[i] == false)
				isJolly = false;
		}

		if (isJolly)
			cout << "Jolly" << endl;
		else
			cout << "Not jolly" << endl;
	}
	return 0;
}