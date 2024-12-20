#include <iostream>
#include "S.h"
using namespace std;

int main()
{
    Stack S;

    createStack_103032330131(S);
    push_103032330131(S, 'G');
    push_103032330131(S, 'N');
    push_103032330131(S, 'U');
    push_103032330131(S, 'D');
    push_103032330131(S, 'N');
    push_103032330131(S, 'A');
    push_103032330131(S, 'B');
    push_103032330131(S, 'O');
    push_103032330131(S, 'L');
    push_103032330131(S, 'A');
    push_103032330131(S, 'H');
    printInfo_103032330131(S);

    pop_103032330131(S);
    pop_103032330131(S);
    pop_103032330131(S);
    pop_103032330131(S);
    printInfo_103032330131(S);

    return 0;
}
