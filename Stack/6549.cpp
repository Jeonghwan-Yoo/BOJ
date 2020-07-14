#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int N;
int height[100'001];

long long MaxArea()
{
    stack<int> s;
    long long maxArea = 0ll;
    for (int i = 1; i <= N; ++i)
    {
        while (!s.empty() && height[s.top()] > height[i])
        {
            int minHeight = height[s.top()];
            s.pop();
            int width = s.empty() ? i - 1 : i - s.top() - 1;
            maxArea = max(maxArea, (long long)width * minHeight);
        }
        s.emplace(i);
    }
    while (!s.empty())
    {
        int minHeight = height[s.top()];
        s.pop();
        int width = s.empty() ? N : N - s.top();
        maxArea = max(maxArea, (long long)width * minHeight);
    }
    return maxArea;
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> N)
    {
        if (N == 0)
            break;
        
        for (int i = 1; i <= N; ++i)
            cin >> height[i];
        
        cout << MaxArea() << '\n';
    }
    return 0;
}