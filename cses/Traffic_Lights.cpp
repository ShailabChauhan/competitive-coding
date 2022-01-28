#include <bits/stdc++.h>
using namespace std;

int max_difference(set<int> s)
{
    int max = 0;
    auto j = s.begin();
    j++;
    for(auto i = j; i != s.end(); i++)
    {
        auto k = i;
        k--;
        if(*i - *k > max)
        {
            max = *i - *k;
        }
    }
    return max;
}

int main()
{
    int l, n;
    cin >> l >> n;

    set <int > s;

    s.insert(0);
    s.insert(l);

    for(auto i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        s.insert(a);
        cout << max_difference(s) << " ";
    }

    return 0;
}