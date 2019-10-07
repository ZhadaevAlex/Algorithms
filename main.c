#include <stdio.h>
#define N 8
#define M 8

void print2Array(int n, int m, int arr[n][m]) {
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
}

int routes(int x, int y) {
    if (x == 0 || y == 0) return 1;
    else return routes(x - 1, y) + routes(x, y - 1);
}

int routesBarrier(int x, int y, int n, int m, int desk[n][m]) {
    if (desk[x][y] == 0)
        return 0;
    else if (x == 0 || y == 0)
        return 1;
    else return routesBarrier(x - 1, y, n, m, desk) + routesBarrier(x, y - 1, n, m, desk);
}

int main(void)
{
    //---------- Сделали на уроке ----------
    printf("Кол-во маршрутов без препятствий\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            printf("%5d", routes(i, j));
        printf("\n");
    }

    printf("\n");

    //-------------------------------------------
    //1. *Количество маршрутов с препятствиями.
    //Реализовать чтение массива с препятствием и нахождение количество маршрутов.

    int desk[N][M] = {0};

    printf("Расположение препятствий\n");
    printf("0 - препятствие\n");
    printf("1 - нет препятствие\n\n");

    //Формирование массива без припятствий
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            desk[i][j] = 1;

    //Формирование препятствий
    desk[0][3] = 0;
    desk[0][4] = 0;
    desk[2][2] = 0;
    desk[4][1] = 0;
    desk[4][0] = 0;
    desk[6][5] = 0;

    //Печать массива с припятствиями
    print2Array(N, M, desk);

    printf("\n");

    printf("Кол-во маршрутов с препятствиями\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            printf("%5d", routesBarrier(i, j, N, M, desk));
        printf("\n");
    }

    printf("\n");

    //-------------------------------------------
    //3. ***Требуется обойти конём шахматную доску размером NxM, пройдя через все поля доски по одному разу.

    return 0;
}
