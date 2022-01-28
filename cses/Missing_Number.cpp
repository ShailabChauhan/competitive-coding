#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a;
    cin >> n;
    vector <int> v;
    v.push_back(0);


    for(int i = 0; i < n - 1; i++)
    {
        cin >> a;
       v.push_back(a);
    }

    sort(v.begin(), v.end());
    int k = 0;

    for(int i = 1; i < n; i++)
    {
        if(v[i] != i)
        {
            cout << i;
            k = 1;
            break;
        }
    }
    
    if(k == 0)
    {
        cout << n;
    }

    return 0;
}