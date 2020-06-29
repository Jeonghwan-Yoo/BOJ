#include <iostream>
#include <map>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    map<int, int> hash;
    int N, M, K;
    cin >> N >> M >> K;
    int key, value;
    for (int i = 0; i < N; ++i)
    {
        cin >> key >> value;
        hash[key] = value;
    }
    int type;
    for (int i = 0; i < M; ++i)
    {
        cin >> type;
        switch (type)
        {
            case 1:
            {
                cin >> key >> value;
                hash[key] = value;
                break;
            }
            case 2:
            {
                cin >> key >> value;
                auto left = hash.lower_bound(key);
                auto right = hash.upper_bound(key);
                if (left != right)
                    left->second = value;
                else
                {
                    if (left == hash.begin())
                    {
                        if (right->first - key <= K)
                            right->second = value;
                    }
                    else if (right == hash.end())
                    {
                        --left;
                        if (key - left->first <= K)
                            left->second = value;
                    }
                    else
                    {
                        --left;
                        if (key - left->first > K && right->first - key > K)
                            break;
                        else if (right->first - key > K)
                            left->second = value;
                        else if (key - left->first > K)
                            right->second = value;
                        else if (key - left->first < right->first - key)
                            left->second = value;
                        else if (key - left->first > right->first - key)
                            right->second = value;
                    }
                }
                break;
            }
            case 3:
            {
                cin >> key;
                auto left = hash.lower_bound(key);
                auto right = hash.upper_bound(key);
                if (left != right)
                    cout << left->second << '\n';
                else
                {
                    if (left == hash.begin())
                    {
                        if (right->first - key > K)
                            cout << -1 << '\n';
                        else
                            cout << right->second << '\n';
                    }
                    else if (right == hash.end())
                    {
                        --left;
                        if (key - left->first > K)
                            cout << -1 << '\n';
                        else
                            cout << left->second << '\n';
                    }
                    else
                    {
                        --left;
                        if (key - left->first > K && right->first - key > K)
                            cout << -1 << '\n';
                        else if (right->first - key > K)
                            cout << left->second << '\n';
                        else if (key - left->first > K)
                            cout << right->second << '\n';
                        else if (key - left->first < right->first - key)
                            cout << left->second << '\n';
                        else if (key - left->first > right->first - key)
                            cout << right->second << '\n';
                        else if (key - left->first == right->first - key)
                            cout << '?' << '\n';
                    }
                }
                break;
            }
        }
    }

    return 0;
}