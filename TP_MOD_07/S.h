#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include <iostream>
using namespace std;

typedef char infotype;

struct Stack{
    infotype info[11];
    int Top;
};

void createStack_103032330131(Stack &S);
bool isEmpty_103032330131(Stack S);
bool isFull_103032330131(Stack S);
void push_103032330131(Stack &S, infotype x);
infotype pop_103032330131(Stack S);
void printInfo_103032330131(Stack S);


#endif // STACK_H_INCLUDED
