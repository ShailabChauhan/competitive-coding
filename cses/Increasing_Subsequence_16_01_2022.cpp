#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> v(n + 1);
    vector<vector<int> >v1;
    vector<int> v2(n, 0);
    v1.push_back(v2);

    for(int i = 1; i <= n; i++)
    {
        cin >> v[i];
        v1.push_back(v2);
    }
    v1[0][0] = 1;

    for(int i = 1; i < n; i++)
    {
        v1[0][i] = 1;
    }

    int l = 0;
    for(int i = 1; i <= n; i++)
    {
       for(int j = 1; j <= n; j++)
        {
            v1[i][j] = (v[j] > v[i]) ? max(1 + v1[i - 1][i], v1[i - 1][j]) : v1[i - 1][j];

            if(v1[i][j] > l)
            {
                l = v1[i][j];
            }
        }
        
        cout << endl;
    }
    
    cout << l << endl;

    return 0;
}