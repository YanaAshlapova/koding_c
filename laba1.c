/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <math.h>

int main()
{
    float a,b,c;
    float Discrim, x1, x2;
    int x;
    
    printf("Введите первый коэфицент ");
    scanf("%f",&a);
    
    printf("Введите второй коэфицент ");
    scanf("%f",&b);
    
    printf("Введите третий коэфицент ");
    scanf("%f",&c);
    

    Discrim=b*b-4*a*c;
    
    do {
        
    
    if (Discrim>0){
        x1=(-b+ sqrt(Discrim))/(2*a);
        x2=(-b- sqrt(Discrim))/(2*a);
        printf("x1=%f x2=%f", x1, x2);
    } else if (Discrim==0){
        x1=-b/(2*a);
        printf("Один корень x1=%f", x1);
    } else if (Discrim<0){
        printf("Нет корней\n");
    }
    
    printf("Нажмите 1 чтообы продолжить\n");
    scanf("%d", &x);
    } while (x==1);
return 0;
    
}
