#include <iostream>
#include <string>
#include <iomanip>


using namespace std;


#define endl '\n'

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	double shortHR = (1.0 / 12.0);  //points per long hand movement
	double longHR = 6; // one point = 6 degreas
	string clockTime;
	string hourh, minuteh;
	double hourP, inbetP;
	double angle;

	cin >> clockTime;
	while (clockTime != "0:00")
	{
		if (clockTime[1] != ':')
		{
			hourh = clockTime.substr(0, 2);
			minuteh = clockTime.substr(3, 2);
		}
		else
		{
			hourh = clockTime.substr(0, 1);
			minuteh = clockTime.substr(2, 2);

		}

		if (stoi(hourh) != 0)
		{
			if (stoi(minuteh) <= 30)
			{
				hourP = stoi(hourh) * 5;
				inbetP = hourP - stoi(minuteh);

				angle = (inbetP * longHR) + ((shortHR * stoi(minuteh)) * longHR);

		
			}
			else
			{
				hourP = stoi(hourh) * 5;
				inbetP = stoi(minuteh) - hourP;

				angle = (inbetP * longHR) - ((shortHR * stoi(minuteh)) * longHR);
			}

			if (angle < 0 && stoi(hourh) <= 12)
			{
				angle *= -1;
			}

			if (angle > 180)
			{
				angle = 360 - angle;
			}

			

			cout << fixed;
			cout << setprecision(3) << angle << endl;
		}
		cin >> clockTime;
	}
	return 0;
}