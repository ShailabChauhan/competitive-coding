#include <bits/stdc++.h>
using namespace std;

int binary_search(vector<int> &v, int low, int high, int a)
{
    if( high == -1)
    {
        return -1;
    }

    int mid;

    if(a > v[high])
    {
        return high + 1;
    }

    while(low < high)
    {
        mid = (low+high)/2;
        if(v[mid] > a)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    if(v[low] <= a)
    {
        return low + 1;
    }
    else
    {
        return low;
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> v;
    int j = -1;

    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        int k = binary_search(v, 0, j, a);

        if(k == -1)
        {
            v.push_back(a);
            j++;
        }
        else if(j < k)
        {
            v.push_back(a);
            j++;
        }
        else
        {
            v[k] = a;
        }
    }

    cout << j + 1 << endl;

    return 0;
}