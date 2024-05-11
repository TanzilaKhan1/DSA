#include <bits/stdc++.h>
using namespace std;

struct bst
{
    struct node
    {
        node *left;
        node *right;
        node *parent;
        int height;
        int val;
    };
    node *root = NULL;

    node *newNode(int val)
    {
        node *p = new node();
        p->val = val;
        p->left = NULL;
        p->right = NULL;
        p->height = 1; // initially  added at leaf
        return (p);
    }

    int height(node *p)
    {
        if (p == NULL)
            return 0;
        return p->height;
    }

    int get_Balance_Factor(node *p)
    {
        if (p == NULL)
            return 0;
        return height(p->left) - height(p->right);
    }

    int max(int a, int b)
    {
        return (a >= b) ? a : b;
    }

    void input(int x)
    {
        node *inp = newNode(x);
        inp->parent = NULL;

        if (!root)
        {
            root = inp;
        }
        else
        {
            insert(root, inp);
        }
    }

    node *leftRotate(node *x)
    {
        node *y = x->right;
        node *T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        x->height = max(height(x->left),
                        height(x->right)) +
                    1;
        y->height = max(height(y->left),
                        height(y->right)) +
                    1;

        // Return new root
        return y;
    }

    node *rightRotate(node *y)
    {
        node *x = y->left;
        node *T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        y->height = max(height(y->left),
                        height(y->right)) +
                    1;
        x->height = max(height(x->left),
                        height(x->right)) +
                    1;

        // Return new root
        return x;
    }

    node *insert(node *par, node *inp)
    {
        if (par == NULL)
            return inp;
        if (par->val >= inp->val && par->left == NULL)
        {
            par->left = inp;
            inp->parent = par;
            // return;
        }
        else if (par->val < inp->val && par->right == NULL)
        {
            par->right = inp;
            inp->parent = par;
            // return;
        }
        else if (par->val >= inp->val)
        {
            insert(par->left, inp);
        }
        else
        {
            insert(par->right, inp);
        }

        par->height = 1 + max(height(par->left),
                              height(par->right));
        int balance = get_Balance_Factor(par);

        // Left Left Case
        if (balance > 1 && inp->val < par->left->val)
            return rightRotate(par);

        // Right Right Case
        if (balance < -1 && inp->val > par->right->val)
            return leftRotate(par);

        // Left Right Case
        if (balance > 1 && inp->val > par->left->val)
        {
            par->left = leftRotate(par->left);
            return rightRotate(par);
        }

        // Right Left Case
        if (balance < -1 && inp->val < par->right->val)
        {
            par->right = rightRotate(par->right);
            return leftRotate(par);
        }

        return par;
    }

    node *minValueNode(node *n)
    {
        while (n->left != nullptr)
        {
            n = n->left;
        }
        return n;
    }

    node *maxValueNode(node *n)
    {
        while (n->right != nullptr)
        {
            n = n->right;
        }
        return n;
    }

    node *delete_node(node *p, int x)
    { // without parent node
        if (p == nullptr)
            return nullptr;

        if (x < p->val)
        {
            p->left = delete_node(p->left, x);
        }
        else if (x > p->val)
        {
            p->right = delete_node(p->right, x);
        }
        else
        {
            if (p->left == nullptr)
            {
                node *temp = p->right;
                delete p;
                p = temp;
                // return temp;
            }
            else if (p->right == nullptr)
            {
                node *temp = p->left;
                delete p;
                p = temp;
                // return temp;
            }
            node *temp = maxValueNode(p->left);
            p->val = temp->val;
            p->left = delete_node(p->right, temp->val);
        }
        // return p;

        if (p == NULL)
            return p;

        p->height = 1 + max(height(p->left),
                            height(p->right));
        int balanceFactor = get_Balance_Factor(p);
        if (balanceFactor > 1)
        {
            if (get_Balance_Factor(p->left) >= 0)
            {
                return rightRotate(p);
            }
            else
            {
                p->left = leftRotate(p->left);
                return rightRotate(p);
            }
        }
        if (balanceFactor < -1)
        {
            if (get_Balance_Factor(p->right) <= 0)
            {
                return leftRotate(p);
            }
            else
            {
                p->right = rightRotate(p->right);
                return leftRotate(p);
            }
        }
        return p;
    }

    void print_Tree(node *root, string indent, bool last)
    {
        if (root != nullptr)
        {
            cout << indent;
            if (last)
            {
                cout << "R----";
                indent += "   ";
            }
            else
            {
                cout << "L----";
                indent += "|  ";
            }
            cout << root->val << endl;
            print_Tree(root->left, indent, false);
            print_Tree(root->right, indent, true);
        }
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
   
    bst1.root= delete_node(bst1.root, 13);
    cout << "After deleting " << endl;
    print_Tree(bst1.root, "", true);
}