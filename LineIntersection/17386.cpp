#include <iostream>
#include <algorithm>

using namespace std;

struct Point
{
    long long x, y;
};

bool OnLine(Point p1, Point p2, Point p3)
{
    return (p3.x <= max(p1.x, p2.x) && p3.x >= min(p1.x, p2.x) && p3.y <= max(p1.y, p2.y) && p3.y >= min(p1.y, p2.y));
}

int Orientation(Point p1, Point p2, Point p3)
{
    long long val = (p2.y - p1.y) * (p3.x - p2.x) - (p3.y - p2.y) * (p2.x - p1.x);
    if (val > 0)
        val = 1;
    else if (val < 0)
        val = -1;
    return val;
}

bool IsIntersection(Point p1, Point p2, Point q1, Point q2)
{
    int o1 = Orientation(p1, p2, q1);
    int o2 = Orientation(p1, p2, q2);
    int o3 = Orientation(q1, q2, p1);
    int o4 = Orientation(q1, q2, p2);
    if (o1 != o2 && o3 != o4)
        return true;
    if (o1 == 0 && OnLine(p1, p2, q1) == true)
        return true;
    if (o2 == 0 && OnLine(p1, p2, q2) == true)
        return true;
    if (o3 == 0 && OnLine(q1, q2, p1) == true)
        return true;
    if (o3 == 0 && OnLine(q1, q2, p2) == true)
        return true;
    return false;
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Point p1, p2, q1, q2;
    cin >> p1.x >> p1.y >> p2.x >> p2.y >> q1.x >> q1.y >> q2.x >> q2.y;
    cout << IsIntersection(p1, p2, q1, q2);

    return 0;
}