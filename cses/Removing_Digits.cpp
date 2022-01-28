#include <bits/stdc++.h>
using namespace std;

int arr(int num, int* a)
{
    int j = 0;
    while(num)
    {
        if(num%10 != 0)
        {
            a[j] = num%10;
            j++;
        }
        num = num/10;
    }

    return j;
}

int minimum(int x, int*a, int*sum)
{
    int k, track;

    for(int i = 1; i <= x; i++)
    {
        int n = arr(i, a);
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
    int n;
    cin >> n;
    int a[10];
    int sum[n+1];
    sum[0] = 0;

    for(int i = 1; i <= n; i++)
    {
        sum[i] = n + 1; 
    }

    cout << minimum(n, a, sum);

    return 0;
}