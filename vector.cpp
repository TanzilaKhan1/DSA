#include <stdio.h>
#include <stdlib.h>
struct vector{
    int* data;
    int index;
    int capacity;
    vector(int n){
        capacity=n;
        index=0;
       data=(int*)malloc(capacity*sizeof(int));     
    }
    void pushback(int value){
        if(index>=capacity){
          capacity++;  
          data=(int*)realloc(data,capacity*sizeof(int));
        }
        data[index]=value;
        index++;
        return;
    }
    int get(int index){
        if(index<=capacity){
           return data[index];}
        else{
           printf("Index not available\n"); 
           return -100000000;}
    }

    int find(int search,int capacity){
        for (int i = 0; i < capacity; i++)
        {
            if(data[i]==search){
                printf("Found at index %d\n",i);
                return i;
            }
        }
        printf("Not Found\n");
        return capacity;      
    }

    void erase(int value){
        int total=capacity;
        for (int i = 0; i < total; i++)
        {
           if(data[i]==value){
               total--;
               for (int j = i; j < total; j++)
               {
                   data[j]=data[j+1];
               }
           }
        }
        capacity=total;
        data=(int*)realloc(data,capacity*sizeof(int));
        return;
    }

    void duplicate_delete(){
        for (int i = 0; i < capacity; i++) {
            if(data[i]==-1000000){
                continue;
            }
            for (int j = i+1; j < capacity; j++){
                if(data[i]==data[j]){
                    data[j]=-1000000;}
            }
        }
        int ind=0;
        for (int k = 0; k < capacity; k++){
            if(data[k]!=-1000000){
                data[ind]=data[k];
                ind++;
            }
        }
        capacity=ind++;
        data=(int*)realloc(data,capacity*sizeof(int));
        return;  
    }

    void show(){
        for (int i = 0; i < capacity; i++)
        {
           printf("%d ",data[i]);
        }
        printf("\n");
        return;
    }

    void clear(){
        free(data);
        return;
    }
};

int main(){ 
   int n=4;
   struct vector v=vector(n);
   for (int i = 0; i < 10; i++)
   {    int a=0;
        scanf("%d",&a);
        v.pushback(a);
   } 
   
    v.erase(7);
   v.show();

   v.duplicate_delete();
   v.show();
   v.clear();
}
