#include <iostream>
#include <cstdlib>
using namespace std;

struct ll
{
    struct node
    {
        node *next;
        int value;
    };
    node *head=NULL;
    node *tail=NULL;

    void insert_last(int val)
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
        node *n= head;
        while(n){
            if(n->next==tail){
                tail=n;
                break;
            }
            n=n->next;
        }
        free(m);}
      return data;
    }

    void insert_first(int val)
    {     
         node *s= new node();
         s->value=val;
         if(head==NULL){
           s->next=NULL;
           head=s;
           tail=s;}
         else{
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
        free(m);}
      return data;
    }

    void delete_duplicate(int x){
       //delete the first x
       node *p=head;
       node *tmp;
       if(head->value==x){
          head = head->next;
          free(p);
          return;}
       while(p->next){
          if(p->next->value==x){
            tmp=p->next;
            p->next = p->next->next;
            free(tmp);
            break;}
          p=p->next;  
        }
    }

    void delete_x(int x){
       //delete all the x
       node *p=head;
       node *tmp;
       if(head->value==x){
          head = head->next;
          free(p);
          return;}
       while(p->next){  
          if(p->next->value==x){ 
            tmp=p->next;  
            if(p->next->next!=NULL){  
               p->next = p->next->next;}
            else{    
              p->next=NULL;
              tail=p;
              break;
            }
            free(tmp);
            }
          p=p->next;  
        }
    }


    void print()
    {
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
    linked_list.print();
    return 0;
}