#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    string s1, s2;
    cin >> s1 >> s2;
    if (s1.size() > s2.size())
        swap(s1, s2);
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    int carry = 0;
    string sum;
    for (int i = 0; i < s1.size(); ++i)
    {
        sum += to_string((s1[i] - '0' + s2[i] - '0' + carry) & 1);
        if (s1[i] - '0' + s2[i] - '0' + carry >= 2)
        {
            carry = 1;
        }
        else
        {
            carry = 0;    
        }
    }
    for (int i = s1.size(); i < s2.size(); ++i)
    {
        sum += to_string((s2[i] - '0' + carry) & 1);
        if (s2[i] - '0' + carry >= 2)
        {
            carry = 1;
        }
        else
        {
            carry = 0;
        }
    }
    if (carry == 1)
    {
        sum += to_string(carry);
    }
    for (int i = sum.size() - 1; i >= 0; --i)
    {
        if (sum[i] == '1')
        {
            break;
        }
        else
        {
            sum.pop_back();
        }
    }
    if (sum.size() == 0)
        sum += "0";
    reverse(sum.begin(), sum.end());
    cout << sum;
    return 0;
}