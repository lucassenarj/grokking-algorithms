#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** sortPeople(char** names, int namesSize, int* heights, int heightsSize, int* returnSize);

int main(void)
{
    const int size = 8;
    int namesSize = size;
    int heights[size] = {17233,32521,14087,42738,46669,65662,43204,8224};
    int heightsSize = size;
    int *returnSize = &heightsSize;
    char *names[size];

    for (int i = 0; i < namesSize; i++)
    {
        names[i] = malloc(sizeof(char) * namesSize);
    }

    strcpy(names[0], "IEO");
    strcpy(names[1], "Sgizfdfrims");
    strcpy(names[2], "QTASHKQ");
    strcpy(names[3], "Vk");
    strcpy(names[4], "RPJOFYZUBFSIYp");
    strcpy(names[5], "EPCFFt");
    strcpy(names[6], "VOYGWWNCf");
    strcpy(names[7], "WSpmqvb");

    char** sorted = sortPeople(names, namesSize, heights, heightsSize, returnSize);

    for (int i = 0; i < namesSize; i++)
    {
        printf("Name: %s\n", sorted[i]);
    }
}

char** sortPeople(char** names, int namesSize, int* heights, int heightsSize, int* returnSize) {
    int i, j;
    *returnSize = namesSize;

    for (i = 0; i < heightsSize; i++)
    {
    
        for (j = i; j < heightsSize; j++)
        {
            if (heights[j] > heights[i])
            {
                int tpmNumber = heights[i];
                heights[i] = heights[j];
                heights[j] = tpmNumber;

                char *tmp=(char*)malloc(sizeof(char)*20);
                tmp = names[i];
                names[i] = names[j];
                names[j] = tmp;
            }
        }
    }

    return names;
}

/*
char** sortPeople(char** names, int namesSize, int* heights, int heightsSize, int* returnSize) {
    int i, j;
    *returnSize = namesSize;

    int sortedHeights[heightsSize];

    for (i = 0; i < heightsSize; i++)
    {
        int minIdex = i;
        int current = heights[i];
    
        for (j = 0; j < heightsSize; j++)
        {
            if (heights[j] > current)
            {
                current = heights[j];
                minIdex = j;
            }
        }
        heights[minIdex] = 0;
        sortedHeights[i] = minIdex;
    }

    char** sortedNames;
    sortedNames = malloc((namesSize)*sizeof(char*));

    for (i = 0; i < namesSize; i++)
    {
        char *name = malloc((namesSize + 1) * sizeof(char));
        name = names[sortedHeights[i]];
        sortedNames[i] = name;
        name = malloc(sizeof(char *));
    }

    return sortedNames;
}
*/
