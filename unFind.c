#include <stdio.h>
#include <stdlib.h>
#include "unFind.h"

uf_node_t *insert(int new_item){
    uf_node_t *new_node;
    new_node =(uf_node_t *) malloc(sizeof(uf_node_t));
    new_node->item = new_item;
    new_node->rank = 0;
    new_node->up = NULL;
    return( new_node );
}

int same_class( uf_node_t *node1, uf_node_t *node2 ){
    uf_node_t *root1, *root2, *tmp;
/* find both roots */
    for( root1 = node1; root1->up != NULL; root1 = root1->up); /* follow path to root for node1 */
    for( root2 = node2; root2->up != NULL; root2 = root2->up); /* follow path to root for node2 */
/* make both paths point directly to
their respective roots */
    tmp = node1->up;

    while( tmp != root1 && tmp != NULL ){
        node1->up = root1;
        node1 = tmp;
        tmp = node1->up;
    }

    tmp = node2->up;

    while( tmp != root2 && tmp != NULL ){
        node2->up = root2;
        node2 = tmp;
        tmp = node2->up;
    }
/* return result */
    return( root1 == root2 );
}

//void join( uf_node_t *node1, uf_node_t*node2 )
uf_node_t *join( uf_node_t *node1, uf_node_t*node2 )
{
    uf_node_t *root1, *root2, *new_root, *tmp;
/* find both roots */
    for( root1 = node1; root1->up !=NULL; root1 = root1->up); /* follow path to root for node1 */
    for( root2 = node2; root2->up !=NULL; root2 = root2->up); /* follow path to root for node2 */
/* perform union by rank */
    if( root1->rank > root2->rank ){
        new_root = root1;
        root2->up = new_root;
    }

    else if( root1->rank < root2->rank ){
        new_root = root2;
        root1->up = new_root;
    }
/* same rank */
    else{
        new_root = root1;
        root2->up = new_root;
        new_root->rank += 1;
    }
/* make both paths point directly to the new root */
    tmp = node1->up;

    while( tmp != new_root && tmp != NULL ){
        node1->up = new_root;
        node1 = tmp;
        tmp = node1->up;
    }

    tmp = node2->up;

    while( tmp != new_root && tmp != NULL){
        node2->up = new_root;
        node2 = tmp;
        tmp = node2->up;
    }
    return new_root;
}