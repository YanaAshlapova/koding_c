#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Функция для генерации случайной матрицы
void generateRandomMatrix(int **matrix, int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 10; // Генерация чисел от 0 до 9
        }
    }
}

// Функция для перемножения матриц
void multiplyMatrices(int **matrix1, int **matrix2, int **result, int rows1, int cols1, int rows2, int cols2) {
    for(int i = 0; i < rows1; i++) {
        for(int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for(int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

// Функция для сложения матриц
void addMatrices(int **matrix1, int **matrix2, int **result, int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

int main() {
    int rows, cols;
    printf("Введите количество строк и столбцов для матриц: ");
    scanf("%d %d", &rows, &cols);

    // Выделение памяти и генерация двух случайных матриц
    int **matrix1 = (int **)malloc(rows * sizeof(int *));
    int **matrix2 = (int **)malloc(rows * sizeof(int *));
    for(int i = 0; i < rows; i++) {
        matrix1[i] = (int *)malloc(cols * sizeof(int));
        matrix2[i] = (int *)malloc(cols * sizeof(int));
    }

    srand(time(0)); // Инициализация генератора случайных чисел
    generateRandomMatrix(matrix1, rows, cols);
    generateRandomMatrix(matrix2, rows, cols);

    // Создание и запись матриц в файл input.txt
    FILE *file = fopen("input.txt", "w");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            fprintf(file, "%d ", matrix1[i][j]);
        }
        fprintf(file, "\n");
    }
    fprintf(file, "\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            fprintf(file, "%d ", matrix2[i][j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);

    // Освобождение памяти, чтобы избежать утечек
    for(int i = 0; i < rows; i++) {
        free(matrix1[i]);
        free(matrix2[i]);
    }
    free(matrix1);
    free(matrix2);

    // Чтение матриц из файла и произведение операций над ними
    file = fopen("input.txt", "r");
    
    // Здесь необходимо добавить код для чтения матриц из файла и вызова функций умножения и сложения
    // Чтение матриц из файла
    int **readMatrix(FILE *file, int rows, int cols) {
        int **matrix = (int **)malloc(rows * sizeof(int *));
        for(int i = 0; i < rows; i++) {
            matrix[i] = (int *)malloc(cols * sizeof(int));
            for(int j = 0; j < cols; j++) {
                fscanf(file, "%d", &matrix[i][j]);
            }
        }
        return matrix;
    }
    
    file = fopen("input.txt", "r");
    int **matrix1_read = readMatrix(file, rows, cols);
    fseek(file, 1, SEEK_CUR); // Пропускаем пустую строку
    int **matrix2_read = readMatrix(file, rows, cols);
    fclose(file);
    
    // Выделение памяти для результатов операций
    int **result_multiply = (int **)malloc(rows * sizeof(int *));
    int **result_add = (int **)malloc(rows * sizeof(int *));
    for(int i = 0; i < rows; i++) {
        result_multiply[i] = (int *)malloc(cols * sizeof(int));
        result_add[i] = (int *)malloc(cols * sizeof(int));
    }
    
    // Умножение матриц
    multiplyMatrices(matrix1_read, matrix2_read, result_multiply, rows, cols, rows, cols);
    
    // Сложение матриц
    addMatrices(matrix1_read, matrix2_read, result_add, rows, cols);
    
    // Запись результата умножения в output.txt
    file = fopen("output.txt", "w");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            fprintf(file, "%d ", result_multiply[i][j]);
        }
        fprintf(file, "\n");
    }
    fprintf(file, "\n");
    
    // Запись результата сложения в output.txt
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            fprintf(file, "%d ", result_add[i][j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
    
    // Освобождение памяти для матриц и результатов
    for(int i = 0; i < rows; i++) {
        free(matrix1_read[i]);
        free(matrix2_read[i]);
        free(result_multiply[i]);
        free(result_add[i]);
    }
    free(matrix1_read);
    free(matrix2_read);
    free(result_multiply);
    free(result_add);
    

    
    // Закрытие файла
    fclose(file);

    // Замер времени работы программы
    clock_t start_time = clock();

    // Выполнение операций

    clock_t end_time = clock();
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Время выполнения программы: %f секунд\n", time_taken);

    return 0;
}
