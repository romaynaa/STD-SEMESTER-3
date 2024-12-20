#include <iostream>
#include "graf.h"
using namespace std;

int main()
{
   graph G;
   adrVertex v;

   cout<< "Build Graph"<<endl;
   buildGraph_103032330131(G);

   v = G.firstVertex;
   while(v!=NULL){
    cout << v->IDVertex << " ";
    v = v->nextVertex;
   }
   cout << endl;
   return 0;
}
