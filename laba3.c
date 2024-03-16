#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char input_string[81]; // Массив для хранения введенной строки (с запасом на 80 символов + символ конца строки)
    printf("Введите строку символов (до 80 символов): ");
    fgets(input_string, sizeof(input_string), stdin); // Считываем строку с консоли

    // Заменяем маленькие 'a' и 'b' на заглавные 'A' и 'B'
    for (int i = 0; i < strlen(input_string); i++) {
        if (input_string[i] == 'a' || input_string[i] == 'b') {
            input_string[i] = toupper(input_string[i]);
        }
    }

    // Вывод полученной строки на консоль
    printf("Полученная строка после замены: %s", input_string);

    return 0;
}
