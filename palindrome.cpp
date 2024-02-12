#include <iostream>
#include <cstdlib>
#include <cstring>

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
};

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
};

int main(){
    string str;
    cin>>str;
    int len,left,right;
    len= str.length();

    if(len%2==0){
        right=(len/2);
        left=right-1;
    }
    else{
        right=(len+1)/2;
        left=right-2;
    }

    Stack st;
    Queue qu;
    for (int i = 0; i <= left; i++)
    {
        st.push(str[i]);
    }
    for (int j = right; j < len; j++)
    {
        qu.enqueue(str[j]);
    }

    int st_char,qu_char,flag=1;
    for (int i = 0; i <= left; i++)
    {
        st_char=st.pop();
        qu_char=qu.dequeue();
        if(st_char!=qu_char){
            flag=0;
            break;
        }
    }
    
    if(flag==1){
        printf("Palindrome \n");
    }
    else{
        printf("Not a Palindrome \n");
    }

    return 0;
}
