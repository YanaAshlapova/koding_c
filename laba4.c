глол


#include <stdio.h>
#include "tr.h"

int main(){
    int a,b,c,p;
    double s;
    printf("Введите a,b,c ");
    scanf("%d %d %d", &a, &b, &c);
    
    if (valid(a,b,c)){
        p = perim(a,b,c);
        printf("P=%d\n", p);
        s = area(a,b,c);
        printf("S=%lf", s);
        return 0;
    } else {
        printf("не существует");
        
    }
    
    return 0;
}


tr.h
int perim(int side1, int side2, int side3);
double area(int side1, int side2, int side3);


tr.c
#include <math.h>

int valid(int side1, int side2, int side3){
    if ((side1<side2+side3) & (side2<side1+side3) & (side3<side1+side2)){
        return 1;
    } else {
        return 0;
    }
}
    

int perim(int side1, int side2, int side3){
    int per;
    per=side1+side2+side3;
    return per;
}

double area(int side1, int side2, int side3){
    double ar;
    int per_2;
    per_2= (side1+side2+side3)/2;
    ar=sqrt(per_2*(per_2-side1)*(per_2-side2)*(per_2-side3));
    return ar;
}
