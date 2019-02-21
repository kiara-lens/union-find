#include <stdio.h>
#include <stdlib.h>
#include "unFind.h"

void check(uf_node_t *t, uf_node_t *f){
    if(same_class(t,f))
    {
        printf("\nboth nodes are in the same set");
    }
    else
    {
        printf("\nboth nodes are not the in the same set");
    }

}



uf_node_t *NODES[10];




int main()
{

    NODES[10]=(uf_node_t*)malloc(10* sizeof(uf_node_t));
    NODES[0]= insert(1);
    NODES[1]= insert(2);
    NODES[2]= insert(10);
    NODES[3]= insert(21);
    NODES[5]= insert(13);
    NODES[6]= insert(12);
    NODES[7]= insert(4);
    NODES[8]= insert(6);
    NODES[9]= insert(15);





    join(NODES[7],NODES[8]);

    join(NODES[0],NODES[1]);

    join(NODES[7],NODES[1]);



    check(NODES[7],NODES[8]);
    check(NODES[0],NODES[1]);
    check(NODES[0],NODES[8]);
    check(NODES[9],NODES[2]);






}

















