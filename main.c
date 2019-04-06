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
//handy_list UNF = handy_create_list();










//for user interface
int menu()

{
    int ch;
    printf("\n 1. Create a Node Item ");
    printf("\n\n 2. Join Node items");
   // printf("\n\n 3. Establish Same Class");
    printf("\n\n 3. Display Information");
    printf("\n\n 4. Exit");

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
    handy_list db = handy_create_list();//create a handy list of intergers (where each integer is found in a node container)
   // aNode1 = (uf_node_t*)malloc(i * sizeof(uf_node_t));
//   / aNode2 = (uf_node_t*)malloc(i * sizeof(uf_node_t));

    while(1)
    {


        switch(menu()) {

            case 1:
                printf("Enter an int: "); //prompt user for and integer
                scanf("%d", &c1);         //read input
                aNode = insert(c1);       //store input integer in a node
                object = aNode->item;       // assign integer item contained in a node to the variable object
                usf->add_back(usf, aNode);    //add node to to the union find structure
               // db->add_back(db, object);
                // printf("%d", aNode->item);
                break;

            case 2:

                printf("The list so far is: ");
               // for (i = 0; i < db->length(db); i++)
                //loop through usf to find a ne=o
                for (int l = 0; l < usf->length(usf); l++)
                {
                    //printf("%3d, ", db->get_at(db, i));
                    uf_node_t *Node = usf->get_at(usf,l);

                    printf("%3d", Node->item);
                }

                printf("\nEnter the first integer you want to perform join: ");
                scanf("%d", &c2);
                for(int l = 0; l < usf -> length(usf); l++)
                {
                    if (usf->contain(usf, aNode) != -1 && aNode->item == c2 )
                    { //checks if usf contains the node with item c2
                        //if the usf contains the node
                        aNode1 = usf->get_at(usf, l); // then gets the node


                    }

                }
                if(aNode1 == NULL)
                {

                     // else insert the item into a node container
                        aNode1 = insert(c2);
                        object1 = aNode1->item;
                        usf->add_back(usf, aNode1);
                      //  db->add_back(db, object1);
                        usf->get_front(usf);

                }



              printf("\nEnter the second integer you want to perform join: ");
                scanf("%d", &c3);
                for(int i = 0; i < usf -> length(usf); i++)
                {
                    if (usf->contain(usf, aNode) != -1 && aNode->item == c3 )
                    { //checks if usf contains the node with item c3
                        //if the usf contains the node
                        aNode2 = usf->get_at(usf,i); // then gets the node


                    }
                }
                if (aNode2 == NULL)
                {
                   // else
                    //{ // else insert the item into a node container
                        aNode2 = insert(c3);
                        object2 = aNode2->item;
                        usf->add_back(usf, aNode2);
                      //  db->add_back(db, object2);
                        usf->get_back(usf);
                   // }
                }

               if(same_class(aNode1,aNode2))
               {
                   printf("both nodes are already in the same set");
               }
                else
               {
                   join(aNode1, aNode2);//perform join function on both nodes
               }



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

                printf("set: { ");
                for (int l = 0; l < usf->length(usf); l++)
                {
                    //printf("%3d, ", db->get_at(db, i));
                    uf_node_t *Node = usf->get_at(usf,l);

                    printf("%3d %3d", Node->item, Node->rank);
                }
                //for (i = 0; i < db->length(db); i++) {

                  //  printf("%3d, ", db->get_at(db,i));


               // }

                printf(" }");
                puts(" ");
                break;

            case 4:
                exit(0);

            default:
                printf("invalid option\n");


        }

    }

}
















