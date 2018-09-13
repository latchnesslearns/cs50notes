#include <stdio.h>
#include <stdlib.h>

#define LENGTH 45

typedef struct nodeTemp
{
    char word[LENGTH];
    struct nodeTemp* next; 
}
node;

node* makeNode(char word[LENGTH]);

node* findWord(node* firstNode, char word[LENGTH]);

node* addNode(node* firstNode, char word[LENGTH]);

void destroyNodes(node* firstNode);