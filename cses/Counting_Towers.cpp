#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    vector <vector<int>> v;

    vector <int> v1(8+1);

    for(int i = 0; i <= 1000000; i++)
    {
        v.push_back(v1);
    }

    for(int i = 1; i <= 8; i++)
    {
        v[1][i] = 1;
    }

    
    int mod = 1000000007;

    for(int i = 2; i <= 1000000; i++)
    {
        for(int j = 1; j <= 8; j++)
        {
            if(j == 1 || j == 3 || j == 7)
            {
                v[i][j] = (v[i][j] + v[i - 1][1])%mod;
                v[i][j] = (v[i][j] + v[i - 1][3])%mod;
                v[i][j] = (v[i][j] + v[i - 1][4])%mod;
            }
            else
            {
                v[i][j] = (v[i][j] + v[i - 1][2])%mod;
                v[i][j] = (v[i][j] + v[i - 1][5])%mod;
                v[i][j] = (v[i][j] + v[i - 1][6])%mod;
                v[i][j] = (v[i][j] + v[i - 1][7])%mod;
                v[i][j] = (v[i][j] + v[i - 1][8])%mod;
            }
        }
    }

    while(t--)
    {
        int n;
        cin >> n;

        if(n == 1)
        {
            cout << 2 << endl;
        }
        else
        {
            int sum = 0;
            for(int i = 1; i <= 8; i++)
            {
                sum = (sum + v[n - 1][i])%mod;
            }
            
            cout << sum  << endl;
        }
    }

    return 0;
}