#include <cstdio>
#include <string>
#include <map>
#include <iostream>

using namespace std;

bool isLeap(int year)
{
    bool flag = false;
    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
    {
        flag = true;
    }
    return flag;
}

map<string, int> monthInfo;

int main()
{
    freopen("in.txt", "r", stdin);
    string in;
    getline(cin, in);
    int year = 0;
    char tmp[10];
    string month;
    int day = 0;
    int hour = 0;
    int minute = 0;
    sscanf(in.c_str(), "%s %d, %d %d:%d", tmp, &day, &year, &hour, &minute);
    monthInfo["January"] = 0;
    monthInfo["February"] = 31;
    monthInfo["March"] = 31 + 28;
    monthInfo["April"] = 31 + 28 + 31;
    monthInfo["May"] = 31 + 28 + 31 + 30;
    monthInfo["June"] = 31 + 28 + 31 + 30 + 31;
    monthInfo["July"] = 31 + 28 + 31 + 30 + 31 + 30;
    monthInfo["August"] = 31 + 28 + 31 + 30 + 31 + 30 + 31;
    monthInfo["September"] = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31;
    monthInfo["October"] = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30;
    monthInfo["November"] = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
    monthInfo["December"] = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
    month = tmp;
    bool leap = isLeap(year);
    int totalMin = 365 * 24 * 60;
    if (leap == true)
        totalMin += 24 * 60;
    int now = 0;
    now += monthInfo[month];
    if (leap == true && month != "January" && month != "February")
        now += 1;
    now += day - 1;
    now = now * 24 * 60;
    now += hour * 60;
    now += minute;
    printf("%.10lf", static_cast<double>(now) / totalMin * 100);

    return 0;
}