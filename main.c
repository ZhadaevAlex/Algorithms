#include <stdio.h>

void DecToBin(int n) {
    int bit = n % 2;
    n /= 2;
    if (n > 0)
        DecToBin(n);
    printf("%d", bit);
}

void Task1() {
    int n = 0;
    printf("Введите целое положительное число: ");
    scanf("%d", &n);
    printf("Двоичное представление введенного числа: ");
    DecToBin(n);
}

int main() {
    //1. Реализовать функцию перевода из 10 системы в двоичную используя рекурсию.
    printf("Задача 1\n");
    Task1();
    printf("\n");

    return 0;
}
