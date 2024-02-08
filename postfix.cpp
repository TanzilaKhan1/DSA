#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

struct stack
{
    struct node{
        node *next;
        char value;
    };

    node *head = NULL;

    bool isEmpty() {
        return head == NULL;
    }

    void push(char val){
        node *s = new node();
        s->value = val;
        s->next = head;
        head = s;
    }

    char peek(){
        if (head == NULL) return '\0';
        return head->value;
    }

    char pop(){
        if (head == NULL){
            return '\0';
        }

        node *temp = head;
        char ch = temp->value;
        head = head->next;
        delete temp;
        return ch;
    }

    void printReverse(){
        printReverseHelper(head);
        cout << endl;
    }

    void printReverseHelper(node *p){
        if (p == NULL)
            return;
        
        printReverseHelper(p->next);
        cout << p->value;
    }
};

int precedence(char a){
    if (a == '*' || a == '/'){
        return 2;
    }
    else if (a == '+' || a == '-'){
        return 1;
    }
    return 0;
}

int main()
{
    string s;
    cin >> s;
    int len = s.length();
    stack output;
    stack operators;
    for (int i = 0; i < len; i++){
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')){
            output.push(s[i]);
        }
        else{
            while (!operators.isEmpty() && precedence(s[i]) <= precedence(operators.peek())){
                output.push(operators.pop());
            }
            operators.push(s[i]);
        }
    }

    while (!operators.isEmpty()){
        output.push(operators.pop());
    }

    output.printReverse();
    return 0;
}