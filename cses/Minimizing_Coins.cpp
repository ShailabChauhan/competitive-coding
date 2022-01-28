#include <bits/stdc++.h>

using namespace std;

int minimum(int x,int n, int*a, int*sum)
{
    int k, track;
    for(int i = 1; i <= x; i++)
    {
        track = 0;
        k = sum[i];
        for(int j = 0; j < n; j++)
        {
            if(i - a[j] >= 0 && k > sum[i - a[j]] + 1)
            {
                k = sum[i - a[j]] + 1;
                track = 1;
            }
        }
        

        if(track != 1)
        {
            sum[i] = x + 1;
        }
        else
        {
            sum[i] = k;
        }
    }

    return sum[x];
}

int main()
{
    int n, x;
    cin >> n >> x;

    int a[n];
    int sum[x+1];

    sum[0] = 0;
    for(int i = 1; i <= x; i++)
    {
        sum[i] = x + 1; 
    }

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int result = minimum(x, n, a, sum);
    
    if(result == x + 1)
    {
        cout <<"-1" << endl;
    }
    else
    {
        cout << result << endl;
    }
    
    /*for(int i = 0; i <=x; i++)
    {
        cout << sum[i] <<" ";
    }*/

    return 0;
}