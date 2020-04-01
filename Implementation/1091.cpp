#include <iostream>
#include <vector>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int N;
	vector<int> P;
	vector<int> S;
	vector<int> order;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int tmp;
		cin >> tmp;
		P.push_back(tmp);
	}
	for (int i = 0; i < N; ++i)
	{
		int tmp;
		cin >> tmp;
		S.push_back(tmp);
	}
	for (int i = 0; i < N; ++i)
    {
        order.push_back(i);
    }
    vector<int> original(order);
    int cnt = 0;
    while (1)
    {
        bool check = true;
        for (int i = 0; i < N; ++i)
        {
            if (cnt > 0 && original[i] != order[i])
            {
                check = false;
                break;
            }
        }
        if (cnt > 0 && check == true)
        {
            cout << -1;
            break;
        }
        bool check2 = true;
        for (int i = 0; i < N; ++i)
        {
            if (P[order[i]] != i % 3)
            {
                check2 = false;
                break;
            }
            if (check2 == false)
              break;
        }
        if (check2 == true)
        {
            cout << cnt;
            break;
        }
        else if (check2 == false)
        {
            vector<int> tmp(N, 0);
            for (int i = 0; i < N; ++i)
            {
                tmp[S[i]] = order[i];
            }
            for (int i = 0; i < N; ++i)
            {
                order[i] = tmp[i];
            }
            ++cnt;
        }
    }
    return 0;
}