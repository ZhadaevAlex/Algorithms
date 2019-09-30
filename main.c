#include <stdio.h>

void DecToBin(int n) {
    int bit = n % 2;
    n /= 2;
    if (n > 0)
        DecToBin(n);
    printf("%d", bit);
}

int Pow(int a, int b) {
    int res = 1;
    for(int i = 0; i < b; i++) {
        res *= a;
    }
    return res;
}

int PowR(int a, int b) {
    int res = 1;    
    if (b != 0) {
        b--;
        res = PowR(a, b);
        res *= a;
    }

    return res;
}

int PowR2(int a, int b) {
    int res = 1;
    if (b != 0) {
        b--;
        res = PowR(a, b);
        res *= a;
    }

    return res;
}

void Task1() {
    int n = 0;
    printf("Введите целое положительное число: ");
    scanf("%d", &n);
    printf("Двоичное представление введенного числа: ");
    DecToBin(n);
}

void Task2() {
    int a = 0;
    int b = 0;
    printf("Введите целое положительное число: ");
    scanf("%d", &a);
    printf("Введите показатель степени: ");
    scanf("%d", &b);

    printf("Без рекурсии: \n");
    int res = Pow(a,b);
    printf("%d в степени %d равно %d\n", a, b, res);

    printf("Рекурсивно: \n");
    res = PowR(a,b);
    printf("%d в степени %d равно %d\n", a, b, res);

    printf("Рекурсивно, используя четность степени : \n");
    res = PowR2(a,b);
    printf("%d в степени %d равно %d\n\n", a, b, res);
}

int main() {
    //1. Реализовать функцию перевода из 10 системы в двоичную используя рекурсию.
    printf("Задача 1\n");
    Task1();
    printf("\n\n");
    
    //2. Реализовать функцию возведения числа a в степень b:
    //a. без рекурсии;
    //b. рекурсивно;
    //c. *рекурсивно, используя свойство чётности степени.
    printf("Задача 2\n");
    Task2();
    printf("\n\n");

    return 0;
}
