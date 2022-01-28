#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long int sum = 0, sum_max = 0;

    //vector < int > v;

    int a;
    cin >> a;
    sum = a;
    sum_max = a;
    for(int i = 1; i < n; i++)
    {
        cin >> a;
        
        if(sum + a < a)
        {
            sum = a;
        }
        else
        {
            sum = sum + a;
        }

        if(sum > sum_max)
        {
            sum_max = sum;
        }
    }

    cout << sum_max << endl;

    return 0;

}