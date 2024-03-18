#include <bits/stdc++.h>
using namespace std;

// Function to print permutations of string with duplicates allowed
// This function takes three parameters:
// 1. String
// 2. Starting index of the string
// 3. Ending index of the string.
void permute(string a, int start, int end)
{
    
    if (start == end)
        cout << a << endl;
    else
    {
        // Permutations made
        for (int i = start; i <= end; i++)
        {
            swap(a[start], a[end]);
            permute(a, start + 1, end);

            // backtrack
            swap(a[start], a[end]);
        }
    }
}

int main()
{
    string str = "ABC";
    int n = str.size();
    permute(str, 0, n - 1);
    return 0;
}