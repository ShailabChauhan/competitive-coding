#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int a[1001][1001];

ll path( vector <vector <char> > v, int n,  int i , int j)
{
    if(i < n && j < n)
    {
        if(i == n - 1 && j == n - 1)
        {
            return a[i][j];
        }
        else 
        {
            if(a[i + 1][j] == -1)
            {
                a[i + 1][j] = path(v, n, i + 1, j);
            }

            if(a[i][j + 1] == -1)
            {
                a[i][j + 1] = path(v, n, i + 1, j);
            }
            return (a[i + 1][j] + a[i][j + 1])%1000000007;
        }
    }
    else
    {
        return 0;
    }
    
}

int main()
{
    int n;
    cin >> n;

    vector<vector < char > > v;

    for(int i = 0; i <= 1000; i++)
    {
        for(int j = 0; j <= 1000; j++)
        {
            a[i][j] = -1;
        }
    }
    

    for(int i = 0; i < n; i++)
    {
        vector <char> v1;
        for(int j = 0; j < n; j++)
        {
            char c;
            cin >> c;
            v1.push_back(c);
        }

        v.push_back(v1);
    }

    if(v[n - 1][n - 1] == '*')
    {
        a[n - 1][n - 1] = 1;
    }
    else
    {
        a[n - 1][n - 1] = 0;
    }
    

    cout << path(v, n, 0, 0) << endl;

    return 0;
}