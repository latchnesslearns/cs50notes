// definitions for nodes and related functions
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sll.h"

node* makeNode(char word[LENGTH])
{
    node* thisNode = malloc(sizeof(node));
    if (thisNode == NULL)
    {
        fprintf(stderr,"Ran out of memory");
    }
    // put string into word
    strncpy(thisNode->word,word,sizeof(thisNode->word));

    thisNode->next = NULL;
    return thisNode;
}

node* addNode(node* firstNode, char word[LENGTH])
{
    node* thisNode = makeNode(word);
    thisNode->next = firstNode;
    return thisNode;
}

node* findWord(node* firstNode, char word[LENGTH])
{   
    // check if there's anything in this node
    if(firstNode == NULL)
    {
        return NULL;
    }
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
    return findWord(firstNode->next, word);
}

void destroyNodes(node* firstNode)
{
    if(firstNode->next != NULL)
    {
        destroyNodes(firstNode->next);
    }
    free(firstNode);
}
