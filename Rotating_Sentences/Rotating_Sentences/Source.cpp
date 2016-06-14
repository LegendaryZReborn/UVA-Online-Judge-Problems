//Programmed: Cavaughn Browne

#include <iostream>
#include <string>

using namespace std;

int main()
{
	
	string mySentences[100];
	string sentence;
	int longest = 0;
	int i = 0, j = 0, c, length;

	while (getline(cin, sentence))
	{
		mySentences[i] = sentence;
		i++;
	}
	i = i-1;
	j = 0;
	c = i;

	for (int n = 0; n <= i; n++)
	{
		if (mySentences[n].length() > mySentences[longest].length())
		{
			longest = n;
		}
	}

	for (int m = 0; m < mySentences[longest].length(); m++)
	{
		i = c;
		while (i >= 0)
		{
			sentence = mySentences[i];
			if (j < sentence.length())
			{
				cout << sentence[j];

			}
			else
			{
				cout << " ";
			}
			
			i -= 1;

		}
		j++;
		cout << endl;
	}

	return 0;
}