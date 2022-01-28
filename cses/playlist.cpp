#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector <int> v;

    for(int i = 0; i < n; i++)
    {
        int a; 
        cin >> a;
        v.push_back(a);
    }

    set <int> s;

    int num, i = 0, j = 0, size = 0, max = 1;

    while(j < n)
    {
        s.insert(v[j]);
        if(s.size() == size + 1)
        {
            size++;
        }
        else
        {
            while(v[i] != v[j] && i < j - 1)
            {
                i++;
            }
            i++;
        }

        if(j - i + 1 > max)
        {
            max = j - i + 1;
        }
        j++;
    }

    cout << max << endl;

    return 0;
}