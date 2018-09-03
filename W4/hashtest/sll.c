// definitions for nodes and related functions
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
