#include <iostream>
#include <vector>

using namespace std;


int main()
{
	vector < vector<int> > rect;
	int N, entry, maxSum = 0, count, count2,  rt, ct, tempSum = 0;

	while (cin >> N)
	{
		count = 0;
		count2 = 0;
		maxSum = 0;
		tempSum = 0;
		//resizing
		rect.resize(N);
		for (int i = 0; i < N; i++)
		{
			rect[i].resize(N);
		}
		//Read data into 2d array
		for (int r = 0; r < N; r++)
		{
			for (int c = 0; c < N; c++)
			{
				cin >> entry;
				maxSum += entry;
				
				rect[r][c] =  entry;
			}

		
		}

		//search max sum for each entry as a top left pivot
		//count is the current size of the rectangle

		//count2 indicates the max a side a smaller rectangle within the sub rectangle of counts dimensions
		//will be and its used to explore all the different rectangles within the count X count rectangle
		for (int r = 0; r < N; r++)
		{
			for (int c = 0; c < N; c++)
			{
				count = 0;

				while (count < N)
				{
					
					for (count2 = 0; count2 <= count; count2++)
					{
						if (count == c && rect[r][c] > maxSum)
						{
							maxSum = rect[r][c];
						}
						else if (count2 >= count)
						{
							//calculate the maxSum of the whole rectangle i.e count is the current size of the rectangle
							tempSum = 0;
							for(int rv = r; rv <= count; rv++)
							{
								for (int cv = c; cv <= count; cv++)
								{
									tempSum += rect[rv][cv];
								}
							}

							if (tempSum > maxSum && c <= count && r <= count)
							{
								maxSum = tempSum;
							}
						}
						else
						{
							tempSum = 0;

							for (int rt = r; rt <= count2; rt++)
							{
								//sum across starting at c 
								for (int a = c; a <= count; a++)
								{
									tempSum += rect[rt][a];
								}
							}

							if (tempSum > maxSum && c <= count && r <= count2)
							{
								maxSum = tempSum;
							}

							tempSum = 0;
							for (int ct = c; ct <= count2; ct++)
							{
								//sum down start at c
								for (int d = r; d <= count; d++)
								{
									tempSum += rect[d][ct];
								}
							}

							if (tempSum > maxSum && r <= count && c <= count2)
							{
								maxSum = tempSum;
							}
						}
	
					}
					count++;
				}
			}
		}

		cout << maxSum << endl;
	}
}