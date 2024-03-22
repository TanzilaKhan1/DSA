#include <bits/stdc++.h>
using namespace std;

void permutations(string a, int start, int end)
{   
    if (start == end){
        cout << a << endl;
        return;}
    else
    {       
        for (int i = start; i <= end; i++)
        {
            swap(a[start], a[i]);
            permute(a, start + 1, end);
            swap(a[start], a[i]);
        }
    }
}

int main()
{
    string str = "ABCD";
    int n = str.size();
    permutations(str, 0, n - 1);
    return 0;
}
