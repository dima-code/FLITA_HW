#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SET_SIZE 100

typedef struct Set {
    char* elements[MAX_SET_SIZE];
    int size;
} Set;

void initialize(Set* set) {
    set->size = 0;
}

void add(Set* set, char* element) {
    if (set->size < MAX_SET_SIZE) {
        int i;
        for (i = 0; i < set->size; i++) {
            if (strcmp(set->elements[i], element) == 0) {
                printf("Error: element already exists in set\n");
                return;
            }
        }
        set->elements[set->size] = strdup(element);
        set->size++;
    }
    else {
        printf("Error: set is full\n");
    }
}

void removeElement(Set* set, char* element) {
    int i;
    for (i = 0; i < set->size; i++) {
        if (strcmp(set->elements[i], element) == 0) {
            free(set->elements[i]);
            set->elements[i] = set->elements[set->size - 1];
            set->size--;
            return;
        }
    }
    printf("Error: element not found in set\n");
}

void print(Set* set) {
    int i;
    for (i = 0; i < set->size; i++) {
        printf("%s\n", set->elements[i]);
    }
}

int main() {
    Set set1, set2;
    initialize(&set1);
    initialize(&set2);

    int i, n;
    char input[100];

    printf("Enter the number of elements in set1:\n");
    scanf("%d", &n);
    printf("Enter %d elements for set1:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%s", input);
        add(&set1, input);
    }

    printf("Enter the number of elements in set2:\n");
    scanf("%d", &n);
    printf("Enter %d elements for set2:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%s", input);
        add(&set2, input);
    }

    int command = 0;

    while (command != 6) {
        printf("\nEnter a command:\n");
        printf("1. Add element to set1\n");
        printf("2. Add element to set2\n");
        printf("3. Remove element from set1\n");
        printf("4. Remove element from set2\n");
        printf("5. Print elements of both sets\n");
        printf("6. Exit\n");

        scanf("%d", &command);

        switch (command) {
            case 1:
                printf("Enter an element to add to set1:\n");
                scanf("%s", input);
                add(&set1, input);
                printf("Set 1 after adding element:\n");
                print(&set1);
                break;

            case 2:
                printf("Enter an element to add to set2:\n");
                scanf("%s", input);
                add(&set2, input);
                printf("Set 2 after adding element:\n");
                print(&set2);
                break;

            case 3:
                printf("Enter an element to remove from set1:\n");
                scanf("%s", input);

                removeElement(&set1, input);
                printf("Set 1 after removing element:\n");
                print(&set1);
                break;

            case 4:
                printf("Enter an element to remove from set2:\n");
                scanf("%s", input);
                removeElement(&set2, input);
                printf("Set 2 after removing element:\n");
                print(&set2);
                break;

            case 5:
                printf("Elements of set1:\n");
                print(&set1);
                printf("Elements of set2:\n");
                print(&set2);
                break;

            case 6:
                break;

            default:
                printf("Invalid command\n");
                break;
        }
    }

// free memory allocated for elements
    for (i = 0; i < set1.size; i++) {
        free(set1.elements[i]);
    }
    for (i = 0; i < set2.size; i++) {
        free(set2.elements[i]);
    }

    return 0;
}