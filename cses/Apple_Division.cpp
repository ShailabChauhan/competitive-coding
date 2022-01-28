#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> v;

    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        v.push_back(a);
    }
    
    sort(v.rbegin(), v.rend());
    
    int a1 = 0, a2 = 0;

    int i = 0;
    while(i < n)
    {   if(a1 > a2)
        {
            a2 = a2 + v[i];
        }
        else
        {
            a1 = a1 + v[i];
        }
        i++;
    }

    if(a1 > a2)
    {
        cout << a1 - a2 << endl;
    }
    else
    {
        cout << a2 - a1 << endl;
    }

    return 0;
}