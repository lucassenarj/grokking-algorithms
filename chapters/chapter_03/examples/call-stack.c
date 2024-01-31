#include <stdio.h>

void salute(char *name);
void salute2(char *name);
void good_bye(void);

int main(void) {
    char name[10] = "Maggie";

    salute(name);
}

void salute(char *name)
{
    printf("Hi, %s! \n", name);

    salute2(name);

    printf("Preparing to say god bye...\n");

    good_bye();
}

void salute2(char *name)
{
    printf("How you doing, %s? \n", name);
}

void good_bye(void)
{
    printf("Ok, bye!\n");
}
