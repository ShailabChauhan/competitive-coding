#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long int num = 5;
    long long int  sum = 0;

    while(n/num)
    {
        sum = sum + n/num;
        num = num*5;
    }

    cout << sum << endl;

    return 0;
}