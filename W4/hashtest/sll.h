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