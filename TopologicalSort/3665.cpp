#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n;
        vector<int> indegree(n + 1);
        vector<int> order(n + 1);
        int in;
        for (int i = 1; i <= n; ++i)
        {
            cin >> in;
            order[in] = indegree[in] = i;
        }
        
        int a, b;
        cin >> m;
        for (int i = 0; i < m; ++i)
        {
            cin >> a >> b;
            if (order[a] > order[b])
            {
                --indegree[a];
                ++indegree[b];
            }
            else
            {
                ++indegree[a];
                --indegree[b];
            }
        }

        order.assign(n + 1, 0);
        bool flag = true;
        for (int i = 1; i <= n; ++i)
        {
            if (order[indegree[i]])
            {
                flag = false;
                break;
            }
            order[indegree[i]] = i;
        }

        if (!flag)
            cout << "IMPOSSIBLE\n";
        else
        {
            for (int i = 1; i <= n; ++i)
                cout << order[i] << ' ';
            cout << '\n';
        }
    }

    return 0;
}

// #include <iostream>
// #include <vector>
// #include <queue>
// #include <algorithm>

// using namespace std;

// int main()
// {
//     freopen("in.txt", "r", stdin);
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n, m;
//         cin >> n;
//         vector<vector<int> > adj(n + 1, vector<int>(n + 1));
//         vector<int> order(n);
//         for (int i = 0; i < n; ++i)
//             cin >> order[i];
        
//         for (int i = 0; i < n; ++i)
//             for (int j = i + 1; j < n; ++j)
//                 adj[order[i]][order[j]] = 1;

//         int a, b;
//         cin >> m;
//         for (int i = 0; i < m; ++i)
//         {
//             cin >> a >> b;
//             swap(adj[a][b], adj[b][a]);
//         }

//         for (int i = 0; i < n; ++i)
//             for (int j = i + 1; j < n; ++j)
//                 if (adj[order[j]][order[i]])
//                     swap(order[j], order[i]); 
        
//         bool flag = true;
//         for (int i = 0; i < n; ++i)
//         {
//             for (int j = i + 1; j < n; ++j)
//             {
//                 if (adj[order[j]][order[i]])
//                 {
//                     flag = false;
//                     break;
//                 }
//             }
//         }

//         if (!flag)
//             cout << "IMPOSSIBLE\n";
//         else
//         {
//             for (int i = 0; i < (int)order.size(); ++i)
//                 cout << order[i] << ' ';
//             cout << '\n';
//         }
//     }

//     return 0;
// }

// #include <iostream>
// #include <vector>
// #include <queue>
// #include <algorithm>

// using namespace std;

// int main()
// {
//     freopen("in.txt", "r", stdin);
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n, m;
//         cin >> n;
//         vector<vector<int> > adj(n + 1, vector<int>(n + 1));
//         vector<int> indegree(n + 1);
//         vector<int> order(n);
//         for (int i = 0; i < n; ++i)
//             cin >> order[i];
        
//         for (int i = 0; i < n; ++i)
//         {
//             for (int j = i + 1; j < n; ++j)
//             {
//                 adj[order[i]][order[j]] = 1;
//                 ++indegree[order[j]];
//             }
//         }
//         int a, b;
//         cin >> m;
//         for (int i = 0; i < m; ++i)
//         {
//             cin >> a >> b;
//             if (adj[a][b])
//             {
//                 ++indegree[a];
//                 --indegree[b];
//             }
//             else
//             {
//                 ++indegree[b];
//                 --indegree[a];
//             }
//             swap(adj[a][b], adj[b][a]);
//         }

//         bool question = false;
//         order.clear();
//         queue<int> q;
//         for (int i = 1; i <= n; ++i)
//             if (indegree[i] == 0)
//                 q.emplace(i);

//         while (!q.empty())
//         {
//             if ((int)q.size() > 1)
//             {
//                 question = true;
//                 break;
//             }
//             int cur = q.front();
//             q.pop();
//             order.emplace_back(cur);
            
//             for (int i = 1; i <= n; ++i)
//             {
//                 if (adj[cur][i])
//                 {
//                     --indegree[i];
//                     if (indegree[i] == 0)
//                         q.emplace(i);
//                 }
//             }
//         }

//         if (question)
//             cout << "?\n";
//         else if ((int)order.size() < n)
//             cout << "IMPOSSIBLE\n";
//         else
//         {
//             for (int i = 0; i < (int)order.size(); ++i)
//                 cout << order[i] << ' ';
//             cout << '\n';
//         }
//     }

//     return 0;
// }