#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Функция для генерации случайного числа в заданном диапазоне
int getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    FILE *file;
    int rows, cols;
    
    // Запросить у пользователя размеры матриц
    printf("Введите количество строк для матриц: ");
    scanf("%d", &rows);
    printf("Введите количество столбцов для матриц: ");
    scanf("%d", &cols);
    
    // Выделить память под две матрицы
    int **matrix1 = (int **)malloc(rows * sizeof(int *));
    int **matrix2 = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix1[i] = (int *)malloc(cols * sizeof(int));
        matrix2[i] = (int *)malloc(cols * sizeof(int));
    }
    
    // Заполнить матрицы случайными числами
    srand(time(NULL));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix1[i][j] = getRandomNumber(1, 10);
            matrix2[i][j] = getRandomNumber(1, 10);
        }
    }
    
    // Записать матрицы в файл input.txt
    file = fopen("input.txt", "w");
    fprintf(file, "Matrix 1:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fprintf(file, "%d ", matrix1[i][j]);
        }
        fprintf(file, "\n");
    }
    fprintf(file, "\nMatrix 2:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fprintf(file, "%d ", matrix2[i][j]);
        }
        fprintf(file, "\n");
    }
    
    // Закрыть файл
    fclose(file);
    
    // Освободить память, занятую под матрицы
    for (int i = 0; i < rows; i++) {
        free(matrix1[i]);
        free(matrix2[i]);
    }
    free(matrix1);
    free(matrix2);
    
    printf("Матрицы записаны в файл input.txt и массивы освобождены.\n");
    
    return 0;
}
