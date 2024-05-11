//25
//25
// 25
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int upper = 1, lower = -1, n;
    scanf("%d", &n);
    int add, r, digit = 10000;
    upper = upper * digit;
    lower = lower * digit;
    add = abs(lower);
    r = abs(lower) + upper;

    short int arr[r + 1]={0};

    int ind, num;
    double number;
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &number);
        num = number * digit;
        ind = num + add;
        arr[ind] += 1;
    }

    for (ind = 0; ind < r + 1; ind++)
    {
        if (arr[ind] != 0)
        {
            num = ind - add;
            number = (double)num / digit;
            for (int i = 0; i < arr[ind]; i++)
            {
                int ans = number * digit;
                if (ans % 10 == 0)
                {
                    printf("%.3lf\n", number);
                }
                else if (ans % 100 == 0)
                {
                    printf("%.2lf\n", number);
                }
                else if (ans % 1000 == 0)
                {
                    printf("%.1lf\n", number);
                }
                else if (ans % 10000 == 0)
                {
                    printf("%.1lf\n", number);
                }
                else
                {
                    printf("%.4lf\n", number);
                }
            }
        }
    }
    return 0;
}