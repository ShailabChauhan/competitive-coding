#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a;
    cin >> n;

    set <int> s;

    for(int i = 0; i < n; i++)
    {
        cin >> a;

        s.insert(a);
    }

    cout << s.size();

    return 0;
}