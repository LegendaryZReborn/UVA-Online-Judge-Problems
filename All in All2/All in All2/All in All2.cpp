#include <iostream>
#include <string>

using namespace std;


int main(int argc, char* argv[])
{

	string original, crypted;
	int count, count2;
	bool isSub = false;
	string yesNo = "";

	while (cin >> original)
	{
		cin >> crypted;
		count = 0;
		count2 = 0;
		isSub = false;

		while (count2 < crypted.length() && !isSub)
		{
			if (original[count] == crypted[count2])
			{
				count++;
			}
			count2++;

			if (count == original.length())
			{
				isSub = true;
			}
		}

		if (isSub == true)
		{
			yesNo = "Yes";
		}
		else
		{
			yesNo = "No";
		}

		cout << yesNo << endl;
	}

		
	return 0;
}

