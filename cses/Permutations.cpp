#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    if(n == 1)
    {
        cout << "1";
    }
    else if(n == 2 || n == 3)
    {
        cout << "NO SOLUTION";
    }
    else
    {
        int i = n - 1;
        while(i > 0)
        {
            cout << i << " ";
            i = i - 2;
        }

        i = n;
        while(i > 0)
        {
            cout << i << " ";
            i = i - 2;
        }
    }

    return 0;
}