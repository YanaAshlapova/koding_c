matrix_operations.c
#include <stdio.h>
#include <stdlib.h>

double** matrix_operation(double** matrix1, double** matrix2, int n, char operation) {
    double** result_matrix = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        result_matrix[i] = (double*)malloc(n * sizeof(double));
    }

    if (operation == '+') {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                result_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }
    } else if (operation == '-') {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                result_matrix[i][j] = matrix1[i][j] - matrix2[i][j];
            }
        }
    } else if (operation == '*') {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                result_matrix[i][j] = 0;
                for (int k = 0; k < n; k++) {
                    result_matrix[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }
    } else {
        printf("Недопустимая операция\n");
        exit(1);
    }

    return result_matrix;
}

main.c

#include <stdio.h>
#include <stdlib.h>
#include "matrix_operations.c"

int main() {
    int n;
    printf("Введите размерность матрицы n: ");
    scanf("%d", &n);

    double** matrix1 = (double**)malloc(n * sizeof(double*));
    double** matrix2 = (double**)malloc(n * sizeof(double*));

    for (int i = 0; i < n; i++) {
        matrix1[i] = (double*)malloc(n * sizeof(double));
        matrix2[i] = (double*)malloc(n * sizeof(double));
    }

    printf("Введите элементы первой матрицы:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &matrix1[i][j]);
        }
    }

    printf("Введите элементы второй матрицы:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &matrix2[i][j]);
        }
    }

    char operation;
    printf("Введите операцию (+, -, *): ");
    scanf(" %c", &operation);

    double** result = matrix_operation(matrix1, matrix2, n, operation);

    printf("Результат операции:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%lf ", result[i][j]);
        }
        printf("\n");
    }

    // Освобождаем выделенную память
    for (int i = 0; i < n; i++) {
        free(matrix1[i]);
        free(matrix2[i]);
        free(result[i]);
    }
    free(matrix1);
    free(matrix2);
    free(result);

    return 0;
}
