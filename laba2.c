#include <stdio.h>
int main() {
    double mas[3][3];
    double sum_main = 0.0;
    double sum_pob = 0.0;

    printf("Введите элементы массива 3x3:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%lf", &mas[i][j]);
        }
    }

    for (int i = 0; i < 3; i++) {
        sum_main += mas[i] [i];
    }
    
    for (int i = 0; i < 3; i++) {
        sum_pob += mas[i] [2-i];
    }
    
    printf("Сумма элементов главной диагонали:%lf\n",sum_main);
    printf("Сумма элементов побочной диагонали:%lf\n",sum_pob);

    
    return 0;
}


