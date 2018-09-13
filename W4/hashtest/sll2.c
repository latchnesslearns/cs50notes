#include "sll.c"
#include <stdio.h>
#include <stdint.h>

// node *hashtable[10]

int main(int argc, char *argv[])
{
        // check proper usage
    if (argc != 2)
    {
        printf("nah, %s\n",argv[0]);
        return 1;
    }
    char *word = argv[1];
    
    printf("%s\n",word);

    node * nodeOne = makeNode(word);

    printf("%s\n",nodeOne->word);

    return 0;
}
//