// #include<bits/stdc++.h>
// using namespace std;
 
// void makeSubString(char str[], int len) 
// {
//     for (int i = 1; i <= len; i++) 
//     {    
//         for (int j = 0; j <= len - i; j++) 
//         {
//             int m = j + i - 1;            
//             for (int k = j; k <= m; k++) 
//                 cout << str[k]; 
//             cout << endl;
//         }
//     }
// }
 
// int main() 
// {
//     char str[] = "abcd";
//     makeSubString(str, strlen(str));
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

void solve(string input, string output)
{
    if (input.length() == 0)
    {
        cout << output<<endl;
        // cout <<output[0];
        // for (int i = 1; i < output.length(); i++)
        // {
        //     cout <<" " << output[i];
        // }
        // cout <<endl;
        return;
    }
    string op1 = output;
    string op2 = output;
    op1.push_back(input[0]);
    input.erase(input.begin() + 0);
    solve(input, op1);
    solve(input, op2);
}

int main()
{
    string ip = "abc";
    string op = "";
    solve(ip, op);
    // cout << "Hello";

    return 0;
}
