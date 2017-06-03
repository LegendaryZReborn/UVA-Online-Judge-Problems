//11222OnlyIdidit
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
#define endl '\n'


void uniquify(int problems_size, vector <int> &p1, vector <int> &p2, vector <int> &p3);

bool checkIfIn(vector<int> &hash, int size, int in);



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T, nP1, nP2, nP3, probNum, pC;
	vector <int> f1, f2, f3, p1, p2, p3;
	int st1, st2, st3;
	
	
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		pC = 0;

		//for each friend
			cin >> nP1;
			f1.resize(nP1 + 1);
			p1.resize(nP1);
			f1[0] = nP1;

			for (int f = 1; f <= nP1; f++)
			{
				cin >> probNum;
				f1[f] = probNum;
				
			}

			cin >> nP2;
			f2.resize(nP2 + 1);
			p2.resize(nP2);
			f2[0] = nP2;

			for (int s = 1; s <= nP2; s++)
			{
				cin >> probNum;
				f2[s] = probNum;

			}

			cin >> nP3;
			f3.resize(nP3 + 1);
			p3.resize(nP3);
			f3[0] = nP3;

			for (int t = 1; t <= nP3; t++)
			{
				cin >> probNum;
				f3[t] = probNum;

			}

			//sort them
			sort(f1.begin() + 1, f1.end());
			sort(f2.begin() + 1, f2.end());
			sort(f3.begin() + 1, f3.end());


			//put lists into other vectors
			
			for (int f = 1; f <= nP1; f++)
			{	
				p1[f-1] = f1[f];

			}

			
			for (int s = 1; s <= nP2; s++)
			{
				p2[s - 1] = f2[s];

			}

			for (int t = 1; t <= nP3; t++)
			{
		
				p3[t - 1] = f3[t];
			
			}

			pC = nP1 + nP2 + nP3;
			uniquify(pC, p1, p2, p3);

			

			cout << "Case #" << i + 1 << ":" << endl;
			//find the largest and print
			if (p1.size() >= p2.size()  && p1.size() >= p3.size())
			{
				
				//print the first friend
				cout << "1";
				cout << " " << p1.size();
				for (int pf = 0; pf < p1.size(); pf++)
				{
					cout << " " << p1[pf];
					
				}
				cout << endl;
			}
			if (p2.size() >= p1.size() && p2.size() >= p3.size())
			{
				
				//print the second friend
				cout << "2";
				cout << " " << p2.size();
				for (int sf = 0; sf < p2.size(); sf++)
				{
					cout << " " << p2[sf] ;
					
				}
				cout << endl;
			}
			if (p3.size() >= p1.size() && p3.size() >= p2.size())
			{
				//print the third friend
				cout << "3";
				cout << " " << p3.size();
				for (int tf = 0; tf < p3.size(); tf++)
				{
					cout << " " << p3[tf] ;
					
				}

					cout << endl;

					
			}
			
	}
	
	return 0;
}


void uniquify(int problems_size, vector <int> &p1, vector <int> &p2, vector <int> &p3 )
{
	
	vector <int> hash, todelete;
	hash.resize(problems_size);
	todelete.resize(problems_size);
	int index = 0, delI = 0;

	for (int j = 0; j < p1.size(); j++)
	{
		if (checkIfIn(hash, index, p1[j]))
		{
			if (!checkIfIn(todelete, delI, p1[j]))
			{
				todelete[delI] = p1[j];
				delI++;
			}


		}
		else
		{
			//add it
			hash[index] = p1[j];
			index++;

		}
	}

	for (int j = 0; j < p2.size(); j++)
	{
		if (checkIfIn(hash, index, p2[j]))
		{
			if (!checkIfIn(todelete, delI, p2[j]))
			{
				todelete[delI] = p2[j];
				delI++;
			}


		}
		else
		{
			//add it
			hash[index] = p2[j];
			index++;

		}
	}

	for (int j = 0; j < p3.size(); j++)
	{
		if (checkIfIn(hash, index, p3[j]))
		{
			if (!checkIfIn(todelete, delI, p3[j]))
			{
				todelete[delI] = p3[j];
				delI++;
			}


		}
		else
		{
			//add it
			hash[index] = p3[j];
			index++;

		}
	}

	for (int d = 0; d < delI; d++)
	{
		p1.erase(remove(p1.begin(), p1.end(), todelete[d]), p1.end());
		p2.erase(remove(p2.begin(), p2.end(), todelete[d]), p2.end());
		p3.erase(remove(p3.begin(), p3.end(), todelete[d]), p3.end());
		
	}
	
}

bool checkIfIn(vector<int> &hash, int size, int in)
{
	bool found = false;

	for (int i = 0; i < size; i++)
	{
		if (hash[i] == in && found == false)
		{
			found = true;
		}
	}

	return found;
}

