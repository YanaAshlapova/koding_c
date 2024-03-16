#include <stdio.h>
#include <math.h>

// Функция для вычисления периметра треугольника
float calculatePerimeter(float side1, float side2, float side3) {
    return side1 + side2 + side3;
}

// Функция для вычисления площади треугольника
float calculateArea(float side1, float side2, float side3) {
    float s = (side1 + side2 + side3) / 2;
    return sqrt(s * (s - side1) * (s - side2) * (s - side3));
}

int main() {
    float side1, side2, side3;

    printf("Введите длины трех сторон треугольника: ");
    scanf("%f %f %f", &side1, &side2, &side3);

    // Проверка неравенства треугольника
    if (side1 + side2 > side3 && side1 + side3 > side2 && side2 + side3 > side1) {
        float perimeter = calculatePerimeter(side1, side2, side3);
        float area = calculateArea(side1, side2, side3);

        printf("Периметр треугольника: %.2f\n", perimeter);
        printf("Площадь треугольника: %.2f\n", area);
    } else {
        printf("Длины сторон не удовлетворяют условиям треугольника.\n");
    }

    return 0;
}
