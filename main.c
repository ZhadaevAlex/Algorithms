#include <stdio.h>
#define SIZE 7

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

int routesBarrier(int x, int y, int desk[SIZE][SIZE]) {
    if (desk[x][y] == 0)
        return 0;
    else if (x == 0 || y == 0)
        return 1;
    else if (x == 0 && y != 0 && desk[x][y] == 0)
        return routesBarrier(x, y - 1, desk);
    else if (y == 0 && x != 0 && desk[x][y] == 0)
        return routesBarrier(x - 1, y, desk);
    else return routesBarrier(x - 1, y, desk) + routesBarrier(x, y - 1, desk);
}

int main(void)
{
    printf("Кол-во маршрутов без препятствий\n");
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++)
            printf("%7d", routes(i, j));
        printf("\n");
    }

    printf("\n");

    int desk[SIZE][SIZE] = {0};

    printf("Расположение препятствий\n");
    printf("0 - препятствие\n");
    printf("1 - нет препятствия\n\n");

    //Формирование массива без припятствий
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            desk[i][j] = 1;

    //Формирование препятствий
    desk[0][3] = 0;
    desk[0][4] = 0;
    desk[2][2] = 0;
    desk[4][1] = 0;
    desk[4][0] = 0;
    desk[6][5] = 0;

    print2Array(SIZE, SIZE, desk);


    printf("\n");

    printf("Кол-во маршрутов с препятствиями\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++)
            printf("%5d", routesBarrier(i, j, desk));
        printf("\n");
    }

    return 0;
}
