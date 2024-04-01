#include <iostream>
using namespace std;

class Stack {
public:
    int size = 0;
    int top = -1;
    char *items;
    
    Stack(int stackSize) {
        size = stackSize;
        items = new char[size];
    }
    
    void push(char item) {
        if (top == size - 1) {
            cout << "ERROR: Stack overflow, stack is full" << endl;
        } else {
            top++;
            items[top] = item;
        }
    }
    
    char pop() {
        char item = '\0'; 
        
        if (top == -1) {
            cout << "ERROR: Stack is empty" << endl;
        } else {
            item = items[top];
            top--;
        }
        
        return item;
    }
};

int main(int argc, char** argv) {
    Stack kantong1(5);
    kantong1.push('A');
    kantong1.push('B');
    kantong1.push('C');
    kantong1.push('D');
    kantong1.push('Z');
    kantong1.push('R');
    
    cout << kantong1.pop() << endl;
    cout << kantong1.pop() << endl;
    cout << kantong1.pop() << endl;
    cout << kantong1.pop() << endl;
    cout << kantong1.pop() << endl;
    cout << kantong1.pop() << endl;
    
    return 0;
}