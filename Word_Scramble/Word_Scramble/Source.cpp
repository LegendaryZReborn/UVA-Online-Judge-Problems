#include <stack>
#include <iostream>
#include <string>


using namespace std;

int main()
{
	string word, sentence;
	stack<char> letterStack;
	int start, position = 0;



	while (getline(cin, sentence))
	{
		position = 0;
		while (position < sentence.length())
		{
			start = position;
			if (isspace(sentence[start]))
			{
				start++;
				position++;
			}

			while (position < sentence.length() && !isspace(sentence[position]))
			{
				position++;
			}

			word = sentence.substr(start, (position - start));
			for (int i = 0; i < word.length(); i++)
			{
				letterStack.push(word[i]);
			}

			for (int j = 0; j < word.length(); j++)
			{
				word[j] = letterStack.top();
				letterStack.pop();
			}
		
			if (position < sentence.length())
			{
				cout << word << " ";
			}
			else
			{
				cout << word;
			}
		}

		cout << endl;
	}
	return 0;
}