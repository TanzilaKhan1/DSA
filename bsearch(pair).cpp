//25
//25
//25

#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n, m;
    scanf("%d", &n);
    pair<int, int> input[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&input[i].first);
        input[i].second = i;
    }
    sort(input, input + n);


    scanf("%d", &m);
    int query, ans;
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &query);


        int start=0,end=n,mid;

        while (1)
        {
            if (start >= end)
            {
                ans=-1;
                break;
            }
    
            mid = (start + end) / 2;
            if (input[mid].first == query)
            {
               
                ans= input[mid].second;
                //ans=mid;
                break;
            }
            if (input[mid].first > query)
            {
                end = mid;
                continue;
            
            }
            if (input[mid].first < query)
            {
                start = mid+1;
                continue;
              
            }
        }
    
        printf("%d\n",ans); 
    }

    return 0;
}