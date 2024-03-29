#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isPalindrome(const string &s, int start, int end) {
    while (start < end) {
        if (s[start++] != s[end--]) return false;
    }
    return true;
}

void backtrack(const string &s, int start, vector<string>& path, vector<vector<string>>& result) {
    if (start == s.length()) {
        result.push_back(path);
        return;
    }
    for (int end = start; end < s.length(); end++) {
        if (isPalindrome(s, start, end)) {
            path.push_back(s.substr(start, end - start + 1));
            backtrack(s, end + 1, path, result);
            path.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> result;
    vector<string> path;
    backtrack(s, 0, path, result);
    return result;
}

int main() {
    string s = "aab";
    vector<vector<string>> partitions = partition(s);
    for (const auto &p : partitions) {
        for (const auto &str : p) {
            cout << str << " ";
        }
        cout << endl;
    }
    return 0;
}







#include <bits/stdc++.h>
using namespace std;

bool checkPalindrome(string String, int i, int j)
{
    while (i < j)
    {
        if (String[i] == String[j])
        {
            i++;
            j--;
        }
        else
        {
            return false;
        }
    }
    return true;
}

int minPalPartion(string String, int i, int j)
{
    if (i >= j || checkPalindrome(String, i, j)){
        
        return 0;
    }
    int ans = INT_MAX, count;
    for (int k = i; k < j; k++)
    {
        count = minPalPartion(String, i, k) + minPalPartion(String, k + 1, j) + 1;
        ans = min(ans, count);
    }
    return ans;
}

int main()
{
    string str = "abb";
    int ans=minPalPartion(str, 0, str.length() - 1);
    cout<< "Min cuts needed for Pal-Part is " << ans << endl;
    return 0;
}
