#include <stdio.h>

void DecToBin(int n) {
    int bit = n % 2;
    n /= 2;
    if (n > 0)
        DecToBin(n);
    printf("%d", bit);
}

//Возведение в степень без рекурсии
int Pow(int a, int b) {
    int res = 1;
    for(int i = 0; i < b; i++) {
        res *= a;
    }
    return res;
}

//Возведение в степень рекурсивно
int PowR(int a, int b) {
    int res = 1;    
    if (b != 0) {
        b--;
        res = PowR(a, b);
        res *= a;
    }

    return res;
}

//Возведение в степень, используя четность
int Pow2(int a, int b) {
    int res = 1;

    while(b) {
        if (b % 2 == 0) {
            a *= a;
            b /= 2;
        }
        else {
            res *= a;
            b--;
        }
    }

    return res;
}

//Возведение в степень, используя четность рекурсивно
int PowR2(int a, int b) {
    int res = 1;

    if (b != 0)
    {
        if (b % 2 == 0) {
            b /= 2;
            res = PowR2(a, b);
            res *= res;

        }
        else {

            b--;
            res = PowR2(a, b);
            res *= a;
        }
    }

    return res;
}

//Подсчет количества программ с использованием циклов
int CountProgrammCycle(int begin, int end) {
    int count = 0;

    for (int i = begin; i <= end/2; i++) {
        int p = 0;
        int tmp = 0;
        do
        {
            tmp = i * Pow(2, p);
            p++;
            count++;
        }
        while(tmp <= end);
        count--;
    }

    return count;
}

//Подсчет количества программ с использованием рекурсии
int CountProgrammR(int begin, int end, int p) {
    int res = 1;

    if (begin <= end/2)
    {
        p++;

        int tmp = begin * Pow(2, p - 1);

        if (tmp > end)
        {
            begin++;
            p = 0;
            res--;
        }

        res = res + CountProgrammR(begin, end, p);
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
    printf("%d в степени %d равно %d\n", a, b, Pow(a,b));

    printf("Рекурсивно: \n");
    printf("%d в степени %d равно %d\n", a, b, PowR(a,b));

    printf("Рекурсивно, используя четность степени : \n");
    printf("%d в степени %d равно %d", a, b, PowR2(a,b));
}

void Task3() {
    int begin = 3;
    int end = 20;

    printf("С использованием массива: \n");
    printf("Количество программ: %d\n", CountProgrammCycle(begin, end));

    printf("С использованием рекурсии: \n");
    int p = 0;
    int count = CountProgrammR(begin, end, p) - 1;
    printf("Количество программ: %d", count);

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

    //3. Исполнитель Калькулятор преобразует целое число, записанное на экране
    //У исполнителя две команды, каждой команде присвоен номер:
    //1.Прибавь 1
    //2.Умножь на 2
    //Первая команда увеличивает число на экране на 1, вторая увеличивает это число в 2 раза.
    //Сколько существует программ, которые число 3 преобразуют в число 20?
    //а) с использованием массива;
    //б) с использованием рекурсии.
    printf("Задача 3\n");
    Task3();
    printf("\n\n");

    return 0;
}
