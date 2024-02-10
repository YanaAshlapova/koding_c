#include <stdio.h>
#include <math.h>

int main()
{
    float a,b,c;
    float Discrim, x1, x2;
    
    printf("Введите первый коэфицент ");
    scanf("%f",&a);
    
    printf("Введите второй коэфицент ");
    scanf("%f",&b);
    
    printf("Введите третий коэфицент ");
    scanf("%f",&c);
    
    Discrim=b*b-4*a*c;
    
    if (Discrim>0){
        x1=(-b+ sqrt(Discrim))/(2*a);
        x2=(-b- sqrt(Discrim))/(2*a);
        printf("x1=%f x2=%f", x1, x2);
    } else if (Discrim==0){
        x1=-b/(2*a);
        printf("Один корень x1=%f", x1);
    } else if (Discrim<0){
        printf("Нет корней");
    }
return 0;
    
}
