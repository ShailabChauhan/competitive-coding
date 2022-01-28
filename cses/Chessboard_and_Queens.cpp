#include <bits/stdc++.h>
using namespace std;

int main()
{
    char a[8][8];

    vector<pair<int, int>>v;

    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            cin >> a[i][j];
            if(a[i][j] == '*')
            {
                v.push_back({i,j});
            }
        }
    }

    vector<int> v1, v2;
    int count = 0;

    for(int i = 0; i < 8; i++)
    {
        v1.push_back(i);
    }

    v2 = v1;

    int k = 0;
    
    do
    {
        k = 0;

        for(int i = 0; i < v.size(); i++)
        {
            if(v1[v[i].first] == v[i].second)
            {
                k++;
                break;
            }
        }

        for(int i = 0; i < 8; i++)
        {
            for(int j = 0; j < 8; j++)
            {
                if( i != j && (v1[i] - v1[j] == i - j || v1[i] - v1[j] == j - i))
                {
                    k = 1;
                    break;
                }
            }

            if(k == 1)
            {
                break;
            }
        }

        if(k == 0)
        {
            count++;
        }

        next_permutation(v1.begin(), v1.end());
    }
    while(v2 != v1);
    
    cout << count << endl;

    return 0;
}