#include <iostream>
#include <string>

using namespace std;

const int month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

bool checkLeap(int year)
{
    bool leap = false;
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        leap = true;
    }
    return leap;
}


int main()
{
    freopen("in.txt", "r", stdin);
    int nowY, nowM, nowD;
    cin >> nowY >> nowM >> nowD;
    int dayY, dayM, dayD;
    cin >> dayY >> dayM >> dayD;
    if ((dayY - nowY > 1000) || (dayY - nowY == 1000 && dayM - nowM > 0) || (dayY - nowY == 1000 && dayM - nowM == 0 && dayD - nowD >= 0))
    {
        cout << "gg";
    }
    else
    {
        int nowTotal = 0;
        bool nowLeap = checkLeap(nowY);
        for (int i = 1; i < nowM; ++i)
        {
            nowTotal += month[i - 1];
            if (i == 2 && nowLeap)
                ++nowTotal;
        }
        for (int i = 1; i < nowD; ++i)
        {
            nowTotal += 1;
        }
        int dayTotal = 0;
        bool dayLeap = checkLeap(dayY);
        for (int i = nowY; i < dayY; ++i)
        {
            dayTotal += 365;
            if (checkLeap(i))
            {
                dayTotal += 1;
            }
        }
        for (int i = 1; i < dayM; ++i)
        {
            dayTotal += month[i - 1];
            if (i == 2 && dayLeap)
                ++dayTotal;
        }
        for (int i = 1; i < dayD; ++i)
        {
            dayTotal += 1;
        }
        cout << "D-" << dayTotal - nowTotal;
    }
    return 0;
}