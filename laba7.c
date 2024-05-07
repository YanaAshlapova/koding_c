87654321
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

typedef struct {
    char name[MAX_LENGTH];
    char surname[MAX_LENGTH];
    int birthYear;
} Human;

void bubbleSortByYear(Human* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].birthYear > arr[j + 1].birthYear) {
                Human temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int N;
    printf("Введите количество элементов N: ");
    scanf("%d", &N);

    Human *arr1 = (Human*)malloc(N * sizeof(Human));
    Human *arr2 = (Human*)malloc(N * sizeof(Human));

    FILE *inputFile = fopen("1.txt", "r");
    if (inputFile == NULL) {
        printf("Ошибка открытия файла для чтения\n");
        return 1;
    }

    for (int i = 0; i < N; i++) {
        fscanf(inputFile, "%s %s %d", arr1[i].name, arr1[i].surname, &arr1[i].birthYear);
    }

    fclose(inputFile);

    // Копирование arr1 в arr2
    memcpy(arr2, arr1, N * sizeof(Human));

    // Сортировка arr2 по году рождения
    bubbleSortByYear(arr2, N);

    // Вывод результата
    printf("Исходный массив:\n");
    for (int i = 0; i < N; i++) {
        printf("%s %s %d\n", arr1[i].name, arr1[i].surname, arr1[i].birthYear);
    }
    
    FILE *newFile = fopen("2.txt", "w");
    if (newFile == NULL){
        printf("Ошибка открытия файла для записи\n");
        return 1;
    }

    printf("\nУпорядоченный массив по году рождения:\n");
    for (int i = 0; i < N; i++) {
        printf("%s %s %d\n", arr2[i].name, arr2[i].surname, arr2[i].birthYear);
    }
    
    for (int i = 0; i < N; i++) {
        fprintf(newFile, "%s %s %d\n", arr2[i].name, arr2[i].surname, arr2[i].birthYear);
    }

    free(arr1);
    free(arr2);

    return 0;
}
