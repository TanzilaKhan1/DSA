#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> pairs;
        int c, j,num=0;
        for (j = 0; j < n; j++)
        {
            cin >> c;
            int flag = 0;
            for (int k = 0; k < pairs.size(); k++)
            {
                if (pairs[k].second == c)
                {
                    pairs[k].first += 1;
                    flag = 1;
                }
            }
            if (flag == 0)
            {
                pairs.push_back(make_pair(1,c));
            }
        }

        sort(pairs.begin(), pairs.end());
        for (int i = 0; i < pairs.size(); i++)
        {
            {
                cout << pairs[i].second << " ";
            }
        }
        cout << endl;
    }

    return 0;
}