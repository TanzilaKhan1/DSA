#include <stdio.h>
#include <math.h>
int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        long long int l, r;
        scanf("%lld%lld", &l, &r);
        int count = 0;
        long long int a;
        a = sqrt(l);
       while(1)
        {
            long long int s;
            s = pow(a, 2);
            if (s > r)
            {
                break;
            }
            if (s >= l && s<=r)
            {
                count++;
            }
            a++;
        }
        printf("%d\n", count);
    }
    return 0;
}
