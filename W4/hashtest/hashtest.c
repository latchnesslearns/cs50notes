#include "PMurHash.h"
#include "sll.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    // check proper usage
    if (argc != 3)
    {
        printf("type a word to get its hash and search for a second word\n");
        return 1;
    }

    // initialise hashtable
   node *hashtable[UINT32_MAX];

    // get input word
    char *word = argv[1];
    printf("word: %s\n",word);

    uint32_t wordhash = PMurHash32(0,word,sizeof(word));

    printf("wordhash: 0x%x\n",wordhash);

    // put word into hashtable
    makeNode(hashtable[wordhash],atoi(word));

    // get search word
    char *searchWord = argv[2];
    uint32_t searchhash = PMurHash32(0,searchWord,sizeof(searchWord));

    node *foundLocation = findData(hashtable[searchhash],atoi(searchWord));

    if(foundLocation != NULL)
    {
        printf("%x\n",(unsigned int)foundLocation->data);
    }
    else
    {
        printf("not found\n");
    }


    return 0;
}