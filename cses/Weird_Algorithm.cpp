#include <bits/stdc++.h>
using namespace std;

void series(long long int n)
{
    cout << n <<" ";

    while(n != 1)
    {
        if(n%2 == 0)
        {
            n = n/2;
        }
        else
        {
            n = n*3 +1;
        }
        cout << n << " ";
    }
}

int main()
{
    long long int n;
    cin >> n;

    series(n);

    return 0;
}