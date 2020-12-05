#include <vector>

long long sum(std::vector<int> &a)
{
    long long ret = 0ll;

    int n = (int)a.size();
    for (int i = 0; i < n; ++i)
        ret += a[i];
    
    return ret;
}