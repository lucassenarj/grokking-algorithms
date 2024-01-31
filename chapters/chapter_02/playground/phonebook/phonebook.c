// open file
// read qtd size
// create new array based on the amount
// read file again
// for each element
    // push in new array the value of the element in i index

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// define struct to each person
typedef struct {
    int id;
    char name[50];
    char phone[10];
} Person;

Person *selection_sort(Person **people, int size);

int main(void) {
    // open file in read mode
    FILE *csv = fopen("./unsorted_names.csv", "r");
    int i, length;

    if (csv == NULL) {
        printf("Unable to read the file!\n");
        return 1;
    }

    // read how many itens contains the file
    fscanf(csv, "%d\n", &length);

    // create list os people
    Person *people[length];
    Person *p = malloc(sizeof(Person));

    for (i = 0; i < length; i++) {

        fscanf(csv, "%d,", &p->id);
        fscanf(csv, "%49[^,]", p->name);
        fscanf(csv, ",%9[^\n]", p->phone);
        people[i] = p;
        p = malloc(sizeof(Person));
    }

    // close file
    fclose(csv);

    selection_sort(people, length);

    // print list
    //*
    printf("\n\tList of people: \n");
    for (i = 0; i < length; i++)
    {
        printf("%s, %s\n", people[i]->name, people[i]->phone);
    }
    free(p);
    //*/
}

Person *selection_sort(Person **people, int size)
{
    int i, j;

    for (i = 0; i < size; i++)
    {
        Person *p = people[i];
        int minIndex = i;
        for (j = 0; j < size; j++)
        {
            if(strcasecmp(people[j]->name, p->name) >= 0) {
                p = people[j];
                minIndex = j;
            }
            // if min index is smaller then current index, means that current index isen't the smaller anymore
            if (minIndex != i) {
                Person *tmp = people[i];
                people[i] = people[minIndex];
                people[minIndex] = tmp;
            }

        }
    }
    
    return *people;
}