#include <iostream>
#include <cstdlib>
using namespace std;

struct ll
{
    struct node
    {
        node *next;
        node *prev;
        int value;
    };
    node *head=NULL;
    node *tail=NULL;

    void insert_first(int val)
    {     
         node *s= new node();
         s->value=val;
         s->prev=NULL;
         if(head==NULL){
           s->next=NULL;
           head=s;
           tail=s;}
         else{
           head->prev=s;
           s->next=head;
           head=s;}
    }
    
    int delete_first(){
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
        head->prev=NULL;
        free(m);}
      return data;
    }


    void insert_last(int val)
    {
         node *s= new node();
         s->value=val;
         s->next=NULL;
         if(head==NULL){
           s->prev=NULL;
           head=s;
           tail=s;}
         else{
           s->prev=tail;
           tail->next=s;
           tail=s;}
    }
    
    int delete_last(){
      if(head==NULL){
        return -1;}
      int data=tail->value;
      if(tail==head){
        free(head);
        head=NULL;
        tail=NULL;}
      else{
        node *m= tail;
        tail=tail->prev;
        tail->next=NULL;
        free(m);}
      return data;
    }

    
    void delete_duplicate(int x){
       //delete the first x
       node *p=head;
       node *tmp;

       while(p){
          if(p->value==x){
            tmp=p;
            p->next->prev = p->prev;
            p->prev->next = p->next;
            free(tmp);
            break;}
          p=p->next;  
        }
    }

    void delete_x(int x){
       //delete all the x
       node *p=head;
       node *tmp;
       node *flag;

       while(p){
          flag=p->next;
          if(p->value==x){
            tmp=p;
            p->next->prev = p->prev;
            p->prev->next = p->next;
            free(tmp);
            }
          p=flag; 
        }
    }


    void print(){
        node *p=head;
        while(p!=NULL){
           int data = p->value;
           printf("%d\n",data);
           p=p->next;
        }
    }
};


int main()
{
    int n, val;
    scanf("%d",&n);
    ll linked_list;
    for(int i=0;i<n;i++){
       scanf("%d",&val);
       linked_list.insert_last(val);
       }
    linked_list.delete_x(2);
    linked_list.delete_duplicate(2);
    linked_list.print();
    return 0;
}