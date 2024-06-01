#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

int main() {
    int N;
    printf("Введите количество случайных чисел: ");
    scanf("%d", &N);
    createInputFile(N);
    modifyInputFile();

    // 2б - Здесь ваш код для формирования матрицы и подсчета суммы строк и столбцов

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
