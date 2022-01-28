#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long int sum = 0, l = 0, r = 0, sum_max = 0, r_max;

    //vector < int > v;

    int a;
    cin >> a;
    sum = a;
    sum_max = a;
    //v.push_back(a);
    for(int i = 1; i < n; i++)
    {
        cin >> a;
        if(sum <= 0 && sum <= a)
        {
            l = i, r = i;
            sum = a;
        }
        else if(sum <= 0 && a >= 0)
        {
            l = i;
            sum = a;
            r = i;

            if(sum > sum_max)
            {
                sum_max = sum;
                r_max = r;
            }
        }
        else if(sum > 0 && a >= 0)
        {
            sum = sum + a;
            r = i;
            if(sum > sum_max)
            {
                sum_max = sum;
                r_max = r;
            }
        }
        else if(sum > 0 && a< 0)
        {
            sum = sum + a;
            r = i;
        }
    }

    cout << sum_max << endl;

    return 0;

}