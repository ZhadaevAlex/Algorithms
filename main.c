#include <stdio.h>
#include <stdlib.h>

void fillArray(int* arr, int len) {
    for (int i = 0; i < len; i++) {
        arr[i] = rand() % 100;
    }
}

void printArray(int* arr, int len) {
    for (int i = 0; i < len; i++) {

        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int *a, int *b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

//Пузырьковый метод (НЕоптимизированный)
int bubbleSort(int* arr, int len) {
    int operations = 0;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len - 1; j++) {
            operations++;

            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);

            }
        }
    }

    return operations;
}

//Пузырьковый метод (оптимизированный)
//Оптимизация произведена в двух местах: количество итераций обоих счетчиков
int bubbleSortOpt(int* arr, int len) {
    int operations = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i; j++) {
            operations++;

            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }

    return operations;
}

int main(void)
{
    //Инициализируем массив
    int size = 9;
    int arr1[9] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    printArray(arr1, size);

    //Сортируем неоптимизированным пузырьковым методом и получаем кол-во операций
    int oper = bubbleSort(arr1, size);
    printArray(arr1, size);
    printf("Количество операций: \%d\n", oper);

    int arr2[9] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    printArray(arr2, size);

    //Сортируем оптимизированным пузырьковым методом
    oper = bubbleSortOpt(arr2, size);
    printArray(arr2, size);
    printf("Количество операций: \%d\n", oper);

    return 0;
}
