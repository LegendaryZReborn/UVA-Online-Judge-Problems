#include <iostream>

using namespace std;

int main()
{

	int T, mid, sal;
	int salArray[3];
	cin >> T;

	for (int t = 0; t < T; t++)
	{ 
		for (int s = 0; s < 3; s++)
		{
			cin >> sal;
			salArray[s] = sal;
		}

		mid = salArray[0];
		
		if ((salArray[0] > salArray[1] && salArray[0] < salArray[2]) || (salArray[0] < salArray[1] && salArray[0] > salArray[2]))
		{
			mid = salArray[0];
		}
		else if ((salArray[1] > salArray[0] && salArray[1] < salArray[2]) || (salArray[1] < salArray[0] && salArray[1] > salArray[2]))
		{
			mid = salArray[1];
		}
		else if ((salArray[2] > salArray[0] && salArray[2] < salArray[1]) || (salArray[2] < salArray[0] && salArray[2] > salArray[1]))
		{
			mid = salArray[2];
		}

		cout << "Case " << t + 1 << ": "<< mid << endl;
	}
	return 0;
}