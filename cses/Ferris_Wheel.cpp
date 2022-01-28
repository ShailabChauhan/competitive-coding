#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;

    vector <int> v;

    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        v.push_back(a);
    }

    sort(v.begin(), v.end());

    int i = 0, j = v.size() - 1;
    int count = 0;

    while(i <= j)
    {
        if(v[i] + v[j] <= x)
        {
            i++;
            j--;
        }
        else
        {
            j--;
        }

        count++;
    }

    cout << count << endl;

    return 0;
}