#include <stdio.h>

int main() {
    double mas[3][3];
    
    printf("Введите элементы массива 3x3:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%lf", &mas[i][j]);
        }
    }

    printf("Введенные элементы массива 3x3:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%f ", mas[i][j]);
        }
        printf("\n");
    }

    
    return 0;
}
