#include <stdio.h>
#include <math.h>

//Вычисление корней квадратного уравнения
int CalculateSquareEquality(int a, int b, int c, double* x1, double* x2)
{
    double d = b * b - 4 * a * c;

    if (a == 0)
    {
        *x1 = -c / b;
        *x2 = *x1;

        printf("Уравнение имеет один корень\n");
        return 0;
    }
    else if (d == 0)
    {
        *x1 = (-b/(2 * a));
        *x2 = *x1;

        printf("Уравнение имеет один корень. D == 0\n");
        return 0;
    }
    else if (d < 0)
    {
        printf("Уравнение не имеет кореней. D < 0\n");
        return -1;
    }

    *x1 = (-b + sqrt(d)) / (2 * a);
    *x2 = (-b - sqrt(d)) / (2 * a);

    printf("Уравнение имеет два корня. D > 0\n");

    return 1;
}

//Определение наличия четных цифр в составе числа
//Возвращает 1, если четная цифра есть
//Возвращает 2, если четной цифры нет
int IsOdd(int n)
{
    while (n > 0)
    {
        if (n % 10 % 2 == 1)
            return 1;

        n = n / 10;
    }

    return 0;
}

float mean()
{
    float sum = 0;
    int counter = -1;
    int in = 0;

    while (in != -1)
    {
        sum = sum + in;
        counter++;
        printf("Введите целое положительное число: ");
        scanf("%d", &in);
    }

    if (counter != 0)
        return sum / counter;
    else
        return -1;
}

void Task1()
{
    double m = 0;
    double h = 0;
    printf("Введите вес в килограммах: ");
    scanf("%lf", &m);
    printf("Введите рост в метрах: ");
    scanf("%lf", &h);
    double i = m / (h * h);
    printf("ИМТ: %lf\n", i);
}

void Task3b()
{
    int a = 0;
    int b = 0;
    printf("Введите значение целочисленной переменной a: ");
    scanf("%d", &a);
    printf("Введите значение целочисленной переменной b: ");
    scanf("%d", &b);
    if (a != b)
    {
        a = a ^ b;
        b = b ^ a;
        a = a ^ b;
    }
    printf("Новое значение переменной a: %d\n", a);
    printf("Новое значение переменной b: %d\n", b);
}

void Task4()
{
    int a = 0;
    int b = 0;
    int c = 0;

    printf("Введите коэффициент a: ");
    scanf("%d", &a);
    printf("Введите коэффициент b: ");
    scanf("%d", &b);
    printf("Введите коэффициент c: ");
    scanf("%d", &c);

    double x1 = 0;
    double x2 = 0;

    int calc = CalculateSquareEquality(a, b, c, &x1, &x2);

    if (calc == 0 || calc == 1)
    {
        printf("Корень x1 = %lf\n", x1);
        printf("Корень x2 = %lf\n", x2);
    }
}

void Task6()
{
    printf("Введите возраст человека (от 1 до 150 лет): ");
    int age = 0;
    scanf("%d", &age);
    char* year = "";

    if (age < 1 || age > 150)
    {
        printf("Вы ввели число за пределами требуемого диапазона");
        return;
    }

    if (age >= 11 && age <= 19 || age >= 111 && age <= 119 ||age % 10 >= 5 && age % 10 <= 9 || age % 10 == 0)
    {
        year = "лет";
    }
    else if (age % 10 == 1)
    {
        year = "год";
    }
    else
    {
        year = "годa";
    }

    printf("Возраст человека: %d %s\n", age, year);
}

void Task7()
{
    int x1 = 0;
    int y1 = 0;
    int x2 = 0;
    int y2 = 0;

    printf("Введите x1: ");
    scanf("%d", &x1);
    printf("Введите y1: ");
    scanf("%d", &y1);
    printf("Введите x2: ");
    scanf("%d", &x2);
    printf("Введите y2: ");
    scanf("%d", &y2);

    int sumRemaind1 = (x1 + y1) % 2;
    int sumRemaind2 = (x2 + y2) % 2;

    if (sumRemaind1 - sumRemaind2 == 0)
    {
        printf("Поля относятся к одному цвету\n");
    }
    else
    {
        printf("Поля не относятся к одному цвету\n");
    }
}

void Task9()
{
    int n = 0; //Делимое
    int k = 0; //Делитель

    printf("Введите положительное целое число n (делимое): ");
    scanf("%d", &n);
    printf("Введите положительное целое число k (делитель): ");
    scanf("%d", &k);

    int quotient = 0; //Частное
    int sum = 0;

    while(sum < n)
    {
        quotient++;
        sum += k;
    }

    if (sum != n)
    {
        sum = sum - k;
        quotient--;
    }

    int remainder = n - sum;

    printf("Частное: %d\n", quotient);
    printf("Остаток: %d\n", remainder);
}

void Task10()
{
    int n = 0;

    printf("Введите положительное целое число n: ");
    scanf("%d", &n);

    int odd = IsOdd(n);

    if (odd == 1)
        printf("Нечетные цифры есть\n");
    else
        printf("Нечетных цифр нет\n");
}

void Task14()
{
    for (long number = 0; number <= 1000000; number++)
    {
        int p = 1;

        while (p <= number)
        {
            p = p * 10;
        }

        if ((number * number % p == number))
        {
            printf("%ld\n", number);
        }
    }
}

void Task15()
{
    float m = mean();
    printf("Среднее значение: %f\n", m);
}

int main()
{
    //1. Ввести вес и рост человека.
    //Рассчитать и вывести индекс массы тела по формуле I=m/(h*h); где m-масса тела в килограммах, h - рост в метрах.
    printf("Задание 1\n");
    Task1();
    printf("\n");

    //3. Написать программу обмена значениями двух целочисленных переменных:
    //b. *без использования третьей переменной.
    printf("Задание 3b\n");
    Task3b();
    printf("\n");

    //4. Написать программу нахождения корней заданного квадратного уравнения.
    printf("Задание 4\n");
    Task4();
    printf("\n");

    //6. Ввести возраст человека (от 1 до 150 лет) и вывести его вместе с последующим словом «год», «года» или «лет».
    printf("Задание 6\n");
    Task6();
    printf("\n");

    //7. Имеются числовые координаты двух полей шахматной доски (x1,y1,x2,y2).
    //Требуется определить, относятся ли к поля к одному цвету или нет.
    printf("Задание 7\n");
    Task7();
    printf("\n");

    //9. Даны целые положительные числа N и K.
    //Используя только операции сложения и вычитания, найти частное от деления нацело N на K, а также остаток от этого деления.
    printf("Задание 9\n");
    Task9();
    printf("\n");

    //10. Дано целое число N (> 0).
    //С помощью операций деления нацело и взятия остатка от деления определить,
    //имеются ли в записи числа N нечетные цифры. Если имеются, то вывести True, если нет — вывести False.
    printf("Задание 10\n");
    Task10();
    printf("\n");

    //14. * Автоморфные числа. Натуральное число называется автоморфным,
    //если оно равно последним цифрам своего квадрата. Например, 25 \ :sup: 2 = 625.
    //Напишите программу, которая выводит на экран все автоморфные числа, в пределах 1_000_000
    printf("Задание 14\n");
    Task14();
    printf("\n");

    //15. Дублирую задание по улучшению алгоритма с урока))
    printf("Задание 15\n");
    Task15();
    printf("\n");

    return 0;
}
