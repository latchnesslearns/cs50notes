#include <stddef.h>
#include <stdio.h>

int main (void)
{
    struct car
    {
        int year;
        char model[10];
        float engine;
    };

    struct car myCar;

    myCar.year = 2007;

    strcpy(myCar.model,"Toyota");

    printf("%d\n",myCar.year);
    printf("%s\n",myCar.model);

    return 0;
}