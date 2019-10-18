#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//           start
//      0------1-------------2------3
//             |                    |
//             |                    |
//             |                    |
//             4------5------6      7
//                    |             |
//                    |             |
//                    |             |
//                    8             9
//                    |
//                    |
//                    |
//      10-----11-----12-----13
//             |             |
//             |             |
//             |             |stop
//             14-----15     16-----17
//             |      |      |      |
//             |      |      |      |
//             |      |      |      |
//             18     19     20     21
//
//Матрица смежности
//    0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20 21
//  0 0  1  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
//  1 1  0  1  0  1  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
//  2 0  1  0  1  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
//  3 0  0  1  0  0  0  0  1  0  0  0  0  0  0  0  0  0  0  0  0  0  0
//  4 0  1  0  0  0  1  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
//  5 0  0  0  0  1  0  1  0  1  0  0  0  0  0  0  0  0  0  0  0  0  0
//  6 0  0  0  0  0  1  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
//  7 0  0  0  1  0  0  0  0  0  1  0  0  0  0  0  0  0  0  0  0  0  0
//  8 0  0  0  0  0  1  0  0  0  0  0  0  1  0  0  0  0  0  0  0  0  0
//  9 0  0  0  0  0  0  0  1  0  0  0  0  0  0  0  0  0  0  0  0  0  0
// 10 0  0  0  0  0  0  0  0  0  0  0  1  0  0  0  0  0  0  0  0  0  0
// 11 0  0  0  0  0  0  0  0  0  0  1  0  1  0  1  0  0  0  0  0  0  0
// 12 0  0  0  0  0  0  0  0  1  0  0  1  0  1  0  0  0  0  0  0  0  0
// 13 0  0  0  0  0  0  0  0  0  0  0  0  1  0  0  0  1  0  0  0  0  0
// 14 0  0  0  0  0  0  0  0  0  0  0  1  0  0  0  1  0  0  1  0  0  0
// 15 0  0  0  0  0  0  0  0  0  0  0  0  0  0  1  0  0  0  0  1  0  0
// 16 0  0  0  0  0  0  0  0  0  0  0  0  0  1  0  0  0  1  0  0  1  0
// 17 0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  1  0  0  0  0  1
// 18 0  0  0  0  0  0  0  0  0  0  0  0  0  0  1  0  0  0  0  0  0  0
// 19 0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  1  0  0  0  0  0  0
// 20 0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  1  0  0  0  0  0
// 21 0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  1  0  0  0  0

#define boolean int
#define true 1
#define false 0

typedef struct List List;

int matrix[100][100];

//Получение матрицы смежности из файла
int getMatrix(int matrix[100][100], int *size) {
    FILE* file = fopen("matrix", "r");
    if (file == NULL) {
        printf("Can't open file");
        return 1;
    }

    char str[100];
    int i = 0;
    while(1) {
        fgets(str, 100, file);
        if (str[0] == '\n')
            break;

        int j = 0;
        char p = 0;
        while(*(str + p) != '\n' && *(str + p) != '\0') {
            char currentStr = *(str + p);
            int current = atoi(&currentStr);
            matrix[i][j] = current;
            //printf("%d", current);
            p++;
            j++;
         }

         printf("\n");
         i++;
    }

    *size = i;

    fclose(file);

    return 0;
}

//Печать матрицы смежности
void printMatrix(int matrix[][100], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d", matrix[i][j]);
        }
        printf("\n");
    }
}

//Узел графа
typedef struct GraphNode {
    int data;
    int used;
    List *children;
} GraphNode;

//Узел списка
typedef struct Node {
    GraphNode data;
    int index;
    struct Node *next;
    struct Node *prev;
} Node;

//Двусвязный список. Узлы графа
typedef struct List{
    Node *head;
    Node *tail;
    int size;
} List;

//Добавление элемента в двусвязный список
boolean push(List *lst, GraphNode value) {
    Node *tmp = (Node*) malloc(sizeof(Node));
    if (tmp == NULL)
        return false;

    tmp->data = value;
    tmp->index = lst->size;
    tmp->next = lst->head;
    tmp->prev = NULL;

    if (lst->head != NULL)
        lst->head->prev = tmp;
    else
        lst->tail = tmp;

    lst->head = tmp;

    lst->size++;

    return true;
}

//Извлечение из двусвязного списка (очередь)
GraphNode Dequeue(List *lst) {
    GraphNode result;
    result.data = -1;
    result.used = -1;
    result.children = NULL;

    if (lst->size == 0) {
        printf("Очередь пустая\n");
    }
    else {
        Node *temp = lst->tail;
        result = temp->data;

        lst->tail = lst->tail->prev;

        if (lst->size > 1)
            lst->tail->next = NULL;
        else
            lst->head = NULL;

        free(temp);

        lst->size--;
    }

    return result;
}

//Извлечение из двусвязного списка (стек)
GraphNode pop(List *lst) {
    GraphNode result;
    result.data = -1;
    result.used = -1;
    result.children = NULL;

    if (lst->size == 0) {
        printf("Стек пуст\n");
    }
    else {
        Node *temp = lst->head;
        result = temp->data;

        lst->head = lst->head->next;

        if (lst->size > 1)
            lst->head->prev = NULL;
        else
            lst->tail = NULL;

        free(temp);

        lst->size--;
    }

    return result;
}

//Получение i-го элемента списка
GraphNode getI(List *queue, int index) {
    Node *current = queue->tail;

    while (current->index != index) {
        current = current->prev;
    }

    return current->data;
}

//Обход в ширину
int widthTravers (List *queue, GraphNode *start, GraphNode *stop) {
    push(queue, *start);
    start->used = 1;

    while(queue->size != 0) {
        GraphNode current = Dequeue(queue);

        if (current.data == stop->data)
            return 1;
        else {
            //Собрать всех чилдренов в очередь
            for (int i = 0; i < current.children->size; i++) {
                GraphNode tmp = getI(current.children, i);
                if (tmp.used != 1) {
                    push(queue, tmp);
                    tmp.used = 1;
               }
            }
        }
    }

    return 0;
}

int main(void)
{
    //Получение матрицы из файла
    int size;
    getMatrix(matrix, &size);

    //Печать матрицы
    printMatrix(matrix, size);
    printf("Размер матрицы: %d\n", size);

    //Формируем список всех узлов графа
    List graph;
    graph.head = NULL;
    graph.tail = NULL;
    graph.size = 0;

    for (int i = 0; i < size; ++i) {
        GraphNode gn;
        gn.data = i;
        gn.used = 0;
        for (int j = 0; j < size; j++) {
            if (matrix[i][j] != 0) {
                GraphNode child;
                child.data = j;
                child.used = 0;
                push(gn.children, child);
            }
        }

        push(&graph, gn);
    }

    //Обход в ширину
    List queue;
    GraphNode start;
    start.data = 2;
    GraphNode stop;
    start.data = 16;
    int result = widthTravers(&queue, &start, &stop);
    printf("Результат обхода графа в ширину: %d", result);

    return 0;
}
