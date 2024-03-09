#include <stdio.h> 
 
int main() { 
    int arr[2][2]; 
    int kv[2][2]; 
     
  
    printf("Введите значения массива:\n"); 
    for (int i = 0; i < 2; i++) { 
        for (int j = 0; j < 2; j++) { 
            scanf("%d", &arr[i][j]); 
        } 
    } 
     
     
    for (int i = 0; i < 2; i++) { 
        for (int j = 0; j < 2; j++) { 
            kv[i][j] = arr[i][0] * arr[0][j] + arr[i][1] * arr[1][j]; 
        } 
    } 
     
     
    printf("Квадрат матрицы:\n"); 
    for (int i = 0; i < 2; i++) { 
        for (int j = 0; j < 2; j++) { 
            printf("%d ", kv[i][j]); 
        } 
        printf("\n"); 
    } 
     
    return 0; 
}
