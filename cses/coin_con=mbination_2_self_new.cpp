#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int b[1001][1001];
ll max_way(int n, int x, vector<int> &v)
{
    if(x == 0)
    {
        return 1;
    }
    else if(x < 0)
    {
        return 0;
    }

    if(n - 1 > 0 )
    {
        if(b[n - 1][x] == -1)
        {
            b[n - 1][x] = max_way(n - 1, x, v);
        }
       
        if(b[n][x - v[n - 1]] == -1)
        {
            max_way(n, x - v[ n - 1], v);
        }

        return (b[n - 1][x] + (b[n][x - v[n - 1]]))%1000000007;
    }
    else if( n > 0)
    {
        if(b[n][x - v[n - 1]] == -1)
        {
            b[n][x - v[n - 1]] = max_way(n, x - v[ n - 1], v);
        }

        return b[n][x - v[n - 1]];
    }
    else
    {
        return 0;
    }
}


int main()
{
    int n, x;
    cin >> n >>x;

    vector<int> v;

    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        v.push_back(a);
    }

    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= x; j++)
        {
            if(j == 0)
            {
                b[i][j] = 1;
            }
            else
            {
                b[i][j] = -1;
            }  
        }
    }

    
    sort(v.begin(), v.end());

    cout << max_way(n, x, v);

    return 0;
}