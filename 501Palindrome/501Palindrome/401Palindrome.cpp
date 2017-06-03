//401Palindrome
#include <iostream>
#include <string>

using namespace std;
#define endl '\n'

bool palindromCheck(string orgS);
bool mirrorCheck(string org, string valm);

string reverse(string val);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	char c = 'A';
	int d = 1;
	string iStr, rStr;
	
	while (cin >> iStr)
	{
		rStr = reverse(iStr);

		if (palindromCheck(iStr) && mirrorCheck(iStr, rStr))
		{
			cout << iStr << " -- is a mirrored palindrome." << endl;

		}
		else if (palindromCheck(iStr))
		{
			cout << iStr << " -- is a regular palindrome." << endl;
		}
		else if (mirrorCheck(iStr, rStr))
		{
			cout << iStr << " -- is a mirrored string." << endl;
		}
		else 
		{
			cout << iStr << " -- is not a palindrome." << endl;
		}

		cout << endl;
	}

	return 0;
}

bool palindromCheck(string orgS)
{
	string rString, c;
	

	for (int j = orgS.length(); j > 0; j--)
	{
		c = orgS[j - 1];
		rString.append(c);
	}



	if (rString == orgS)
		return true;
	else
		return false;
}

bool mirrorCheck(string org, string valm)
{
	bool mirrored = true;

	for (int i = 0; i < org.length(); i++)
	{
		if (org[i] != valm[(org.length() - 1) - i])
		{
			mirrored = false;
		}
	}

	return mirrored;
}


string reverse(string val)
{
	string valC = val;
	string characters = "AEHIJLMOSTUVWXYZ12358";
	string reverses = "A3HILJMO2TUVWXY51SEZ8";
	int find;

	for (int i = 0; i < val.length(); i++)
	{
		find = characters.find(val[i]);

		if (find != -1)
		{
			valC[i] = reverses[find];
		}
		else
		{
			valC[i] = '?';
		}
	}

	
	return valC;
}
