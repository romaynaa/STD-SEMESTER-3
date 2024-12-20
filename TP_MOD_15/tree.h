#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED
#include <iostream>
using namespace std;

typedef int infotype;
typedef struct ElmNode *adrNode;
struct ElmNode{
    infotype info;
    adrNode left;
    adrNode right;
};
struct tree{
    adrNode root;
};

adrNode newNode_103032330131(infotype x);
adrNode findNode_103032330131(adrNode root, infotype x);
void insertNode_103032330131(adrNode &root, adrNode p);
void printPreOrder_103032330131(adrNode root);
void printDescendant_103032330131(adrNode root, infotype x);
int sumNode_103032330131(adrNode root);
int countLeaves_103032330131(adrNode root);
int heightTree_103032330131(adrNode root);
adrNode max_Node(adrNode &root);
void printAll(adrNode root);
adrNode delete_Node(adrNode &root, infotype x);
adrNode delete_All(adrNode root);

#endif // TREE_H_INCLUDED
