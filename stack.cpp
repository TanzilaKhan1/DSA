#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

struct Stack
{
    struct node
    {
        node *next;
        int value;
    };
    node *head = NULL;

    bool isEmpty() {
        return head == NULL;
    }

    void push(int val) //insert first
    {
        node *s = new node();
        s->value = val;
        s->next = head;
        head = s;
    }

    int peek() 
    {
        if (head == NULL) return '\0';
        return head->value;
    }

    int pop()  // delete first
    {
        if (head == NULL)
        {
            return '\0';
        }

        node *temp = head;
        int ch = temp->value;
        head = head->next;
        free(temp);
        return ch;
    }

    void printReverse()
    {
        printReverseHelper(head);
        cout << '\n';
    }

    void printReverseHelper(node *p)
    {
        if (p == NULL)
            return;
        
        printReverseHelper(p->next);
        cout << p->value;
    }
};
