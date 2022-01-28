#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int a[n + 1][m + 1];

    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            a[i][j] = 0;
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            int s = 1000000000;

            if(i == j)
            {
                a[i][j] = 0;
            }
            else
            {
                for(int k = 1; k <= i/2; k++)
                {
                    if(s > 1+ a[i -k][j] + a[k][j])
                    {
                        s = 1 + a[i -k][j] + a[k][j];
                    }
                }

                for(int l = 1; l <= j/2; l++)
                {
                    if(s > 1 + a[i][j - l] + a[i][l])
                    {
                        s = 1 + a[i][j - l] + a[i][l];
                    }
                }

                a[i][j] = s;
            } 
        }
    }

    cout << a[n][m] << endl;

    return 0;
}