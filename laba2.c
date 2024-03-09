#include <stdio.h>


int main() {
    int i,j ;
    
    printf("Введите количество строк: ");
    scanf("%d",&i);
    printf("Введите количество столбцов: ");
    scanf("%d",&j);
    double mas[i][j];
    double sum_main = 0.0;
    double sum_pob = 0.0;

    
    printf("Введите элементы массива:\n");
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
