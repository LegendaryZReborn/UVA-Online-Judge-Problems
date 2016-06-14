// Mirror Mirror.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void verticalRef(vector<vector<char> > &reflectedPatternSquare, vector<vector<char> > &patternSquare, int size);
bool equalArray(vector<vector<char> > &patternSquare, vector<vector<char> > &patternSquare2, int size);
void rotateSquare(vector<vector<char> > &patternSquare, vector<vector<char> > &rotatedPatternSquare, int size);


int main(int argc, char* argv[])
{
	int size, count = 0, rotationCount;
	char item;
	bool equal;
	vector<vector<char> > patternSquare;
	vector<vector<char> > transformedPatternSquare;
	vector<vector<char> > testPatternSquare; 
	vector<vector<char> > rotatedPatternSquare;

	while (cin >> size)
	{

		equal = false;
		rotationCount = 0;
		count++;

		// initiallize 2 2d arrays
		patternSquare.resize(size);

		for (int i = 0; i < size; i++)
		{
				patternSquare[i].resize(size);
		}

		transformedPatternSquare.resize(size);

		for (int i = 0; i < size; i++)
		{
			transformedPatternSquare[i].resize(size);
		}

		testPatternSquare.resize(size);

		for (int i = 0; i < size; i++)
		{
			testPatternSquare[i].resize(size);
		}

		rotatedPatternSquare.resize(size);

		for (int i = 0; i < size; i++)
		{
			rotatedPatternSquare[i].resize(size);
		}

		//read in the square patterns into their appropriate arrays
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				cin >> item;
				patternSquare[i][j] = item;
			}

			for (int j = 0; j < size; j++)
			{
				cin >> item;
				transformedPatternSquare[i][j] = item;
			}
		}


		//check for equality
		equal = equalArray(patternSquare, transformedPatternSquare, size);

		if (equal)
		{
			cout << "Pattern " << count << " was preserved." << endl;
		}
		else
		{
			
				while (rotationCount != 270 && equal != true)
				{
					rotateSquare(patternSquare, rotatedPatternSquare, size);
					rotationCount += 90;
					

					equal = equalArray(rotatedPatternSquare, transformedPatternSquare, size);
					if (equal)
					{

						cout << "Pattern " << count << " was rotated " << rotationCount << " degrees." << endl;
		
					}

					//copy rotatedsquare to pattern square
					for (int i = 0; i < size; i++)
					{
						for (int j = 0; j < size; j++)
						{
							patternSquare[i][j] = rotatedPatternSquare[i][j];
						}
					}
				}

				if (!equal)
				{
					//reset
					rotationCount = 0;
					rotateSquare(patternSquare, rotatedPatternSquare, size);

					//copy rotatedsquare to pattern square
					for (int i = 0; i < size; i++)
					{
						for (int j = 0; j < size; j++)
						{
							patternSquare[i][j] = rotatedPatternSquare[i][j];
						}
					}

					verticalRef(testPatternSquare, patternSquare, size);

					equal = equalArray(transformedPatternSquare, testPatternSquare, size);
					if (equal)
					{
						cout << "Pattern " << count << " was reflected vertically." << endl;

					}
					else
					{

						while (rotationCount != 270 && equal != true)
						{
							rotateSquare(testPatternSquare, rotatedPatternSquare, size);
							rotationCount += 90;
						

							equal = equalArray(rotatedPatternSquare, transformedPatternSquare, size);
							if (equal)
							{
								cout << "Pattern " << count << " was reflected vertically and rotated " << rotationCount << " degrees." << endl;
							}

							//copy rotatedsquare to pattern square
							for (int i = 0; i < size; i++)
							{
								for (int j = 0; j < size; j++)
								{
									testPatternSquare[i][j] = rotatedPatternSquare[i][j];
								}
							}

						}

				}
					 
			}

				if (equal != true)
					cout << "Pattern " << count << " was improperly transformed." << endl;
		}

	}//end while to read input

	
	return 0;
}



void verticalRef(vector<vector<char> > &reflectedPatternSquare, vector<vector<char> > &patternSquare, int size)
{ 
	int sizeCopy = size;
	//vertically reflect array
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			reflectedPatternSquare[sizeCopy - 1][j] = patternSquare[i][j];
			
		}
		sizeCopy--;
	}
}

bool equalArray(vector<vector<char> > &patternSquare, vector<vector<char> > &patternSquare2, int size)
{
	bool isEqual = true;


		//read in the square patterns into their appropriate arrays
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (patternSquare[i][j] != patternSquare2[i][j])
				{
					isEqual = false;
				}
			}
		}

	return isEqual;
}

void rotateSquare(vector<vector<char> > &patternSquare, vector<vector<char> > &rotatedPatternSquare,int size)
{
	int sizeCopy = size;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			rotatedPatternSquare[j][(sizeCopy - 1)] = patternSquare[i][j];

		}
		sizeCopy--;
	}

}