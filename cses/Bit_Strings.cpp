#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long int sum = 1;

    for(int i = 0; i < n; i++)
    {
        sum = (sum*2)%1000000007;
    }
    
    cout << sum << endl;

    return 0;
}