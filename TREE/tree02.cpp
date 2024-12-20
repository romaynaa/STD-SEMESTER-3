#include <iostream>
#include "tree02.h"
using namespace std;

adrNode createNode(infotype x){
    adrNode N = new elmNode;
    N->info = x;
    N->left = NULL;
    N->right = NULL;
    return N;
}
void insert_newNode(BinTree &R, infotype x){
    if(R == NULL){
        R = createNode(x);
    }else{
        if(x < R->info){
            insert_newNode(R->left, x);
        }else if(x > R->info){
            insert_newNode(R->right, x);
        }else{
            cout << "Duplicate" << endl;
        }
    }
}
adrNode find_Node(BinTree R, infotype x){
    if(R->info == x || R == NULL){
        return R;
    }else{
        if(x < R->info){
            return find_Node(R->left, x);
        }else{
            return find_Node(R->right, x);
        }
    }
}
void print_PreOrder(BinTree R){
    if(R != NULL){
        cout << R->info << " ";
        print_PreOrder(R->left);
        print_PreOrder(R->right);
    }
}
void print_InOrder(BinTree R){
    if(R != NULL){
        print_InOrder(R->left);
        cout << R->info << " ";
        print_InOrder(R->right);
    }
}
void print_PostOrder(BinTree R){
    if(R != NULL){
        print_PostOrder(R->left);
        print_PostOrder(R->right);
        cout << R->info << " ";
    }
}
adrNode max_Node(BinTree &R){
//    adrNode p;
//    p = root->left;
//    while(p->right != NULL){
//        p = p->right;
//    }
    adrNode p;
    p = R->left;
    while(p->right != NULL){
        p = p->right;
    }
}
adrNode min_Node(BinTree &R){
    adrNode p;
    p = R->right;
    while(p->left != NULL){
        p = p->left;
    }
}
BinTree delete_Node(BinTree R, infotype x){
    if(R == NULL){
        return R;
    }else if(x < R->info){
        delete_Node(R->left, x);
    }else if(x > R->info){
        delete_Node(R->right, x);
    }else{
        //delete leaf / node yang tidak memiliki anak
        if(R->left == NULL && R->right == NULL){
            delete R;
            R = NULL;
            return R;
        }else if(R->left == NULL){
            adrNode temp = R;
            R = R->left;
            delete temp;
            return R;
        }else if(R->right == NULL){
            adrNode temp = R;
            R = R->right;
            delete temp;
            return R;
        }else{
            adrNode temp = min_Node(R->right);
            R->info = temp->info;
            R->right = delete_Node(root->right, info->)
            return R;
        }
    }
}
