#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_ROWS 100
#define MAX_COLS 100

void createInputFile(int N) {
    FILE *file = fopen("Inputbt.txt", "w");
    if (file == NULL) {
        printf("Ошибка открытия файла\n");
    } else {
        srand(time(NULL));
        for (int i = 0; i < N; i++) {
            fprintf(file, "%d\n", rand() % 100); // записываем случайные числа в файл
        }
        fclose(file);
    }
}

void modifyInputFile() {
    FILE *inputFile = fopen("Inputbt.txt", "r");
    FILE *outputFile = fopen("output.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Ошибка открытия файлов\n");
    } else {
        int num;
        while (fscanf(inputFile, "%d", &num) != EOF) {
            if (num % 6 == 0) {
                fprintf(outputFile, "ПЯТЬ\n");
            } else if (num % 7 == 0) {
                fprintf(outputFile, "СЕМЬ\n");
            } else if (num % 5 == 0 && num % 7 == 0) {
                fprintf(outputFile, "ПЯТЬСЕМЬ\n");
            } else {
                fprintf(outputFile, "%d\n", num);
            }
        }
        fclose(inputFile);
        fclose(outputFile);
    }
}

void formMatrixFromInputFile(int M) {
    FILE *inputFile = fopen("Inputbt.txt", "r");
    int matrix[MAX_ROWS][MAX_COLS] = {0};
    int num, row = 0, col = 0;

    if (inputFile == NULL) {
        printf("Ошибка открытия файла\n");
    } else {
        while (fscanf(inputFile, "%d", &num) != EOF) {
            if (col == M) {
                row++;
                col = 0;
            }
            if (row < MAX_ROWS && col < MAX_COLS) {
                matrix[row][col] = num;
                col++;
            }
        }
        fclose(inputFile);
    }

    // Вывод матрицы на экран
    printf("Сформированная матрица:\n");
    for (int i = 0; i <= row; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    // Посчитать сумму строк и столбцов
    int rowSum[MAX_ROWS] = {0};
    int colSum[MAX_COLS] = {0};

    for (int i = 0; i <= row; i++) {
        for (int j = 0; j < M; j++) {
            rowSum[i] += matrix[i][j];
            colSum[j] += matrix[i][j];
        }
    }

    // Вывести результаты сложения строк и столбцов
    printf("\nСумма строк:\n");
    for (int i = 0; i <= row; i++) {
        printf("%d\t", rowSum[i]);
    }
    
    printf("\nСумма столбцов:\n");
    for (int j = 0; j < M; j++) {
        printf("%d\t", colSum[j]);
    }
}

int main() {
    int N, M;
    printf("Введите количество случайных чисел: ");
    scanf("%d", &N);
    printf("Введите количество столбцов для матрицы: ");
    scanf("%d", &M);
    createInputFile(N);
    modifyInputFile();
    formMatrixFromInputFile(M);


    // 3
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    // Ваша программа или функции выполняющие задачи
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Время выполнения программы: %f секунд\n", cpu_time_used);

    return 0;
}
