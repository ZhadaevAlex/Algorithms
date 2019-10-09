#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define T char
//#define SIZE 100

//Реализация структуры через массив
//T Stack[SIZE];
//int ind = -1;

//void push(char value) {
//    if (ind < SIZE)
//        Stack[++ind] = value;
//    else
//        printf("Stack overflow");
//}

//T pop() {
//    if (ind != -1)
//        return Stack[ind--];
//    else {
//        printf("Stack is empty");
//        return -1;
//    }
//}

//Реализация структуры через односвязный список
typedef int boolean;
#define true 1
#define false 0;

typedef struct Node {
    T data;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    int size;
} Stack;

boolean push(Stack *st, T value) {
    Node *temp = (Node*) malloc(sizeof(Node));
    if (temp == NULL)
        return false;

    temp->data = value;
    temp->next = st->head;
    st->head = temp;
    st->size++;
    return true;
}

T pop(Stack *st) {
    if (st->size == 0)
        return -1;

    Node *temp = st->head;
    T result = temp->data;
    st->head = st->head->next;
    st->size--;
    free(temp);
    return result;
}

//Алгоритм проверки скобок
//Приоритет скобок такой: ([{}])
//Cоздаем три стека для каждого вида скобок
//Посимвольно читаем входную строку и:
//Если скобка открывающаяся, то в соостветсвующий стек помещаем значение
//Если скобка закрывающаяся, то извлекаем из стека значение
//Остальные правила описаны в коде
boolean checkBrace(char* str) {
    Stack sRound;
    Stack sSquare;
    Stack sFigure;
    sRound.size = 0;
    sRound.head = NULL;
    sSquare.size = 0;
    sSquare.head= NULL;
    sFigure.size = 0;
    sFigure.head = NULL;

    int len = strlen(str);

    for (int i = 0; i < len; i++)
    {
        if (str[i] == '(') {
            if (sSquare.size == 0 && sFigure.size == 0)
                push(&sRound, 1);
            else
                return false; //Перед открытием круглой не закрыты квадратная и фигурная
        }
        else if (str[i] == ')') {
            if (sRound.size != 0 && sSquare.size == 0 && sFigure.size == 0)
                pop(&sRound);
            else
                return false; //Перед закрытием круглой не открыта круглая и не закрыты квадратная и фигурная
        }
        else if (str[i] == '[') {
            if (sFigure.size == 0)
                push(&sSquare, 1);
            else
                return false; //Перед открытием квадратной не закрыта фигурная
        }
        else if (str[i] == ']') {
            if (sSquare.size != 0 && sFigure.size == 0)
                pop(&sSquare);
            else
                return false; //Перед закрытием квадратной не открыта квадратная и не закрыта фигурная
        }
        else if (str[i] == '{')
            push(&sFigure, 1);
        else if (str[i] == '}') {
            if (sFigure.size != 0)
                pop(&sFigure);
            else
                return false; //Перед закрытием фигурной не закрыта фигурная
        }
    }

    if ((sRound.size != 0) || (sSquare.size != 0) || (sFigure.size != 0))
        return false; //Не закрыта хотя бы одна из скобок

    return true;
}

int main(void)
{
    char str[100];
    printf("Введите математическое выражение:\n");
    scanf("%s", str);

    printf("Последовательность \%s\n", checkBrace(str) ? "правильная" : "неправильная");

    return 0;
}

