#include <stdio.h>

int main() {
    int i,j ;
    int N,M;
    int x;
    
    do {
        printf("Введите количество строк: ");
        scanf("%d",&N);
        printf("Введите количество столбцов: ");
        scanf("%d",&M);
        double mas[N][M];
        double sum_main = 0.0;
        double sum_pob = 0.0;
    
        
        printf("Введите элементы массива:\n");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                scanf("%lf", &mas[i][j]);
            }
        }
    
        for (int i = 0; i < N; i++) {
            sum_main += mas[i] [i];
        }
        
        for (int i = 0; i < N; i++) {
            sum_pob += mas[i] [2-i];
        }
        
    
        printf("Сумма элементов главной диагонали:%lf\n",sum_main);
        printf("Сумма элементов побочной диагонали:%lf\n",sum_pob);

        printf("Нажмите 1 чтообы продолжить\n");
        scanf("%d", &x);
    } while (x==1);
    return 0;
}
