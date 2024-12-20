#include <iostream>
#include "tree.h"
using namespace std;

int main()
{
   cout << "=============================================" << endl;
   int x[9] = {5,3,9,10,4,7,1,8,6};
   cout << "\nArray elements\t        : ";
   for(int i = 0; i < 9; i++){
        cout << x[i] << " ";
   }
   cout << endl;

   adrNode root;
   root = NULL;
   for(int i = 0;i < 9; i++){
        adrNode p = newNode_103032330131(x[i]);
        insertNode_103032330131(root, p);
   }

   cout << "\nNode 10 dihapus \t: ";
   delete_Node(root, 10);
   printAll(root);
   cout << endl;

   cout << "\nNode 7 dihapus \t        : ";
   delete_Node(root, 7);
   printAll(root);
   cout << endl;

   cout << "\nNode 3 dihapus \t        : ";
   delete_Node(root, 3);
   printAll(root);
   cout << endl;


   cout << "\nPre Order\t        : ";
   printPreOrder_103032330131(root);
   cout << endl;

   cout <<"\nDescendant of Nide 9\t: ";
   printDescendant_103032330131(root, 9);
   cout << endl;

   cout << "\nSum of BST Info\t        : " << sumNode_103032330131(root) << endl;

   cout << "\nNumber of Leaves\t: " << countLeaves_103032330131(root) << endl;

   cout << "\nHeight of Tree\t        : " << heightTree_103032330131(root) << endl;



   cout << "=============================================" << endl;
   return 0;

}

