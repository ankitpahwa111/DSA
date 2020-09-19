#include <bits/stdc++.h>
using namespace std;
void changing(int a[], int size)
{
    for (int i = 0; i < size; i++)
        a[i] = a[i] + 1;
}

void change(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
        v[i] = v[i] + 1;
}

int main()
{
    int a[3] = {0, 1, 2};
    vector<int> v;
    for (int i = 0; i < 3; i++)
        v.push_back(i);
    changing(a, 3);
    change(v);
    for (int i = 0; i < 3; i++)
        cout << a[i] << " ";
    for (int i = 0; i < 3; i++)
        cout << v[i] << " ";
}