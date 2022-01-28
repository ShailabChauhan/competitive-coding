#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n;
    cin >> n;

    for(long long int i = 1; i <= n; i++)
    {
        long long int m = i*i;
        long long int s = (m*(m - 1))/2 - (i-1)*(i - 2)*4;
        cout << s << endl;
    }

    return 0;
}