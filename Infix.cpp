#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* next;
};

class Stack {
public:
    Node* top;

    Stack() {
        top = nullptr;
    }

    void push(string value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    string pop() {
        if (isEmpty()) {
            return ""; 
        }
        string value = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return value;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}
string postfixToInfix(string postfix) {
    Stack stack;
    for (char c : postfix) {
        if (isalnum(c)) {  
            stack.push(string(1, c));  
        } else if (isOperator(c)) {
            string operand2 = stack.pop();
            string operand1 = stack.pop();
            string expression = "(" + operand1 + c + operand2 + ")";
            stack.push(expression);
        }
    }
    return stack.pop();  
}


int main() {
    string postfixExpression;
    cin>>postfixExpression;
    string infixExpression = postfixToInfix(postfixExpression);
    cout << infixExpression << '\n';
    return 0;
}