//
// Created by jorel on 1/23/19.
//

#ifndef UNION_FIND_UNFIND_H
#define UNION_FIND_UNFIND_H


//fields of item_t
/*
typedef struct item_t {
    char * name;
    int id;
    char * sex;
} item_t;
*/


// /fields representing the node of an item_t
typedef struct uf_n_t {
    int rank;                //rank of the node of an item
    int item;            //the item in the node
    struct uf_n_t *up;       //all nodes point to their parent
} uf_node_t;

//make item of a node a node
uf_node_t *insert(int new_item);

int menu();

//function checks if two nodes point to  thesame root node i.e if two nodes are in thesame set.
//if two nodes have thesame roots then they are in thesame set.
int same_class( uf_node_t *node1,uf_node_t *node2);
uf_node_t * join( uf_node_t *node1, uf_node_t*node2 );// make two nodes point to the same root.



#endif //UNION_FIND_UNFIND_H
