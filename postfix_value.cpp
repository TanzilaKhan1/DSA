#include <iostream>
#include <stack>
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

int evaluatePostfix(const string& postfix) {
    Stack s;

    for (char c : postfix) {
        if (isdigit(c)) {  
            s.push(c - '0');  
        } else {  
            int operand2 = s.pop();
            int operand1 = s.pop();
            switch (c) {
                case '+':
                    s.push(operand1 + operand2);
                    break;
                case '-':
                    s.push(operand1 - operand2);
                    break;
                case '*':
                    s.push(operand1 * operand2);
                    break;
                case '/':
                    if (operand2 == 0) {
                        throw runtime_error("Division by zero");
                    }
                    s.push(operand1 / operand2);
                    break;
                default:
                    throw runtime_error("Invalid operator");
            }
        }
    }

    int result = s.pop();
    if (!s.isEmpty()) {
        throw runtime_error("Invalid postfix expression");
    }
    return result;
}

int main() {
    string postfix;
   
    getline(cin, postfix);


     int result = evaluatePostfix(postfix);
     cout << result << endl;
   

    return 0;
}
