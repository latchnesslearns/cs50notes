// Test program for understanding of linked list and typdef

#include <stdio.h>
#include <stdlib.h>
#include "sll.h"

// typedef struct nodeTemp
// {
//     char word[LENGTH];
//     struct nodeTemp* next; 
// }
// node;

// node* makeNode(int word);

// node* findword(node* firstNode, int word);

// node* addNode(node* firstNode, int word);

// void destroyNodes(node* firstNode);

int main (int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Enter exactly 3 CLIs\n");
        return 1;
    }
    // get word value from user
    int firstVal = atoi(argv[1]);
    int secondVal = atoi(argv[2]);

    int searchVal = atoi(argv[3]);

    // initalise first node
    node* firstNode = makeNode(firstVal);

    // add 2nd node (which will now be the first in the list)
    firstNode = addNode(firstNode,secondVal);

    // search for value
    node* foundLocation = findword(firstNode,searchVal);

    // print it for good measure
    printf("firstNode.word: %d\n",firstNode->word);
    printf("firstNode.next: 0x%x\n",(unsigned int) firstNode->next);
    printf("foundLocation: 0x%x\n",(unsigned int) foundLocation);

    return 0;
}

node* makeNode(int word)
{
    node* thisNode = malloc(sizeof(node));
    if (thisNode == NULL)
    {
        fprintf(stderr,"Ran out of memory");
    }
    thisNode->word = word;
    thisNode->next = NULL;
    return thisNode;
}

node* addNode(node* firstNode, int word)
{
    node* thisNode = makeNode(word);
    thisNode->next = firstNode;
    return thisNode;
}

node* findword(node* firstNode, int word)
{
    // check if word is in firstNode
    if(firstNode->word == word)
    {
        return firstNode;
    }
    // ensure this isn't last object in list
    else if(firstNode->next == NULL)
    {
        return NULL;
    }
    // call recursively with next
    return findword(firstNode->next, word);
}

void destroyNodes(node* firstNode)
{
    if(firstNode->next != NULL)
    {
        destroyNodes(firstNode->next);
    }
    free(firstNode);
}
