#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector < int > v;
    long long int sum = 0;

    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        v.push_back(a);
        //sum = sum + a;
    }

    sort(v.begin(), v.end());
    sum = v[(n - 1)/2];
    long long int sum1 = 0;

    for(int i = 0; i < n; i++)
    {
        if(sum > v[i])
        {
            sum1 = sum1 + sum - v[i];
        }
        else
        {
            sum1 = sum1 + v[i] - sum;
        }
    }

    cout << sum1 << endl;

    return 0;
}