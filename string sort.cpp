#include <stdio.h>
char ind[100];
void compare(char x[], char y[], int w, int u, int v)
{
    for (int c = 0; c < 100; c++)
    {
        int temp;
        if (x[c] == '\0')
        {
            break;
        }
        if (y[c] == '\0')
        {
            w = -1;
        }
        if (x[c] > y[c])
        {
            w = -1;
        }
        else if (x[c] < y[c])
        {
            break;
        }
        else
        {
            continue;
        }
        if (w = -1)
        {
            temp = ind[u];
            ind[u] = ind[v];
            ind[v] = temp;
            break;
        }
    }
}
int main()
{
    char str[100][100];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", str[i]);
    }
    int total = n, flag = 0;
    for (int j = 0; j < total; j++)
    {
        ind[j] = j;
    }
    for (int m = 0; m < total - 1; m++)
    {
        for (int k = m + 1; k < total; k++)
        {
            compare(str[m], str[k], flag, m, k);
        }
    }
    for (size_t i = 0; i < total; i++)
    {
        printf("%d ", ind[i]);
    }
    int x = 15;
    printf("%d ", !x);
}