#include <bits/stdc++.h>
using namespace std;

int storing(int n, int* count)
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= 6; j++)
        {
            if(i -j >= 0)
            {
                count[i] = count[i] + count[i - j];
                count[i] = count[i]%1000000007;   
            }
        }
    }
    
    return count[n];
}

/*int max_way_possib(int n)
{
    if(n < 0)
    {
        return 0;
    }
    else if(n == 0)
    {
        return 1;
    }

    int result = 0;

    for(int i = 1; i <= 6; i++)
    {
        result = result + max_way_possib(n - i);
        result = result%1000000007;
    }

    return result;
}*/

int main()
{
    int n;
    cin >> n;
    int count[n + 1];
    count[0] = 1;
    
    for(int i = 1; i <= n; i++)
    {
        count[i] = 0;
    }

    cout << storing(n, count);

    return 0;
}