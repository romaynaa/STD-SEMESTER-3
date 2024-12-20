#include <iostream>
#include "tree.h"
using namespace std;

adrNode newNode_103032330131(infotype x){
    adrNode p = new ElmNode;
    p->info = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}
adrNode findNode_103032330131(adrNode root, infotype x){
   if(root->info == x){
    return root;
   }
   if(x < root->info){
    return findNode_103032330131(root->left,x);
   }else{
    return findNode_103032330131(root->right,x);
   }
//    adrNode p;
//    if(root != NULL){
//        p = root;
//        while(p != NULL && p->info != x){
//            if(x < p->info){
//                p = p->left;
//            }else{
//                p = p->right;
//            }
//        }
//        if(p->info == x){
//            return p;
//        }else{
//            return NULL;
//        }
//    }else{
//        return NULL;
//    }
}
void insertNode_103032330131(adrNode &root, adrNode p){
    if(root == NULL){
        root = p;
    }else if(p->info < root->info){
        insertNode_103032330131(root->left, p);
    }else{
        insertNode_103032330131(root->right, p);
    }
}
void printPreOrder_103032330131(adrNode root){
    if(root != NULL){
        cout << root->info << " ";
        printPreOrder_103032330131(root->left);
        printPreOrder_103032330131(root->right);
    }
}
void printDescendant_103032330131(adrNode root, infotype x){
    adrNode p = findNode_103032330131(root, x);
    if(p != NULL){
        printPreOrder_103032330131(p->left);
        printPreOrder_103032330131(p->right);
    }else{
        cout << "Node tidak ditemukan" << endl;
    }
}
int sumNode_103032330131(adrNode root){
    if(root == NULL){
        return 0;
    }else{
        return root->info + sumNode_103032330131(root->left) + sumNode_103032330131(root->right);
    }
}
int countLeaves_103032330131(adrNode root){
    if(root == NULL){
        return 0;
    }else if(root->left == NULL && root->right == NULL){
        return 1;
    }else{
        return countLeaves_103032330131(root->left) + countLeaves_103032330131(root->right);
    }
}
int heightTree_103032330131(adrNode root){
    if(root == NULL){
        return -1;
    }
    int leftHeight = heightTree_103032330131(root->left);
    int rightHeight = heightTree_103032330131(root->right);
    return max(leftHeight, rightHeight) + 1;
}
adrNode max_Node(adrNode &root){
    adrNode p;
    p = root->left;
    while(p->right != NULL){
        p = p->right;
    }
    return p;
}
void printAll(adrNode root){
    if(root == NULL){
        return;
    }
    printAll(root->left);
    cout << root->info << " ";
    printAll(root->right);
}
adrNode delete_Node(adrNode &root, infotype x){
    adrNode p;
    if(root == NULL){ //data tidak ada dalam tree
        return NULL;
    }else if(x < root->info){
        delete_Node(root->left, x);
    }else if(x > root->info){
        delete_Node(root->right, x);
    }else{
        //root tidak punya anak atau hanya satu anak
        if(root->left == NULL || root->right == NULL){
            p = NULL;
            if(root->left != NULL){
                p = root->left;
            }else{
                p = root->right;
            }
            if(p == NULL){
                p = root;
                root = NULL;
            }else{
               root = p;
            }
            delete p;
        }else{
            p = max_Node(root);
            root->info = p->info;
            root->left = delete_Node(root->left, p->info);
        }
    }
    return root;
}
adrNode delete_All(adrNode root){
    if(root == NULL){
        return NULL;
    }
    root->left = delete_All(root->left);
    root->right = delete_All(root->right);
    delete root;
    return NULL;
}
