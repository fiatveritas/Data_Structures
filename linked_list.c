#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
}node;

void traverse(node *head); // this method traverses the linked list
void traverse_r(node *head); //traverses in reverse
void clear_list(node *head);

int main()
{
    //create nodes that will be used
    node *node_1;
    node *node_2;
    node *node_3;
    node *node_4;

    //allocate size using malloc
    node_1 = (node*) malloc(sizeof(node));
    node_2 = (node*) malloc(sizeof(node));
    node_3 = (node*) malloc(sizeof(node));
    node_4 = (node*) malloc(sizeof(node));

    //assign values to the nodes
    node_1->value = 1;
    node_2->value = 2;
    node_3->value = 3;
    node_4->value = 4;

    //set next and skip node 3, it will be added later
    node_1->next = node_2;
    node_2->next = node_4;
    node_4->next = NULL;

    printf("traversing list...\n");
    traverse(node_1);
    printf("done\n");

    node *dummy;
    dummy = (node*) malloc(sizeof(node));

    dummy->next = node_4; //dummy is needed as a place holder
    node_2->next = node_3;
    node_3->next = node_4;
    dummy->next = NULL; //set dummy to dull after it is used up

    printf("updated list...\n"); //make sure the list was updated
    traverse(node_1);
    printf("done\n");

    printf("printing in reverse...\n");
    traverse_r(node_1);

    printf("clearing list...\n"); //clear nodes->next
    clear_list(node_1);

    traverse(node_1); //traverse each node to check nodes->next is NULL
    printf("done\n");
    traverse(node_2);
    printf("done\n");
    traverse(node_3);
    printf("done\n");
    traverse(node_4);
    printf("done\n");

    //dummy = 

    free(node_1);
    free(node_2);
    free(node_3);
    free(node_4);
    free(dummy);

    return 0;
}

void traverse(node *head) //this traverses and prints the linked list
{
    //traversal happens from head to tail of the linked list
    while (head != NULL)
    {
        printf("%i\n", head->value);
        head = head->next;
    }
    return;
}

void traverse_r(node *head)
{
    if (head == NULL)
    {
        return;
    }
    else
    {
        traverse_r(head->next);
        printf("%d\n", head->value);
        return;
    }
}

void clear_list(node *head) //this clear the linked list
{
    if (head == NULL)
    {
        return;
    }
    else if (head != NULL)
    {
        //
        clear_list(head->next);
        head->next = NULL;
        return;
    }
    return;
}