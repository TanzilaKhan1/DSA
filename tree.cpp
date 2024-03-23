#include <bits/stdc++.h>
using namespace std;

struct binary_tree
{
    struct node
    {
        node *left;
        node *right;
        //node *parent;
        int val;
    };
    node *root = NULL;

    bool find(int x, node *m) {
        if (root == NULL){
            printf("Tree is empty\n");
            return false;
        }
        if(!m){
            return false;
        }
        if (m->val == x){
            return true;
        }      
        find(x, m->left);      
        find(x, m->right);
    }

};





int arr[1100000]={0};
void insert_left_child(int x,int par_ind){
    arr[2*par_ind+1]=x;
}
void insert_right_child(int x,int par_ind){
    arr[2*par_ind+2]=x;
}
int find_right_child(int par_ind){
    return arr[2*par_ind+2];
}
int find_left_child(int par_ind){
    return arr[2*par_ind+1];
}
int find_parent(int child_ind){
    return arr[(child_ind-1)/2];
}

void find(int x){

}

int main(){
    int level,n, val,x;
    scanf("%d %d", &level,&n);
    int len=pow(2,level);
    int a[len];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        a[i]=0;
    }
    


    return 0;
}