#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "unFind.h"
#include "handy_list.h"



int c1, i, c4,c5;
int c2, c3;
//int j;
uf_node_t * aNode;
uf_node_t * aNode1;
uf_node_t * aNode2;
uf_node_t * aNode3;
uf_node_t * aNode4;

int object;
int object1,object2;

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






//for user interface
int menu()

{
    int ch;
    printf("\n 1. Create a Node Item ");
    printf("\n\n 2. Join Node items");
    printf("\n\n 3. Establish Same Class");
    printf("\n\n 4. Display Information");
    printf("\n\n 5. Exit");

    //default:printf("invalid option\n");
    puts(" ");
    printf("\n Enter your choice: ");
    scanf("%d",&ch);

    return ch;
}
//main function begins program execution
int main()
{
    aNode = (uf_node_t*)malloc(i * sizeof(uf_node_t));  //dynamically allocate memory for a node
    handy_list usf = handy_create_list();    //create a handy list of nodes (union find structure) i.e a linked list
    handy_list db = handy_create_list();     //create a handy list of intergers (where each integer is found in a node container)


    while(1)
    {


        switch(menu()) {

            case 1:
                printf("Enter an int: "); //prompt user for and integer
                scanf("%d", &c1);         //read input
                aNode = insert(c1);       //store input integer in a node
                object = aNode->item;       // assign integer item contained in a node to the variable object
                usf->add_back(usf, aNode);    //add node to to the union find structure
                db->add_back(db, object);
                // printf("%d", aNode->item);
                break;

            case 2:

                printf("The list so far is: ");
               // for (i = 0; i < db->length(db); i++)
                for (int l = 0; l < usf->length(usf); l++)
                {
                    //printf("%3d, ", db->get_at(db, i));
                    uf_node_t *Node = usf->get_at(usf,l);

                    printf("%3d", Node->item);
                }

                printf("\nEnter the first integer you want to perform join: ");
                scanf("%d", &c2);
                if (usf->contain(usf, aNode) != -1 && aNode->item == c2)
                { //checks if usf contains the node with item c2
                  //if the usf contains the node
                    aNode1 = usf->get_at(usf, i); // then gets the node

                }
                else
                { // else insert the item into a node container
                    aNode1 = insert(c2);
                    object1 = aNode1->item;
                    usf->add_back(usf, aNode1);
                    db->add_back(db, object1);
                    usf->get_back(usf);
                }

                printf("\nEnter the second integer you want to perform join: ");
                scanf("%d", &c3);

                if (usf->contain(usf, aNode) != -1 && aNode->item == c3)
                { //checks if usf contains the node with item c3
                    //if the usf contains the node
                    aNode2 = usf->get_at(usf, i); // then gets the node


                }
                else
                { // else insert the item into a node container
                    aNode2 = insert(c3);
                    object2 = aNode2->item;
                    usf->add_back(usf, aNode2);
                    db->add_back(db, object2);
                    usf->get_back(usf);
                }

                join(aNode1, aNode2); //perform join function on both nodes


                /*
                if(usf->length(usf) >= 2)
                {
                    printf("Enter integer position of first node: ");
                    scanf("%d",&i);
                    printf("Enter integer position of second node: ");
                    scanf("%d",&j);
                    join(usf->get_at(usf, i),usf->get_at(usf,j));

                }

               */
                break;

            case 3:

                printf("The list so far is: ");
               // for (i = 0; i < db->length(db); i++)
                for (int l = 0; l < usf->length(usf); l++)
                {
                    //printf("%3d, ", db->get_at(db, i));
                    uf_node_t *Node = usf->get_at(usf,l);

                   printf("%3d", Node->item);
                }
                printf("\nEnter the first integer you want to establish same class: ");
                scanf("%d", &c4);
                if (usf->contain(usf, aNode) != -1 && aNode->item == c4)
                { //checks if usf contains the node with item c4
                    //if the usf contains the node
                    aNode3 = usf->get_at(usf, i); // then gets the node

                }
                else
                { // else insert the item into a node container
                    aNode3 = insert(c4);
                    object1 = aNode1->item;
                    usf->add_back(usf, aNode3);
                    db->add_back(db, object1);
                    usf->get_back(usf);
                }

                printf("\nEnter the second integer you want to establish same class: ");
                scanf("%d", &c5);

                if (usf->contain(usf, aNode) != -1 && aNode->item == c5)
                { //checks if usf contains the node with item c5
                    /// /if the usf contains the node
                    aNode4 = usf->get_at(usf, i);// then gets the node

                }
                else
                {// else insert the item into a node container
                    aNode4 = insert(c5);
                    object2 = aNode2->item;
                    usf->add_back(usf, aNode4);
                    db->add_back(db, object2);
                    usf->get_back(usf);
                }


                check (aNode3, aNode4); //checkif both nodes are in the same class or set



                //   printf(" Both nodes are in thesame class");
             //   } else {
               //     printf(" Both nodes are not in thesame class");
              //  }

                /*
                if(usf->length(usf) >= 2)
                {
                    //integer position starts at o
                    printf("Enter integer position of first node: ");
                    scanf("%d",&i);
                    printf("Enter integer position of second node: ");
                    scanf("%d",&j);
                    printf("\n\nAre the nodes in thesame class? ");
                    if(same_class(usf->get_at(usf, i),usf->get_at(usf,j)))
                    {
                        printf(" Both nodes are in thesame class");
                    }
                    else
                    {
                        printf("Both nodes are not in the class\n");
                    }


                }
               */
                break;

            case 4:

                printf("set: { ");
                for (i = 0; i < db->length(db); i++) {

                    printf("%3d, ", db->get_at(db,i));


                }

                printf(" }");
                puts(" ");
                break;

            case 5:
                exit(0);


        }

    }

}
















