#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion_sort(int arr[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void shell_sort(int arr[], int n) {
    int i, j, gap, temp;
    for (gap = n / 2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            temp = arr[i];
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}

void generate_data(char* filename, int n) {
    FILE* fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Unable to open file %s\n", filename);
        return;
    }

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        int num = rand() % 1000;
        fprintf(fp, "%d\n", num);
    }

    fclose(fp);
}

void read_data(char* filename, int arr[], int n) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Unable to open file %s\n", filename);
        return;
    }

    for (int i = 0; i < n; i++) {
        fscanf(fp, "%d", &arr[i]);
    }

    fclose(fp);
}

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int sizes[] = {1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 1000000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

    for (int i = 0; i < num_sizes; i++) {
        int n = sizes[i];
        int arr[n];

        // Generate data
        char filename[100];
        sprintf(filename, "data_%d.txt", n);
        generate_data(filename, n);

        // Read data
        read_data(filename, arr, n);

        // Sort using insertion sort
        clock_t start_time = clock();
//        insertion_sort(arr, n);
        clock_t end_time = clock();
        double insertion_sort_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

        // Print sorted array
        printf("Insertion Sort (%d):\n", n);
        print_array(arr, n);

        // Read data again
        read_data(filename, arr, n);

        // Sort using shell sort
        start_time = clock();
        shell_sort(arr, n);
        end_time = clock();
        double shell_sort_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

        // Print sorted array
        printf("Shell Sort (%d):\n", n);
        print_array(arr, n);

        printf("Insertion Sort time (%d): %f seconds\n", n, insertion_sort_time);
        printf("Shell Sort time (%d): %f seconds\n", n, shell_sort_time);
    }

    return 0;
}
