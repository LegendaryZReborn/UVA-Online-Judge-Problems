#include <iostream>


using namespace std;

int main()
{
	int c, f, a;
	bool first = true;

	

	cin >> c;
	for (int i = 0; i < c; i++)
	{
		cin >> a;
		cin >> f;

		for (int fc = 0; fc < f; fc++)
		{
			if (first)
			{
				first = false;
			}
			else
			{
				cout << endl;
				
			}
			
			//print up
			for (int s = 1; s <= a; s++)
			{
				for (int m = 1; m <= s; m++)
				{
					cout << s;
					
				}

				cout << endl;
				
			}

			//print back down
			for (int s = (a - 1); s >= 1; s--)
			{
				for (int m = s; m >= 1; m--)
				{
					cout << s;
					
				}

				cout << endl;
				
			}
			
			
		}

		
	}
	return 0;
}