#include <iostream>
#include <string>

using namespace std;


int main(int argc, char* argv[])
{
	string lineInput;

	while (getline(cin, lineInput))
	{
		for (int i = 0; i < lineInput.size(); i++)
		{
			lineInput[i] = lineInput[i] - 7;
		}

		cout << lineInput << endl;
	}
}

