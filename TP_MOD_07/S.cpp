
#include <iostream>
#include "S.h"
using namespace std;


void createStack_103032330131(Stack &S){
    S.Top = 0;
}
bool isEmpty_103032330131(Stack S){
    if(S.Top == 0){
        return true;
    }else{
        return false;
    }
}
bool isFull_103032330131(Stack S){
    if(S.Top == 11){
        return true;
    }else{
        return false;
    }
}
void push_103032330131(Stack &S, infotype x){
    if(isFull_103032330131(S) == false){
        S.Top++;
        S.info[S.Top] = x;
    }else{
        cout << "Stack penuh" << endl;
    }
}
infotype pop_103032330131(Stack &S){
    infotype x;
    x = S.info[S.Top];
    S.Top--;
    return x;
}
void printInfo_103032330131(Stack S){
    for(int i = S.Top; i >= 0; i--){
        cout << S.info[i] << " ";
    }
    cout << endl;
}

