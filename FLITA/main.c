#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // максимальный размер множества

typedef struct {
    int elements[MAX_SIZE]; // элементы множества
    int size; // текущий размер множества
} Set;

void initializeSet(Set *set) {
    set->size = 0;
}

void inputSet(Set *set) {
    int i, n;

    printf("Введите размер множества: ");
    scanf("%d", &n);

    printf("Введите элементы множества: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &set->elements[i]);
    }

    set->size = n;
}

void outputSet(Set set) {
    int i;

    printf("Элементы множества: ");
    for (i = 0; i < set.size; i++) {
        printf("%d ", set.elements[i]);
    }
    printf("\n");
}

void addElement(Set *set, int element) {
    if (set->size == MAX_SIZE) {
        printf("*** Множество уже максимального размера ***\n");
        return;
    }

    set->elements[set->size] = element;
    set->size++;
}

void removeElement(Set *set, int element) {
    int i, j;

    for (i = 0; i < set->size; i++) {
        if (set->elements[i] == element) {
            // сдвигаем элементы на одну позицию влево, чтобы удалить элемент
            for (j = i; j < set->size - 1; j++) {
                set->elements[j] = set->elements[j+1];
            }
            set->size--;
            printf("*** Элемент %d удален из множества ***\n", element);
            return;
        }
    }

    printf("*** Элемент %d не найден в множестве ***\n", element);
}

int main() {
    Set set1, set2;
    int choice, element;

    initializeSet(&set1);
    initializeSet(&set2);

    while (1) {
        printf("1. Задать множества\n");
        printf("2. Вывести множества\n");
        printf("3. Добавить элемент в множество 1\n");
        printf("4. Добавить элемент в множество 2\n");
        printf("5. Удалить элемент из множества 1\n");
        printf("6. Удалить элемент из множества 2\n");
        printf("7. Выйти\n");
        printf("Выберите действие (1-7): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Введите элементы первого множества:\n");
                inputSet(&set1);
                printf("Введите элементы второго множества:\n");
                inputSet(&set2);
                break;
            case 2:
                printf("*** Первое множество ***\n");
                outputSet(set1);
                printf("*** Второе множество ***\n");
                outputSet(set2);
                break;
            case 3:
                printf("Введите элемент, который нужно добавить в множество 1: ");
                scanf("%d", &element);
                addElement(&set1, element);
                break;
            case 4:
                printf("Введите элемент, который нужно добавить в множество 2: ");
                scanf("%d", &element);
                addElement(&set2, element);
                break;
            case 5:
                printf("Введите элемент, который нужно удалить из множества 1: ");
                scanf("%d", &element);
                removeElement(&set1, element);
                break;
            case 6:
                printf("Введите элемент, который нужно удалить из множества 2: ");
                scanf("%d", &element);
                removeElement(&set2, element);
                break;
            case 7:
                exit(0);
            default:
                printf("Неверный выбор\n");
                break;
        }
    }
}