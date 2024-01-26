#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Quarterback {
    char name[50];
    int jersey;
} Quarterback;

Quarterback search(char *name, Quarterback *qbs);

int main (void)
{
    char *player;

    Quarterback qbs[5] = {
        { "Andrew Luck", 12 },
        { "Bert Jones", 7 },
        { "Jim Harbaugh", 4 },
        { "Johnny Unitas", 19 },
        { "Peyton Manning", 18 }
    };

    printf("Type Colts QB name which you want to know the jersey: ");
    scanf("%50[^\n]", player);
    getchar();

    Quarterback qb = search(player, qbs);

    if (qb.jersey == 0)
    {
        printf("Player not found!\n");
        return 1;
    }

    printf("\nQB Founded! #%d %s\n", qb.jersey, qb.name);
    return 0;
}

Quarterback search(char *typed, Quarterback *qbs)
{
    Quarterback player;
    player.jersey = 0;
    char *name = malloc(sizeof(typed));
    if (name == NULL) {
        printf("ERROR: Unable to alloc memory space.\n");
        return player;
    }

    strcpy(name, typed);
    

    int lowestPosition = 0;
    int highestPosition = 4;
    int middlePosition = 0;

    while (lowestPosition <= highestPosition) {
        middlePosition = (lowestPosition + highestPosition) / 2;
        Quarterback pick = qbs[middlePosition];
        int result = strcmp(pick.name, name);
    
        /*
            printf("\n\tSEARCH FUNCTION\n");
            printf("QB Name: %s\n", name);
            printf("Pick Name: %s\n", pick.name);
            printf("Lowest position: %d\n", lowestPosition);
            printf("Middle position: %i\n", middlePosition);
            printf("Highest position: %d\n", highestPosition);
            printf("Result: %d\n", result);
        */

        if ( result == 0) {
            return pick;
        } else if (result > 0) { // if current name is alphabetical higher or lower than the requested name
            highestPosition = middlePosition - 1;
        } else {
            lowestPosition = middlePosition + 1;
        }
    }
    
    free(name);
    return player;
}