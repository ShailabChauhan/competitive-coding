#include <bits/stdc++.h>

using namespace std;

int required(vector <pair < int , int > >&v, int start, int end, int num)
{
	int mid;
    int prev;

    while(start <= end)
    {
        mid = (start + end)/2;

        if(v[mid].first == num)
        {
            while(mid <= end && v[mid].first == num)
            {
                mid++;
            }

            return mid;
        }
        else if(v[mid].first > num)
        {
            prev = mid;
            start = mid + 1;
        }
        else if(v[mid].first < num)
        {
            end = mid - 1;
        }
    }

    return prev;
}

int main()
{
	int n;
	cin >> n;
	
	vector< pair<int, int> > v;
	
	for(int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}

	sort(v.begin(), v.end());

    int l = 0;

    for(int i = 0; i < n; i++)
    {
        if(required(v, 0, n - 1, v[i].second) > l)
        {
            l = required(v, 0, n - 1, v[i].second);
        }
    }

    cout << l << endl;

    return 0;
}