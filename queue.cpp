#include <iostream>
#include <cstdlib>
using namespace std;

struct Queue
{
    struct node
    {
        node *next;
        int value;
    };
    node *head=NULL;
    node *tail=NULL;

    void enqueue(int val) //insert last
    {
         node *s= new node();
         s->value=val;
         s->next=NULL;
         if(head==NULL){
           head=s;
           tail=s;}
         else{
           tail->next=s;
           tail=s;}
    }
    

    int dequeue() //delete first
    {
      if(head==NULL){
        return -1; }
      int data=head->value;
      if(tail==head){
        free(head);
        head=NULL;
        tail=NULL;}
      else{
        node *m= head;
        head=head->next;
        free(m);}
      return data;
    }
    
    void print()
    {
        printHelper(head);
        cout << '\n';
    }

    void printHelper(node *p)
    {
        if (p == NULL)
            return;
        
        printHelper(p->next);
        cout << p->value;
    }

    bool isEmpty() {
        return head == NULL;
    }
};