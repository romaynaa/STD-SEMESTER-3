#ifndef TREE02_H_INCLUDED
#define TREE02_H_INCLUDED
#include <iostream>
using namespace std;

typedef int infotype;
typedef struct elmNode *adrNode;
struct elmNode{
    infotype info;
    adrNode left;
    adrNode right;
};
typedef adrNode BinTree;
BinTree root;

adrNode createNode(infotype x);
void insert_newNode(BinTree &R, infotype x);
void print_PreOrder(BinTree R);
void print_InOrder(BinTree R);
void print_PostOrder(BinTree R);
BinTree delete_Node(BinTree R, infotype x);
#endif // TREE02_H_INCLUDED
