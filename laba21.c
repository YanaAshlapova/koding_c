




#include <stdio.h>

int main() {
    int i,j ;
    int N,M;
    int x;
    
    printf("Введите количество строк: ");
    scanf("%d",&N);
    printf("Введите количество столбцов: ");
    scanf("%d",&M);
    double mas[N][M];
    int kv[N][M];

    
    printf("Введите элементы массива:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%lf", &mas[i][j]);
        }
    }

     for (int i = 0; i < N; i++) { 
        for (int j = 0; j < M; j++) { 
            kv[i][j] = 0; 
            for (int k = 0; k < M; k++) 
                kv[i][j] += mas[i][k]*mas[k][j]; 
        } 
    } 
     
     
    printf("Квадрат матрицы:\n"); 
    for (int i = 0; i < N; i++) { 
        for (int j = 0; j < M; j++) { 
            printf("%d ", kv[i][j]); 
        } 
        printf("\n"); 
    } 
     
    return 0; 
}
