#include <bits/stdc++.h>

using namespace std;


int main()
{
    int n, x;
    cin >> n >> x;

    int a[n];

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int count[x + 1];

    count[0] = 0;

    for(int i = 1; i <=x; i++)
    {
        count[i] = x + 1;
    }

    cout << minimum(n, j, a, count);

    return 0;
}