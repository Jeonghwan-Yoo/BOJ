#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Student
{
    int korean, english, math;
    string name;
    friend bool operator<(Student const &a, Student const &b)
    {
        if (a.korean != b.korean)
            return a.korean > b.korean;
        else if (a.english != b.english)
            return a.english < b.english;
        else if (a.math != b.math)
            return a.math > b.math;
        return a.name < b.name;
    }
};

vector<Student> student;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    student.resize(N);
    for (int i = 0; i < N; ++i)
        cin >> student[i].name >> student[i].korean >> student[i].english >> student[i].math;

    sort(student.begin(), student.end());
    for (int i = 0; i < (int)student.size(); ++i)
        cout << student[i].name << '\n';

    return 0;
}