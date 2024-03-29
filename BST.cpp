#include <bits/stdc++.h>
using namespace std;

struct bst
{
    struct node
    {
        node *left;
        node *right;
        node *parent;
        int val;
    };
    node *root = NULL;


    void input(int x)
    {
        node *inp = new node();
        inp->left = NULL;
        inp->right = NULL;
        inp->val = x;
        inp->parent = NULL;

        if (!root){
            root = inp;}
        else{
            insert(root, inp);}
    }

    void insert(node *par, node *inp){
        if (par->val >= inp->val && par->left == NULL){
            par->left = inp;
            inp->parent = par;
            return;
        }
        else if (par->val < inp->val && par->right == NULL){
            par->right = inp;
            inp->parent = par;
            return;
        }
        else if (par->val >= inp->val){
            insert(par->left, inp);}
        else{
            insert(par->right, inp);}
    }



    void preorder(node *m){
        if (root == NULL){
            printf("Tree is empty\n");
            return;
        }
        if (!m){
            return;}

        printf("%d ", m->val);
        preorder(m->left);
        preorder(m->right);
    }

    void inorder(node *m){
        if (root == NULL){
            printf("Tree is empty\n");
            return;
        }
        if (!m){
            return;}

        inorder(m->left);
        printf("%d ", m->val);
        inorder(m->right);
    }

    void postorder(node *m){
        if (root == NULL){
            printf("Tree is empty\n");
            return;
        }
        if (!m){
            return;}

        postorder(m->left);
        postorder(m->right);
        printf("%d ", m->val);
    }



    bool find(int x, node *m) {
        if (root == NULL){
            printf("Tree is empty\n");
            return false;}
        if (m->val == x){
            return true;}
        if (m->val > x && m->left == NULL){
            return false;}
        else if (m->val < x && m->right == NULL){
            return false;}
        else if (m->val >= x){
            find(x, m->left);}
        else{
            find(x, m->right);}
    }



    void change_in_child_add(node *cur_child, node *new_child){
        if (cur_child->val > cur_child->parent->val)
            cur_child->parent->right = new_child;
        else
            cur_child->parent->left = new_child;
        
    }

    node *minValueNode(node *n){
        while (n->left != nullptr)
        {
            n = n->left;
        }
        return n;
    }

    node *maxValueNode(node *n){
        while (n->right != nullptr)
        {
            n = n->right;
        }
        return n;
    }

    void deletes(node *p, int x){
        if (root == NULL){
            printf("Tree is empty\n");
            return;
        }
        if (!p){
            return;}

        if (x < p->val){
            deletes(p->left, x);
        }
        else if (x > p->val){
            deletes(p->right, x);
        }
        else{
            if (p->left == nullptr && p->right == nullptr){
                node *m=NULL;
                change_in_child_add(p,m);
                free(p);
                return;
            }
            else if (p->left == nullptr){
                change_in_child_add(p,p->right);
                p->right->parent = p->parent;
                free(p);
                return;
            }
            else if (p->right == nullptr){
                change_in_child_add(p,p->left);
                p->left->parent = p->parent;
                free(p);
                return;
            }
            else{
                node *temp = minValueNode(p->right);
                p->val = temp->val;
                node *m=NULL;
                change_in_child_add(temp,m);
                free(temp);
                return;
            }
        }
    }

    node *delete_node(node *p, int x) {// without parent node
        if (p == nullptr)
            return nullptr;
        
        if (x < p->val){
            p->left = delete_node(p->left, x);
        }
        else if (x > p->val){
            p->right = delete_node(p->right, x);
        }
        else{
            if (p->left == nullptr){
                node *temp = p->right;
                delete p;
                return temp;
            }
            else if (p->right == nullptr){
                node *temp = p->left;
                delete p;
                return temp;
            }
            node *temp = maxValueNode(p->left);
            p->val = temp->val;
            p->left = delete_node(p->right, temp->val);
        }
        return p;
    }


    int max_height(node *node)
    {
        if (node == nullptr)
            return 0;
        int hl = max_height(node->left);
        int hr = max_height(node->right);

        return 1 + max(hr, hl);
    }

    bool is_balanced(node *node)
    {
        return dfs_height(node) != -1;
    }

    int dfs_height(node *node)
    {
        if (node == nullptr)
            return 0;
        int left_h = dfs_height(node->left);
        if (left_h == -1)
            return -1;
        int right_h = dfs_height(node->right);
        if (right_h == -1)
            return -1;
        if (abs(right_h - left_h) > 1)
            return -1;

        return 1 + max(left_h, right_h);
    }

    int diameter(node *p,int *height){
        if (p == nullptr){
            *height=0;
            return 0;}

        int lh=0,rh=0;
        int ld=diameter(p->left,&lh);
        int rd=diameter(p->right,&rh);
        *height=max(lh,rh)+1;
        return max({lh+rh+1,ld,rd});

    }
};

int main()
{
    int n, val, x;
    scanf("%d", &n);
    bst bst1;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        bst1.input(val);
    }
    bst1.preorder(bst1.root);
    printf("\n");
    bst1.inorder(bst1.root);
    printf("\n");
    bst1.postorder(bst1.root);
    printf("\n");
    scanf("%d", &x);
    bool ans = bst1.find(x, bst1.root);
    if (ans)
    {
        printf("Found\n");
    }
    else
    {
        printf("Not Found\n");
    }

    bst1.deletes(bst1.root, 16);
    bst1.delete_node(bst1.root, 16);
    bst1.preorder(bst1.root);
    int h=0;
    int d=bst1.diameter(bst1.root,&h);
    cout<<d<<" "<<h<<endl;

    return 0;
}

