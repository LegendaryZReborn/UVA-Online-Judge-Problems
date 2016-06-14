#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

#define endl '\n'

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string compound;
	int T, c, n, h, o, num, s;
	double C = 12.01, H = 1.008, O = 16.00, N = 14.01;

	while (cin >> T)
	{
		
		for (int i = 0; i < T; i++)
		{
			cin >> compound;

			c = 0;
			h = 0;
			n = 0;
			o = 0;

			
			for (int j = 0; j < compound.length(); j++)
			{
				if (!isdigit(compound[j]))
				{

					if (j != (compound.length() - 1) && isdigit(compound[j + 1]))
					{
						s = 2;
						while ((j + (s-1)) != (compound.length() - 1) && isdigit(compound[j + s]))
						{
							if ((j + s) == (compound.length() - 1) || !isdigit(compound[j + (s + 1)]))
							{
								num = stoi(compound.substr(j + 1, s));
							}
							s++;
						}

						if (s == 2)
						{
							num = compound[j + 1] - '0';
						}
					}
					else
					{
						num = 1;
					}

					//count molecules
					if (compound[j] == 'C')
					{
						c += num;
					}
					else if (compound[j] == 'H')
					{
						h += num;
					}
					else if (compound[j] == 'O')
					{
						o += num;
					}
					else if (compound[j] == 'N')
					{
						n += num;
					}
				}
			}

			cout << fixed;
			cout << setprecision(3) << (C*c) + (H*h) + (N*n) + (O*o) << endl;
			
		}
	}

	
	return 0;
}