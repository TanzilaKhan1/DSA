#include <bits/stdc++.h>
using namespace std;

int parent[500];
int ranks[500] = {0};
int sizes[500] = {0};

int find_set(int i)
{
    if (parent[i] == i)
    {
        return i;
    }
    else
    {
        int root = find_set(parent[i]);
        parent[i] = root;
        if (ranks[i] != 1)
        {
            ranks[i]--;
        }
        if (sizes[i] != 1)
        {
            sizes[i]--;
        }
        return root;
    }
}

int is_in_union(int x, int y)
{
    int root_x = find_set(x);
    int root_y = find_set(y);
    if (root_x == root_y)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

void union_set(int x, int y)
{

    int root_x = find_set(x); 
    int root_y = find_set(y); 
    if (root_x == root_y)
    {
        return;
    }

    if (ranks[root_x] > ranks[root_y])
    {
        parent[root_y] = root_x;
        sizes[root_x] += sizes[root_y];
    }
    else if (ranks[root_x] < ranks[root_y])
    {
        parent[root_x] = root_y;
        sizes[root_y] += sizes[root_x];
    }
    else
    {
        if (sizes[root_x] >= sizes[root_y])
        {
            parent[root_y] = root_x;
            ranks[root_x] += 1;
            sizes[root_x] += sizes[root_y];
        }
        else
        {
            parent[root_x] = root_y;
            ranks[root_y] += 1;
            sizes[root_y] += sizes[root_x];
        }
    }
    
}

int main()
{
    for (int i = 0; i < 10; i++)
    {
        parent[i] = i;
        sizes[i] += 1;
        ranks[i] += 1;
    }
 
    union_set(5, 7);
    union_set(1, 7);
    union_set(2, 9);
    union_set(1, 2);

    union_set(6, 3);
    union_set(4, 6);
    union_set(3, 8);

    //union_set(2, 4);
    
    for (int i = 0; i < 10; i++)
    {
        cout << parent[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << find_set(i) << " ";
    }
    cout << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << ranks[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << sizes[i] << " ";
    }
    cout << endl;

    return 0;
}