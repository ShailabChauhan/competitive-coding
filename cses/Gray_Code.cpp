#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &v)
{
    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i];
    }
}
void decimal_to_binary(vector <int> &v, int num, int n)
{
    while(num)
    {
        v.push_back(num%2);
        num = num/2;
    }

    while(v.size() < n)
    {
        v.push_back(0);
    }
}

void decimal_to_gray_code(vector<int>&v, int num, int n)
{
    decimal_to_binary(v, num, n);

    vector<int> v1;

    v1.push_back(v[n - 1]);

    for(int i = n - 2; i >= 0; i--)
    {
        v1.push_back(v[i + 1]^v[i]);
    }

    v = v1;
}

int main()
{
    int n;
    cin >> n;

    int num = pow(2,n);

    for(int i = 0; i < num; i++)
    {
        vector<int> v;
        decimal_to_gray_code(v, i, n);
        print(v);
        cout << endl;
    }

    return 0;
}