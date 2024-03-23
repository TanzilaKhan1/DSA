#include <stdio.h>
#include <string.h>
int main()
{
    char a[1001];
    scanf("%[^\n]s", a);
    int count = 0, alp = 0, j = 0;
    while (a[j] != '\0')
    {
        count++;
        if (a[j] != ' ')
        {
            alp++;
        }
        j++;
    }
    int b[26], n, temp = 0;
    for (int k = 0; k < 26; k++)
    {
        b[k] = 0;
    }
    for (int i = 0; i < count; i++)
    {
        if (a[i] >= 'A' && a[i] <= 'Z')
        {
            a[i] += 32;
        }
        n = a[i] - 'a';
        b[n] = 1;
    }
    for (int m = 0; m < 26; m++)
    {

        if (b[m] == 0)
        {
            temp++;
            break;
        }
    }
    if (temp)
    {
        printf("not pangram\n");
    }
    else
    {
        printf("pangram\n");
    }
}
