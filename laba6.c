21
#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 100

typedef struct {
    char name[MAX_LENGTH];
    int year;
} Person;

int main() {
    FILE *inputFile, *outputFile;
    char name[MAX_LENGTH];
    int year;

    // Создаем и записываем данные в файл
    inputFile = fopen("input.txt", "w");
    if (inputFile == NULL) {
        printf("Ошибка открытия файла для записи\n");
        return 1;
    }
    fprintf(inputFile, "Иванов Петр Сергеевич 1975\n");
    fprintf(inputFile, "Сидоров Николай Андреевич 1981\n");
    fprintf(inputFile, "Воробьянинов Ипполит Матвеевич 1978\n");
    fclose(inputFile);

    // Чтение из файла и запись в другой файл
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Ошибка открытия файла для чтения\n");
        return 1;
    }

    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Ошибка открытия файла для записи\n");
        return 1;
    }

    while (fscanf(inputFile, "%s %s %s %d", name, name, name, &year) != EOF) {
        if (year > 1980) {
            fprintf(outputFile, "%s %s %s %d\n", name, name, name, year);
        }
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
