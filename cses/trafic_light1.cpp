#include <bits/stdc++.h>
using namespace std;

int main()
{
    int l, n;

    //cin >> l >> n;
    scanf("%d %d", &l, &n);

    set <int>s;
    multiset<int> m;

    s.insert(0);
    s.insert(l);
    m.insert(l);

    for(int i = 0; i < n; i++)
    {
        int a;
        //cin >> a;
        scanf("%d", &a);

        s.insert(a);

        auto it = s.find(a);
        auto c = prev(it);
        auto d = next(it);

        m.erase(m.find(*d - *c));
        m.insert(a - *c);
        m.insert(*d - a);

        auto j = m.rbegin();
        //cout << *j << " ";
        printf("%d ", *j);
    }

    return 0;
}