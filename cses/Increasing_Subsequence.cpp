#include <bits/stdc++.h>
using namespace std;

int max_length(vector <int> &v, vector<vector<int> >&v1,int n, int m)
{
    if(m == 0 || n < 0)
    {
        return 1;
    }

    if(v1[n][m] != -1)
    {
        return v1[n][m];
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j<= m; j++)
        {
            int s = 0, k = 0;

            if(v[j] > v[i])
            {
                k = 1 + max_length(v, v1, i - 1, i);
                if(s < k)
                {
                    s = k;
                }
            }

            k = max_length(v, v1, i - 1, i);
            if(s < k)
            {
                s = k;
            }

            v1[i][j] = s;
        }
        
    }
    return v1[n][m];
}

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    vector<vector<int> >v1;

    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
        vector<int> v2(n, -1);
        v1.push_back(v2);
    }
    v1[0][0] = 1;

    cout << max_length(v, v1, n - 1, n - 1) << endl;

    //max_length(v, v1, n - 1, n - 1);

    /*for(int i = 0; i < n; i++)
    {
        cout << v1[i] << " ";
    }*/

    return 0;
}