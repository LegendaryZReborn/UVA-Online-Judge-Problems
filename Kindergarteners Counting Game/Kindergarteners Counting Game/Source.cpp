#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
	string sentence;
	int wordCount = 0, sentenceL, letterCount = 0, i = 0; 
	bool word = false;
	

	while (getline(cin, sentence))
	{
		sentenceL = sentence.length();
		wordCount = 0;
		word = false;

		for (int i = 0; i < sentenceL; i++)
		{
			if (!word && isalpha(sentence[i]))
			{
				wordCount++;
				word = true;
			}
			else if (word == true && !isalpha(sentence[i]) || isspace(sentence[i]))
			{
				word = false;
			}
		}
		cout << wordCount << endl;
	}

	return 0;
}