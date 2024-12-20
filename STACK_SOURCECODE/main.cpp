#include <iostream>
#include <string>
using namespace std;

const int NMAX = 15;

struct Stack {
    char info[NMAX];
    int top;
};

// Initialize stack by setting top to -1
void initStack(Stack &s) {
    s.top = -1;
}

// Check if stack is empty
bool isEmpty(const Stack &s) {
    return s.top == -1;
}

// Check if stack is full
bool isFull(const Stack &s) {
    return s.top == NMAX - 1;
}

// Push an element to the stack
void push(Stack &s, char data) {
    if (!isFull(s)) {
        s.top++;
        s.info[s.top] = data;
    } else {
        cout << "Stack is full!" << endl;
    }
}

// Pop an element from the stack
char pop(Stack &s) {
    if (!isEmpty(s)) {
        char data = s.info[s.top];
        s.top--;
        return data;
    } else {
        cout << "Stack is empty!" << endl;
        return '\0';
    }
}

// Procedure to sort stack in ascending order using a temporary stack
void sortAscending(Stack &s) {
    Stack tempStack;
    initStack(tempStack);

    while (!isEmpty(s)) {
        char temp = pop(s);

        // Move elements from tempStack to s if they are greater than temp
        while (!isEmpty(tempStack) && tempStack.info[tempStack.top] > temp) {
            push(s, pop(tempStack));
        }

        // Place temp in the correct position in tempStack
        push(tempStack, temp);
    }

    // Move sorted elements back to the original stack
    while (!isEmpty(tempStack)) {
        push(s, pop(tempStack));
    }
}

// Procedure to sort stack in descending order using a temporary stack
void sortDescending(Stack &s) {
    Stack tempStack;
    initStack(tempStack);

    while (!isEmpty(s)) {
        char temp = pop(s);

        // Move elements from tempStack to s if they are less than temp
        while (!isEmpty(tempStack) && tempStack.info[tempStack.top] < temp) {
            push(s, pop(tempStack));
        }

        // Place temp in the correct position in tempStack
        push(tempStack, temp);
    }

    // Move sorted elements back to the original stack
    while (!isEmpty(tempStack)) {
        push(s, pop(tempStack));
    }
}

// Convert a string to stack by pushing each character
void stringToStack(const string &str, Stack &s) {
    initStack(s);
    for (char ch : str) {
        if (!isFull(s)) {
            push(s, ch);
        } else {
            cout << "Stack overflow, cannot push more elements." << endl;
            break;
        }
    }
}

// Display elements of stack for testing
void displayStack(const Stack &s) {
    for (int i = 0; i <= s.top; i++) {
        cout << s.info[i] << ' ';
    }
    cout << endl;
}

// Test functions
int main() {
    Stack s;

    push(s, 'A');
    push(s, 'C');
    push(s, 'B');
    push(s, 'D');
    displayStack(s);

    pop(s);
    displayStack(s);

    sortAscending(s);
    cout << "Ascending sorted stack: ";
    displayStack(s);

    sortDescending(s);
    cout << "Descending sorted stack: ";
    displayStack(s);

    string str = "helloworld";
    stringToStack(str, s);
    cout << "Original stack: ";
    displayStack(s);

    return 0;
}
