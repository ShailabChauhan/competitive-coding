#include <bits/stdc++.h>
using namespace std;

int minimum(int n,  int*sum)
{
    int m = n, a;
    vector< int > v;

    while(m)
    {
        a = m%10;
        m = m/10;
        if(a!= 0)
        {
            v.push_back(a);
        }
    }

    int k = v.size();

    sort(v.begin(), v.end());

    int b[k];
    b[0] = v[0];
    int j = 1;

    for(int i = 1; i < k; i++)
    {
        if(v[i - 1]!= v[i])
        {
            b[j] = v[i];
            j++;
        }
    }
    
    int k, track;
    for(int i = 1; i <= n; i++)
    {
        track = 0;
        k = sum[i];
        for(int j = 0; j < n; j++)
        {
            if(i - b[j] >= 0 && k > sum[i - b[j]] + 1)
            {
                k = sum[i - b[j]] + 1;
                track = 1;
            }
        }
        
 
        if(track != 1)
        {
            sum[i] = n + 1;
        }
        else
        {
            sum[i] = k;
        }
    }
 
    return sum[n];
}


int main()
{
    int n, a;
    cin >> n;
    int m = n;

    

    int count[n + 1];
    count[0] = 0;
    for(int i = 1; i < n + 1; i++)
    {
        count[i] = n + 1;
    }

    cout << minimum(n, j, b, count) << endl;

    return 0;
}