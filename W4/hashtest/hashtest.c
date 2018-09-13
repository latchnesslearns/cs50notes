#include "PMurHash.h"
#include "sll.h"
#include <stdio.h>
#include <string.h>

node *hashtable[UINT32_MAX];

int main(int argc, char *argv[])
{
    // check proper usage
    if (argc != 3)
    {
        printf("type a word to get its hash and search for a second word\n");
        return 1;
    }

    // get input word
    char *word = argv[1];

    // hash it
    uint32_t wordhash = PMurHash32(0,word,strlen(word));

    // put word into hashtable
    if(hashtable[wordhash] == NULL) // array at current hashpoint is empty
    {
        hashtable[wordhash] = makeNode(word);
    }
    else // array at current hashpoint already has something in it
    {
        addNode(hashtable[wordhash],word);
    }

    // print some debug stuff
    printf("word: %s\t||\t",word);
    printf("wordhash: 0x%x\t||\t",(unsigned int)wordhash);    
    printf("word in hashtable: %s\n",hashtable[wordhash]->word);

    // get search word
    char *searchWord = argv[2];

    // check what's in that array loc
    
    uint32_t searchHash = PMurHash32(0,searchWord,strlen(searchWord));

    // print some debug stuff
    printf("searchWord: %s\t||\t",searchWord);
    printf("searchHash: 0x%x\t||",(unsigned int)searchHash);    
    // printf("word in hashtable: %s\n",hashtable[wordhash]->word);

    node *foundLocation = findWord(hashtable[searchHash],searchWord);

    if(foundLocation != NULL)
    {
        printf("FOUND! 0x%x\t|| word at foundloc: %s\n",(unsigned int)&foundLocation,foundLocation->word);
    }
    else
    {
        printf("not found\n");
    }


    return 0;
}