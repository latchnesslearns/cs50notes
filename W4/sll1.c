// Test program for understanding of linked list and typdef

#include <stdio.h>
#include <stdlib.h>

typedef struct nodeTemp
{
    int data;
    struct nodeTemp* next; 
}
node;

node* makeNode(int data);

node* findData(node* firstNode, int data);

node* addNode(node* firstNode, int data);

void destroyNodes(node* firstNode);

int main (int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Enter exactly 3 CLIs\n");
        return 1;
    }
    // get data value from user
    int firstVal = atoi(argv[1]);
    int secondVal = atoi(argv[2]);

    int searchVal = atoi(argv[3]);

    // initalise first node
    node* firstNode = makeNode(firstVal);

    // add 2nd node (which will now be the first in the list)
    firstNode = addNode(firstNode,secondVal);

    // search for value
    node* foundLocation = findData(firstNode,searchVal);

    // print it for good measure
    printf("firstNode.data: %d\n",firstNode->data);
    printf("firstNode.next: 0x%x\n",(unsigned int) firstNode->next);
    printf("foundLocation: 0x%x\n",(unsigned int) foundLocation);

    return 0;
}

node* makeNode(int data)
{
    node* thisNode = malloc(sizeof(node));
    if (thisNode == NULL)
    {
        fprintf(stderr,"Ran out of memory");
    }
    thisNode->data = data;
    thisNode->next = NULL;
    return thisNode;
}

node* addNode(node* firstNode, int data)
{
    node* thisNode = makeNode(data);
    thisNode->next = firstNode;
    return thisNode;
}

node* findData(node* firstNode, int data)
{
    // check if data is in firstNode
    if(firstNode->data == data)
    {
        return firstNode;
    }
    // ensure this isn't last object in list
    else if(firstNode->next == NULL)
    {
        return NULL;
    }
    // call recursively with next
    return findData(firstNode->next, data);
}

void destroyNodes(node* firstNode)
{
    if(firstNode->next != NULL)
    {
        destroyNodes(firstNode->next);
    }
    free(firstNode);
}
