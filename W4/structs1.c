#include <stddef.h>
#include <stdio.h>

int main (int argc, char *argv[])
{
    struct car
    {
        int year;
        char model[10];
        float engine;
    };

    struct car myCar;

    myCar.year = 2007;

    printf("%d",myCar.year);




    return 0;
}