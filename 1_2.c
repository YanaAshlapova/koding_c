#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Функция для чтения матрицы из файла
void readMatrix(FILE *file, int matrix[MAX_SIZE][MAX_SIZE], int *rows, int *cols) {
    fscanf(file, "%d %d", rows, cols);
    
    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *cols; j++) {
            fscanf(file, "%d", &matrix[i][j]);
        }
    }
}

// Функция для сложения двух матриц
void addMatrix(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

// Функция для умножения двух матриц
void multiplyMatrix(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows1, int cols1, int cols2) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int main() {
    FILE *inputFile, *outputFile;
    int matrix1[MAX_SIZE][MAX_SIZE], matrix2[MAX_SIZE][MAX_SIZE];
    int resultMatrix[MAX_SIZE][MAX_SIZE];
    int rows1, cols1, rows2, cols2;
    
    // Открываем файл для чтения
    inputFile = fopen("input.bt", "r");
    if (inputFile == NULL) {
        printf("Не удалось открыть файл для чтения.\n");
        return 1;
    }
    
    // Читаем исходные матрицы из файла
    readMatrix(inputFile, matrix1, &rows1, &cols1);
    readMatrix(inputFile, matrix2, &rows2, &cols2);
    
    if (cols1 != rows2) {
        printf("Для умножения матриц количество столбцов первой матрицы должно быть равно количеству строк второй матрицы.\n");
        return 1;
    }
    
    // Вычисляем результат перемножения матриц
    multiplyMatrix(matrix1, matrix2, resultMatrix, rows1, cols1, cols2);
    
    // Открываем файл для записи
    outputFile = fopen("output.bot", "w");
    if (outputFile == NULL) {
        printf("Не удалось открыть файл для записи.\n");
        return 1;
    }
    
    // Записываем результат в файл
    fprintf(outputFile, "Результат умножения матриц:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            fprintf(outputFile, "%d ", resultMatrix[i][j]);
        }
        fprintf(outputFile, "\n");
    }
    
    // Закрываем файлы
    fclose(inputFile);
    fclose(outputFile);
    
    return 0;
}
