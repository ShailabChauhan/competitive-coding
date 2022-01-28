#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    long long int count = 0;
    int i = 1;

    while(i < n)
    {
        if(a[i] < a[i - 1])
        {
            count = count + a[i - 1] - a[i];
            a[i] = a[i - 1];
        }
        i++;
    }

    cout << count << endl;

    return 0;
}